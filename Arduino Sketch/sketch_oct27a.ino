#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "SSID"; 
const char* password = "Password";         

WebServer server(80);
const int ledPin = 2;               
bool wifiConnected = false;        

void setCORS() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.sendHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
  server.sendHeader("Access-Control-Allow-Headers", "Content-Type");
}

void handleOptions() {
  setCORS();
  server.send(204);
}

void handleLED() {
  setCORS();

  if (server.hasArg("state")) {
    String state = server.arg("state");

    if (state == "on" || state == "1") {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED ON");
      server.send(200, "text/plain", "LED turned ON");
    } 
    else if (state == "off" || state == "0") {
      digitalWrite(ledPin, LOW);
      Serial.println("LED OFF");
      server.send(200, "text/plain", "LED turned OFF");
    } 
    else {
      server.send(400, "text/plain", "Invalid state");
    }
  } else {
    server.send(400, "text/plain", "Missing 'state' parameter");
  }
}


void connectToWiFi() {
  Serial.print("\nConnecting to Wi-Fi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  int maxAttempts = 20; 
  while (WiFi.status() != WL_CONNECTED && maxAttempts > 0) {
    delay(500);
    Serial.print(".");
    maxAttempts--;
  }

  if (WiFi.status() == WL_CONNECTED) {
    wifiConnected = true;
    Serial.println("\n✅ Wi-Fi connected!");
    Serial.print("ESP32 IP address: ");
    Serial.println(WiFi.localIP());
  } else {
    wifiConnected = false;
    Serial.println("\n❌ Failed to connect to Wi-Fi.");
    Serial.println("Check your SSID and password.");
  }
}


void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  connectToWiFi();

  if (wifiConnected) {
    server.on("/led", HTTP_GET, handleLED);
    server.on("/led", HTTP_OPTIONS, handleOptions);
    server.begin();
    Serial.println("🌐 Server ready to receive requests!");
  }
}

void loop() {
  if (wifiConnected) {
    server.handleClient();
  } else {
    static unsigned long lastAttempt = 0;
    if (millis() - lastAttempt > 5000) {
      Serial.println("🔄 Trying to reconnect...");
      connectToWiFi();
      lastAttempt = millis();
    }
  }
}
