#ifndef CONFIG_H
#define CONFIG_H

// Network Configuration
#define WIFI_SSID     "YOUR_SSID"
#define WIFI_PASSWORD "YOUR_PASSWORD"
#define SERVER_PORT   80

// Hardware Configuration (Matrix)
#define MATRIX_PIN        14 
#define NUMPIXELS         64 

// Animation Engine Limits
// Maximum number of frames the ESP32 will store in RAM for a single animation.
#define MAX_FRAMES        20 

#endif // CONFIG_H