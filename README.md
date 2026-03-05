# 🚀 STM32 Nucleo Skill Lab – Embedded Systems Projects

This repository contains a set of **hands-on embedded system experiments** developed during a **one-week STM32 Nucleo Skill Lab**.
The goal of this lab was to explore **microcontroller peripherals, sensor interfacing, and real-time embedded programming** using **Embedded C and STM32CubeIDE**.

These projects demonstrate practical implementations of **GPIO control, sensors, actuators, and serial communication**.

---

## 🧠 Learning Focus

During this lab, the following embedded concepts were explored:

* Microcontroller GPIO programming
* Sensor interfacing
* Digital and analog signal reading
* Buzzer and LED control
* Serial communication with PC
* Real-time embedded applications

---

## 🛠 Hardware Used

* STM32 Nucleo Development Board
* LEDs
* Active Buzzer
* Touch Sensor Module
* DHT11 Temperature & Humidity Sensor
* LDR (Light Dependent Resistor) Sensor
* Breadboard & Jumper Wires

---

## 💻 Software Tools

* STM32CubeIDE
* Embedded C
* Arduino IDE (for serial monitoring in sensor testing)
* Git & GitHub

---

# 📂 Implemented Projects

## 1️⃣ LED Blink

A basic embedded systems program where an LED connected to the STM32 board **blinks at regular intervals**.
This experiment introduces **GPIO configuration and delay-based timing**.

---

## 2️⃣ SOS Morse Code LED Blink

The LED blinks in the **SOS Morse code pattern (··· --- ···)**.
This project demonstrates **precise timing control and pattern generation using GPIO**.

---

## 3️⃣ Different Buzzer Patterns

An active buzzer is programmed to produce **multiple sound patterns**.
This experiment demonstrates **signal timing and actuator control** using the microcontroller.

Examples of patterns include:

* Short beep pattern
* Long alert tone
* Repeating alarm sequence

---

## 4️⃣ Touch Sensor Controlled Buzzer

A **touch sensor module** is used as input to trigger buzzer patterns.
When the sensor detects touch, the microcontroller activates the buzzer.

Concepts used:

* Digital input reading
* Event-driven control
* Sensor interfacing

---

## 5️⃣ Temperature & Humidity Monitoring (DHT11)

The **DHT11 sensor** is used to measure environmental conditions.

The STM32 reads:

* 🌡 Temperature
* 💧 Humidity

The values are displayed in the **Arduino IDE Serial Monitor** for real-time monitoring.

---

## 6️⃣ Light Intensity Measurement

A **Light Dependent Resistor (LDR)** is used to measure ambient light intensity.

The STM32 reads the analog signal and sends the value to the **serial monitor**, allowing observation of light level changes.

Applications:

* Automatic lighting systems
* Smart home lighting
* Environmental monitoring

---

# 📁 Repository Structure

```
STM32-Nucleo-Skill-Lab
│
├── Projects
│   ├── LED_Blink
│   ├── SOS_Morse_LED
│   ├── Buzzer_Patterns
│   ├── Touch_Sensor_Buzzer
│   ├── DHT11_Temperature_Humidity
│   └── Light_Intensity_LDR
│
├── Images
│   └── Project Outputs / Circuit Diagrams
│
└── README.md
```

---

# 🎯 Skills Developed

Through these experiments, the following skills were gained:

* Embedded C Programming
* STM32 Peripheral Configuration
* Sensor Interfacing
* Hardware Debugging
* Serial Communication
* Real-Time Embedded System Design

---

# 👨‍💻 Author

**Alvayajnesh**
Electronics & Embedded Systems Enthusiast

GitHub:
https://github.com/alvayajnesh


