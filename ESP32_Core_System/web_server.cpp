#include "web_server.h"
#include <WiFi.h>
#include <WebServer.h>
#include <mbedtls/base64.h>

#include "config.h"
#include "html_views.h"
#include "led_matrix.h"

// Instantiate the server using the port from config.h
WebServer server(SERVER_PORT);
TaskHandle_t WebServerTask;

// --- Route Handlers ---

void handleRoot() {
  String html = String(dashboard_html);
  
  // Get milliseconds since ESP32 booted, convert to seconds
  unsigned long uptimeSeconds = millis() / 1000; 
  
  // Inject the actual hardware uptime into the JavaScript
  html.replace("%UPTIME%", String(uptimeSeconds));
  
  server.send(200, "text/html", html);
}

void handleMatrix() {
  server.send(200, "text/html", matrix_operator_html);
}

void handleDraw() {
  if (server.method() != HTTP_POST) {
    return server.send(405, "text/plain", "Method Not Allowed");
  }

  String b64Payload = server.arg("plain"); 
  unsigned char tempBuffer[192];
  size_t outputLength;
  
  // Decode the incoming Base64 frame
  if (mbedtls_base64_decode(tempBuffer, sizeof(tempBuffer), &outputLength, (const unsigned char*)b64Payload.c_str(), b64Payload.length()) == 0 && outputLength == 192) {
    
    // Hand the data off to the LED Matrix module
    if (updateSingleFrame(tempBuffer)) {
      server.send(200, "text/plain", "Frame Updated");
    } else {
      server.send(500, "text/plain", "Hardware busy");
    }
  } else {
    server.send(400, "text/plain", "Decode Failed");
  }
}

void handleAnim() {
  if (server.method() != HTTP_POST) {
    return server.send(405, "text/plain", "Method Not Allowed");
  }

  String payload = server.arg("plain"); 
  
  if (payload.startsWith("ANIM:")) {
    int firstColon = payload.indexOf(':');
    int secondColon = payload.indexOf(':', firstColon + 1);
    
    if (firstColon != -1 && secondColon != -1) {
      int parsedDelay = payload.substring(firstColon + 1, secondColon).toInt();
      String framesPayload = payload.substring(secondColon + 1);
      
      int frameIdx = 0;
      int startIdx = 0;
      bool decodeSuccess = true;
      uint8_t tempFrames[MAX_FRAMES][192]; 
      
      // Parse out the comma-separated Base64 strings
      while (startIdx < framesPayload.length() && frameIdx < MAX_FRAMES) {
        int commaIdx = framesPayload.indexOf(',', startIdx);
        String b64Frame = (commaIdx == -1) ? framesPayload.substring(startIdx) : framesPayload.substring(startIdx, commaIdx);
        startIdx = (commaIdx == -1) ? framesPayload.length() : commaIdx + 1;
        
        size_t outputLength;
        if (mbedtls_base64_decode(tempFrames[frameIdx], 192, &outputLength, (const unsigned char*)b64Frame.c_str(), b64Frame.length()) != 0 || outputLength != 192) {
          decodeSuccess = false; break;
        }
        frameIdx++;
      }
      
      if (decodeSuccess && frameIdx > 0) {
         // Hand the multi-frame array off to the LED Matrix module
         if (loadAnimation(parsedDelay, frameIdx, tempFrames)) {
           server.send(200, "text/plain", "Animation Loaded");
         } else {
           server.send(500, "text/plain", "Hardware busy");
         }
         return;
      }
    }
  }
  server.send(400, "text/plain", "Invalid Animation Payload");
}

// --- CORE 0: Network Task ---
void WebServerTaskCode(void * parameter) {
  for(;;) {
    server.handleClient();
    vTaskDelay(10 / portTICK_PERIOD_MS); // Yield to prevent watchdog crash
  }
}

// --- Public Initialization ---
void initWebServer() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) { 
    delay(500); 
    Serial.print("."); 
  }
  Serial.println("\nIP: " + WiFi.localIP().toString());

  // Attach endpoints
  server.on("/", handleRoot);
  server.on("/matrix", handleMatrix);
  server.on("/draw", handleDraw);
  server.on("/anim", handleAnim);
  server.begin();

  // Explicitly spawn this task and pin it to Core 0
  xTaskCreatePinnedToCore(
    WebServerTaskCode, // Function to implement the task
    "WebTask",         // Name of the task
    10000,             // Stack size in words
    NULL,              // Task input parameter
    1,                 // Priority of the task
    &WebServerTask,    // Task handle
    0                  // Core where the task should run (Core 0)
  );
}