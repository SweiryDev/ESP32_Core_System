#include "FreeRTOSConfig.h"
#include "led_matrix.h"
#include <Adafruit_NeoPixel.h>

// Initialize NeoPixel object using settings from config.h
Adafruit_NeoPixel pixels(NUMPIXELS, MATRIX_PIN, NEO_RGB + NEO_KHZ800);

// --- Private Globals ---
static uint8_t animationFrames[MAX_FRAMES][192];
static int currentFrameCount = 1; 
static int frameDelayMs = 0;
static bool newAnimationReady = false;

static uint8_t* hardwarePixelBuffer;
static SemaphoreHandle_t frameMutex; 
static TaskHandle_t MatrixTask;

// --- The Hardware Worker Thread ---
void MatrixTaskCode(void * parameter) {
  for(;;) {
    int localFrameCount = 1;
    int localDelayMs = 0;
    
    // Safely read current playback settings
    if (xSemaphoreTake(frameMutex, portMAX_DELAY)) {
      localFrameCount = currentFrameCount;
      localDelayMs = frameDelayMs;
      xSemaphoreGive(frameMutex);
    }

    // Projector Loop
    for (int i = 0; i < localFrameCount; i++) {
      bool restartEarly = false;
      
      if (xSemaphoreTake(frameMutex, portMAX_DELAY)) {
        // If Core 0 just gave us new data, break out of the current animation loop
        if (newAnimationReady) {
          newAnimationReady = false; 
          restartEarly = true;         
        } else {
          // Otherwise, copy the current frame to the physical LED buffer
          memcpy(hardwarePixelBuffer, animationFrames[i], 192);
        }
        xSemaphoreGive(frameMutex);
      }
      
      if (restartEarly) break; 
      
      pixels.show();
      if (localDelayMs > 0) delay(localDelayMs);
    }
    
    if (localDelayMs == 0) delay(20); // Base frame rate for smooth live drawing
  }
}

// --- Public Interface Functions ---

void initMatrix() {
  pixels.begin();
  hardwarePixelBuffer = pixels.getPixels();
  memset(animationFrames[0], 0, 192); 
  pixels.show();

  frameMutex = xSemaphoreCreateMutex();

  // Explicitly spawn this task and pin it to Core 1
  /* xTaskCreatePinnedToCore(
    MatrixTaskCode,   // Function to implement the task
    "MatrixTask",     // Name of the task
    10000,            // Stack size in words
    NULL,             // Task input parameter
    1,                // Priority of the task
    &MatrixTask,      // Task handle
    1                 // Core where the task should run (Core 1)
  ); */

  // Attach a ready to run task
  xTaskCreate(
    MatrixTaskCode, // Task Function
    "MatrixTaskCode", // Task Name
    4096, // Stack size (words)
    NULL, // Function Parameters
    configMAX_PRIORITIES - 1, // Priority
    &MatrixTask // Task Handle
    );
}

bool updateSingleFrame(uint8_t* frameData) {
  if (xSemaphoreTake(frameMutex, portMAX_DELAY)) {
    currentFrameCount = 1;
    frameDelayMs = 0;
    memcpy(animationFrames[0], frameData, 192);
    newAnimationReady = true;
    xSemaphoreGive(frameMutex);
    return true;
  }
  return false;
}

bool loadAnimation(int delayMs, int frameCount, uint8_t frames[][192]) {
  if (xSemaphoreTake(frameMutex, portMAX_DELAY)) {
     frameDelayMs = delayMs;
     currentFrameCount = frameCount;
     for (int i = 0; i < frameCount; i++) {
       memcpy(animationFrames[i], frames[i], 192);
     }
     newAnimationReady = true;
     xSemaphoreGive(frameMutex);
     return true;
  }
  return false;
}