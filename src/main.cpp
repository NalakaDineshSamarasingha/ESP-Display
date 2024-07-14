// main.cpp

#include <Arduino.h>
#include <esp32_smartdisplay.h>
#include "ui.h" // Ensure this path is correct relative to your project structure
#include <src/extra/libs/qrcode/lv_qrcode.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <WebServer.h>
#include <Firebase_ESP_Client.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

const char* ssid = "MSI5554";
const char* password = "12345678";

#define API_KEY "AIzaSyDbe1TXxoQD7VRbKU0jYICbJJMl-PozVjM"
#define DATABASE_URL "https://kaluwa-c59b6-default-rtdb.firebaseio.com"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
bool signupOK = false;



WebServer server(80);

void getData(){

}

void handlereq() {
    Serial.println("Handling request for /success");
    ui_init2();
    server.send(200, "text/plain", "UI for Screen 4 updated");

}
void handlereq2() {
    Serial.println("Handling request for /success");
    ui_init();
    server.send(200, "text/plain", "UI for Screen updated");

 }
// void price(){
//     config.api_key = API_KEY;
//     config.database_url = DATABASE_URL;

//     if (Firebase.signUp(&config, &auth, "nalakadinesh97@gmail.com", "")) {
//         Serial.println("ok");
//         signupOK = true;
//     } else {
//         Serial.printf("%s\n", config.signer.signupError.message.c_str());
//     }

//     config.token_status_callback = tokenStatusCallback;
//     Firebase.begin(&config, &auth);
//     Firebase.reconnectWiFi(true);
//     if (Firebase.RTDB.getInt(&fbdo, "/Bun/GalBanis")) {
//         if (fbdo.dataType() == "int") {
//             int PriceDb = fbdo.intData();
//             GalBanis = PriceDb;
//         }
//     }
//     if (Firebase.RTDB.getInt(&fbdo, "/Bun/CreamBun")) {
//         if (fbdo.dataType() == "int") {
//             int PriceDb = fbdo.intData();
//             CreamBun = PriceDb;
//         }
//     }
//     if (Firebase.RTDB.getInt(&fbdo, "/Bun/FishBun")) {
//         if (fbdo.dataType() == "int") {
//             int PriceDb = fbdo.intData();
//             FishBun = PriceDb;
//         }
//     }
//     updatePrice();
// }

void setup() {
#ifdef ARDUINO_USB_CDC_ON_BOOT
    delay(5000);
#endif
    Serial.begin(115200);
    Serial.setDebugOutput(true);
    log_i("Board: %s", BOARD_NAME);
    log_i("CPU: %s rev%d, CPU Freq: %d Mhz, %d core(s)", ESP.getChipModel(), ESP.getChipRevision(), getCpuFrequencyMhz(), ESP.getChipCores());
    log_i("Free heap: %d bytes", ESP.getFreeHeap());
    log_i("Free PSRAM: %d bytes", ESP.getPsramSize());
    log_i("SDK version: %s", ESP.getSdkVersion());

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    //price();
    Serial.println("Connected to WiFi");

    
    server.on("/success", HTTP_GET, handlereq);
    server.on("/done", HTTP_GET, handlereq2);
    server.begin();
    getData();
    smartdisplay_init();
    ui_init();  // Initialize the UI

}

void loop() {
    server.handleClient();
    lv_timer_handler();
    delay(5);  // Small delay to let the CPU rest a bit
}
