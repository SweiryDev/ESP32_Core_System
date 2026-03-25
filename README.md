# ESP32-S3 Core System & Matrix Engine

A high-performance, operating environment for the ESP32-S3, featuring a real-time web dashboard and WS2812B NeoPixel animation engine. 

![Dashboard Screenshot](assets/dashboard_screenshot.png)

## System Architecture & FreeRTOS Implementation

This project breaks away from the standard monolithic Arduino `loop()` by implementing  FreeRTOS architecture. This ensures that heavy network traffic or Base64 payload decoding..

* **Task 1 (Network Engine):** Dedicated to handling asynchronous Wi-Fi requests, serving the HTML/Tailwind frontend, and parsing multi-frame Base64 animation payloads.
* **Task 2 (Hardware Projector):** Dedicated hardware thread. It infinitely loops through the active animation buffer, pushing pixels to the matrix at the requested frame rate.
* **IPC (Inter-Process Communication):** The two cores safely share data using a FreeRTOS `SemaphoreHandle_t` (Mutex). Task 1 locks the memory just long enough to copy new frame arrays, and Task 2 locks it just long enough to read them, completely eliminating race conditions and visual tearing.

## ✨ Features

* **Multi-App Dashboard:** A scalable root control panel (`/`) designed to host multiple system modules (e.g., Matrix Operator, Telemetry, OTA Sync) with a live hardware uptime tracker.
* **Matrix Operator (`/matrix`):** A fully responsive, mobile-friendly web UI built with Tailwind CSS.
* **Real-Time Drawing:** Draw directly on the web canvas and see instant hardware updates.
* **Animation Studio:** Capture custom multi-frame sequences, define the delay in milliseconds, and deploy them to the board's RAM.
* **Mathematical Presets:** The frontend dynamically generates complex RGB animation matrices (Police strobes, Rainbow shifts, Sweep, Spin) based on your active color and brightness selections.
* **Hardware Protections:** Enforces brightness clamping to prevent high intensities.

![Matrix Operator](assets/matrix_ui_screenshot.png)

## 🛠️ Hardware Requirements

* **Microcontroller:** Waveshare ESP32-S3-Matrix (compatible with other dual-core ESP32 variants)
* **Display:** Onboard 8x8 WS2812B NeoPixel Matrix
* **Wiring:** Matrix Data IN is internally routed to **GPIO 14** on this specific board (Configurable in `config.h` for custom builds)

## 📂 Repository Structure

```text
ESP32_Core_System/
├── config.h               # Global configuration (Network credentials, Pins, Engine limits)
├── ESP32_Core_System.ino  # Bootloader & Task assignment
├── html_views.h           # UI Strings (Dashboard & Matrix Operator)
├── led_matrix.cpp/.h      # Core 1: NeoPixel hardware logic and Mutex locks
└── web_server.cpp/.h      # Core 0: Wi-Fi, HTTP Server, and Payload Parsing
```

## 🚀 Getting Started

1. **Clone the repository:**
   ```bash
   git clone https://github.com/SweiryDev/ESP32_Core_System
   ```
2. **Configure Settings:**
   Open `config.h` and update your Wi-Fi credentials:
   ```cpp
   #define WIFI_SSID     "Your_SSID"
   #define WIFI_PASSWORD "Your_PASSWORD"
   ```
   *Modify `MATRIX_PIN` if you are using a different GPIO.*
3. **Dependencies:**
   Ensure you have the **Adafruit NeoPixel** library installed in your Arduino IDE / PlatformIO.
4. **Compile & Upload:**
   Flash the code to your ESP32. Open the Serial Monitor (115200 baud) to find the assigned IP address, and navigate to it in your web browser.

## 🛣️ Roadmap

* Expand the animation memory buffer utilizing PSRAM for larger matrices.
* Implement non-volatile flash storage (LittleFS/SPIFFS) to save and load custom frames and animation sequences persistently across reboots.

---
*If you find this project interesting, feel free to star the repo or open a pull request!*