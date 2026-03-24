#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include <Arduino.h>

// Connects to WiFi, sets up the HTTP routes, and spins up the Core 0 Task
void initWebServer();

#endif // WEB_SERVER_H