# 🌦️ Arduino Weather Detector

An interactive weather detection system built with **Arduino UNO** that measures **temperature and humidity** in real-time and provides both **digital (LCD)** and **physical (servo motor)** indicators of the weather.  

The project demonstrates how **sensor integration + actuator control** can be combined to create a smart embedded system prototype.

---

## 📸 Project Demo

### Hardware in Action
| OUTPUT 1 | OUTPUT 2 |
|----------------------|--------------------------|
| ![Output](https://github.com/nishantmohanani59-tech/Arduino-Weather-Detector/blob/main/project_prototype.jpg) | ![OUTPUT](https://github.com/nishantmohanani59-tech/Arduino-Weather-Detector/blob/main/project_prototype2.jpg) |

---

## 🛠️ Features
- Real-time measurement of:
  - 🌡️ **Temperature** (°C)  
  - 💧 **Humidity** (%)  
- **LCD Display** shows live readings.  
- **Servo motor** acts as a physical weather indicator:  
  - ☀️ Points to *Clear* when weather is sunny.  
  - ☁️ Points to *Cloudy* when humidity is high.  
- Multiple sensors (DHT22, LDR, TMP, etc.) used for environmental monitoring.  

---

## ⚙️ Components Used
- Arduino UNO  
- DHT22 Temperature & Humidity Sensor  
- 16x2 LCD Display (with I2C interface)  
- Servo Motor (SG90)  
- LDR (Light Dependent Resistor)  
- Breadboard, Jumper Wires, Power Supply  

---

## 🔌 Circuit Diagram
Below is the circuit wiring for the system:  

![Circuit Diagram](https://github.com/nishantmohanani59-tech/Arduino-Weather-Detector/blob/main/Schematics.jpg)

---

## 🚀 How It Works
1. **Sensor Readings**  
   - DHT22 continuously measures temperature and humidity.  
   - LDR detects light intensity (helps determine sunny vs cloudy).  

2. **Data Display**  
   - Values are displayed on the 16x2 LCD screen.  

   Example output:  
          TEMP: 31 °C
          HUMID: 59 %


3. **Weather Indication via Servo**  
- Arduino logic interprets sensor data.  
- If humidity > threshold → Servo points to *Cloudy*.  
- Else → Servo points to *Clear*.  

---

## 💻 Code Overview

The main logic is divided into three parts: **setup**, **loop**, and **decision-making for weather conditions**.

### 1️⃣ Setup Section
```cpp
#include <DHT.h>
#include <Servo.h>
#include <LiquidCrystal.h>

DHT dht(2, DHT22); 
Servo weatherServo;
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
lcd.begin(16, 2);
dht.begin();
weatherServo.attach(6);
}

### 2️⃣ Loop Section
```cpp
void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  lcd.setCursor(0, 0);
  lcd.print("TEMP: ");
  lcd.print(temp);
  lcd.print(" *C");

  lcd.setCursor(0, 1);
  lcd.print("HUMID: ");
  lcd.print(hum);
  lcd.print(" %");

  if (hum > 60) {
    weatherServo.write(120);  // Cloudy position
  } else {
    weatherServo.write(30);   // Clear position
  }

  delay(2000);
}
```

## 📷 Project Images
- LCD & Sensor Output

- Servo Weather Indicator

- Full Setup with Arduino

## 🧑‍💻 Skills & Learning

- Sensor integration with Arduino (DHT22, LDR).

- Real-time data visualization with LCD.

- Actuator control using servo motors.

- Hands-on practice with circuit design and breadboard prototyping.

- Bridging hardware + software logic into a functional system.

## 📌 Future Improvements

- Add Wi-Fi module (ESP8266) for IoT-based weather logging.

- Implement data logging to SD card.

- Enhance classification (Sunny, Cloudy, Rainy) with more sensors.

## 🔖 License

- This project is for educational and learning purposes. Feel free to modify and improve upon it.
