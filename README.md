# Wireless Bluetooth Bot (HC-05)

Arduino-based **wireless robot** controlled via **Bluetooth** using an HC-05 module.  
You can control the robot manually using a phone or PC via a Bluetooth serial terminal.

---

## Features

- Forward, backward, left, right movement.  
- Stop motor at any time.  
- Speed adjustment (optional, can be implemented).  
- Controlled wirelessly using **HC-05 Bluetooth module**.  

---

## Components

- Arduino Uno (or compatible board)  
- 2 DC motors with L298N or similar motor driver  
- HC-05 Bluetooth module  
- Jumper wires  
- Power supply / battery pack  

---

## Pin Configuration

| Component           | Pin           |
|--------------------|---------------|
| Motor 1 IN1         | 8             |
| Motor 1 IN2         | 9             |
| Motor 1 ENA (PWM)   | 10            |
| Motor 2 IN3         | 13            |
| Motor 2 IN4         | 12            |
| Motor 2 ENB (PWM)   | 11            |
| HC-05 TX → Arduino RX | RX (0)       |
| HC-05 RX → Arduino TX | TX (1)       |
| HC-05 VCC           | 5V            |
| HC-05 GND           | GND           |

> **Note:** If using Arduino 5V logic, use a voltage divider on HC-05 RX pin.

---

## How It Works

- Connect your phone/PC to the **HC-05 Bluetooth module**.  
- Open any **Bluetooth serial terminal app** (Android, iOS, or PC).  
- Send commands via the serial terminal to control the bot:  

| Command | Action          |
|---------|----------------|
| F       | Move Forward    |
| B       | Move Backward   |
| L       | Turn Left       |
| R       | Turn Right      |
| S       | Stop Motors     |
| +       | Speed Up (optional) |
| -       | Slow Down (optional) |

- The Arduino reads the commands over Bluetooth and controls the motors using PWM.

---

## Usage

1. Connect the motors and HC-05 module as per the pin configuration.  
2. Upload `wirelessBot.ino` to your Arduino using Arduino IDE.  
3. Pair your phone/PC with the HC-05 module (`1234` default PIN).  
4. Open a Bluetooth terminal app and send commands to control the bot.  

---

## Code

- The main Arduino sketch is `wirelessBot.ino`.  
- Motor speed is set using the `speed` variable in the code.  



## LIVE DEMO
https://www.linkedin.com/posts/tarush-bajpai_roboticsinternship-makex-autonomousrobots-ugcPost-7359528620685479938-HlVH?utm_source=share&utm_medium=member_desktop&rcm=ACoAAEDF1jMBO1Ndq53HUyGuJhyBpf-tR1Vachc

This project is open-source under the **MIT License**.  
Feel free to use and modify it for personal or educational purposes.
