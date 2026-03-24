#include <Arduino.h>
#include "led_matrix.h"
#include "web_server.h"

void setup() {
  // Initialize Serial Communication
  Serial.begin(115200);
  // Give the Serial monitor a tiny moment to catch up after reset
  delay(500); 
  Serial.println("--- ESP32-S3 Core System Booting ---");

  // Boot Core 1 (Hardware / LED Matrix Task)
  Serial.println("Initializing Hardware Engine...");
  initMatrix();

  // Boot Core 0 (Network / Web Server Task)
  Serial.println("Initializing Network Engine...");
  initWebServer();
  
  Serial.println("Boot Sequence Complete. FreeRTOS Scheduler Active.");
}

void loop() {
  // In the standard ESP32 Arduino core, this loop() is actually a hidden 
  // FreeRTOS task that runs on Core 1. 
  // No need for this task, Matrix and Web Server are explicitly pinned to the cores.

  // Safely kill the loop task to free up a little bit of SRAM.
  vTaskDelete(NULL); 
}