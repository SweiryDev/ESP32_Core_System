#ifndef LED_MATRIX_H
#define LED_MATRIX_H

#include <Arduino.h>
#include "config.h"

// Initializes the hardware, the Mutex, and spins up the Core 1 Task
void initMatrix();

// Called by the Web Server to push a single static frame
bool updateSingleFrame(uint8_t* frameData);

// Called by the Web Server to push a multi-frame animation sequence
bool loadAnimation(int delayMs, int frameCount, uint8_t frames[][192]);

#endif // LED_MATRIX_H