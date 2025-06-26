# 🌬️ IoT Air Quality Monitoring System

This project monitors air quality using an MQ135 sensor and uploads real-time data to a ThingSpeak cloud dashboard.

## 📦 Components Used
- NodeMCU ESP8266
- MQ135 Gas Sensor
- Jumper Wires
- Wi-Fi Connection

## ⚙️ Circuit Connections

| MQ135 Pin | NodeMCU Pin |
|-----------|-------------|
| VCC       | 3.3V        |
| GND       | GND         |
| A0        | A0          |

## ☁️ Cloud Dashboard (ThingSpeak)
1. Create a ThingSpeak channel
2. Add a field named **Air Quality Value**
3. Copy your **Channel ID** and **Write API Key**
4. Replace them in the code

## 💻 Code Snippet

```cpp
int airQualityValue = analogRead(A0);
ThingSpeak.writeField(channelID, 1, airQualityValue, writeAPIKey);
