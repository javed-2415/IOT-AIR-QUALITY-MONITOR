#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

const char* ssid = "YourWiFi";
const char* password = "YourPassword";
WiFiClient client;

unsigned long channelID = YourChannelID; // Replace with your channel number
const char* writeAPIKey = "YourWriteAPIKey";

int mq135Pin = A0;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println("Connected to WiFi");
  ThingSpeak.begin(client);
}

void loop() {
  int airQualityValue = analogRead(mq135Pin);
  Serial.print("Air Quality: ");
  Serial.println(airQualityValue);

  ThingSpeak.writeField(channelID, 1, airQualityValue, writeAPIKey);

  delay(15000); // Update every 15 seconds
}
