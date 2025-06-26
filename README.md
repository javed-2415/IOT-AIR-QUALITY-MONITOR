# 🌬️ IoT Air Quality Monitoring System

## 🚀 Project Title:
**Build a Device That Monitors Air Quality and Displays Data on a Cloud Dashboard**

---

## 📋 Intern Details

- **👨‍💼 Name:** Shaik Javed Ahmed  
- **🎓 Intern ID:** CT04DF594  
- **🏢 Company:** CodTech IT Solutions  
- **🌐 Domain:** Internet of Things  
- **📅 Internship Duration:** 4 Weeks  
- **🧑‍🏫 Mentor:** Neela Santhosh  

---

## 📌 Project Overview

This project creates a smart **Air Quality Monitoring System** that measures CO2 or PM2.5 levels using a gas sensor like MQ135 and displays **live air quality data on a cloud dashboard** (ThingSpeak). It helps monitor indoor or outdoor air pollution with **historical trend analysis**.

---

## 🔧 Components Required

| Component        | Quantity |
|------------------|----------|
| NodeMCU ESP8266  | 1        |
| MQ135 Gas Sensor | 1        |
| Jumper Wires     | As needed|
| Internet (Wi-Fi) | 1        |
| ThingSpeak Account | 1      |

---

## 🧩 Circuit Connections
![Image](https://github.com/user-attachments/assets/6f9a33d2-f078-4015-ae16-00fe4af6c603)

| MQ135 Pin | NodeMCU Pin |
|-----------|-------------|
| VCC       | 3.3V        |
| GND       | GND         |
| A0        | A0          |

---

## ☁️ ThingSpeak Dashboard Setup

1. Go to [https://thingspeak.com](https://thingspeak.com) and create an account.
2. Click **New Channel** → Add:
   - **Field 1:** Air Quality Value
3. Save the channel.
4. Go to the **API Keys** tab → Copy the **Write API Key**
5. Copy the **Channel ID** from the top of the channel page.

---

## 💻 Arduino Code (`air_quality_monitor.ino`)

```cpp
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

const char* ssid = "YourWiFi";
const char* password = "YourPassword";
WiFiClient client;

unsigned long channelID = YourChannelID; // Replace with actual channel number
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
