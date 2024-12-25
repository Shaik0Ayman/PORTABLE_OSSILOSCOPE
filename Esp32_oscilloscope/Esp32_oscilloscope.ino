#include <WiFi.h>
#include <Wire.h>
#include <U8g2lib.h>
#include "QRCodeGenerator.h"
#include "servers/std/Cstring.hpp"
#include "servers/std/console.hpp"
#include "Esp32_servers_config.h"

#ifndef FILE_SYSTEM
    #include "oscilloscope_amber.h"
#endif

// Define your WiFi credentials
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

// Initialize the OLED display
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

// Define pin and PWM settings
const int ledPin = 12;
const int pwmChannel = 0;
const int pwmFreq = 5000;
const int pwmResolution = 8;

// HTTP request handler
// Handles HTTP requests not processed by the server itself.
String httpRequestHandler(char *httpRequest, httpConnection *hcn) {
    #define httpRequestStartsWith(X) (strstr(httpRequest,X)==httpRequest)

    #ifdef __OSCILLOSCOPE__
        #ifdef __FILE_SYSTEM__
            // Redirect root and index requests to oscilloscope.html if using file system
            if (httpRequestStartsWith("GET / ") || httpRequestStartsWith("GET /index.html ")) {
                hcn->setHttpReplyHeaderField("Location", "/oscilloscope.html");
                hcn->setHttpReplyStatus((char *) "307 temporary redirect");
                return "Redirecting ...";
            }
        #else
            // Handle requests within RAM if not using file system
            if (httpRequestStartsWith("GET / ") || httpRequestStartsWith("GET /index.html ") || httpRequestStartsWith("GET /oscilloscope.html ")) {
                return F(oscilloscope_amber);
            }
        #endif
    #endif

    return "";
}

// WebSocket request handler
void wsRequestHandler(char *wsRequest, WebSocket *webSocket) {
    #define wsRequestStartsWith(X) (strstr(wsRequest,X)==wsRequest)

    #ifdef __OSCILLOSCOPE__
        // Handle oscilloscope run request
        if (wsRequestStartsWith("GET /runOscilloscope")) runOscilloscope(webSocket);
    #endif
}

void setup() {
    Serial.begin(115200);

    // Initialize I2C communication and OLED display
    Wire.begin(21, 22);  
    u8g2.begin();
    u8g2.clearDisplay();

    // Connect to WiFi network
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    // Display Wi-Fi credentials as QR code
    String wifiCredentials = "WIFI:S:" + String(ssid) + ";T:WPA;P:" + String(password) + ";;";
    displayQRCode(wifiCredentials);
    delay(5000);

    // Display IP address as QR code
    displayQRCode(WiFi.localIP().toString());
    delay(5000);

    // Initialize HTTP server with request handlers
    httpServer *httpSrv = new httpServer(httpRequestHandler, wsRequestHandler);
    if (!httpSrv || httpSrv->state() != httpServer::RUNNING) {
        #ifdef __DMESG__
            dmesgQueue << "[httpServer] did not start";
        #endif
        Serial.println("[httpServer] did not start");
    }

    #ifdef FILE_SYSTEM
        // Initialize FTP server if file system is available
        ftpServer *ftpSrv = new ftpServer();
        if (!ftpSrv || ftpSrv->state() != ftpServer::RUNNING) {
            #ifdef __DMESG__
                dmesgQueue << "[ftpServer] did not start";
            #endif
            Serial.println("[ftpServer] did not start");
        }
    #endif
}

// Function to display QR code on OLED
void displayQRCode(String text) {
    QRCode qrcode;
    uint8_t qrcodeData[qrcode_getBufferSize(3)];

    // Initialize QR code with provided text
    qrcode_initText(&qrcode, qrcodeData, 3, 0, text.c_str());

    u8g2.firstPage();
    do {
        // Clear display and prepare to draw
        u8g2.setDrawColor(0);
        u8g2.drawBox(0, 0, u8g2.getDisplayWidth(), u8g2.getDisplayHeight());
        u8g2.setDrawColor(1);

        // Center and draw QR code on display
        int offsetX = (u8g2.getDisplayWidth() - qrcode.size * 2) / 2;
        int offsetY = (u8g2.getDisplayHeight() - qrcode.size * 2) / 2;

        for (uint8_t y = 0; y < qrcode.size; y++) {
            for (uint8_t x = 0; x < qrcode.size; x++) {
                if (qrcode_getModule(&qrcode, x, y)) {
                    u8g2.drawBox(offsetX + x * 2, offsetY + y * 2, 2, 2);
                }
            }
        }
    } while (u8g2.nextPage());
}

void loop() {
    // Main loop does nothing in this setup
}