# Smart Home Automation System 🏠

An Arduino-based smart home simulation built with TinkerCAD, implementing two independent automation subsystems in C++.

Developed as part of the **Robotics Applications** coursework at the **School of Mechanical Engineering, NTUA** (2025–2026).

---

## Subsystems

### 1. Smart Door Lock (`smart_door_lock.ino`)
An automated door access system using proximity detection and a 4-digit keypad.

**How it works:**
- An **HC-SR04 ultrasonic sensor** continuously monitors the distance in front of the door
- When an object/person is detected within **50 cm**, the system prompts for a 4-digit code
- If the correct code is entered via the **4×4 keypad**, a **servo motor** rotates to unlock the door and a **MOSFET-controlled output** (e.g. light/buzzer) activates
- The door automatically re-locks after 3 seconds

**Components:**
| Component | Pin |
|-----------|-----|
| HC-SR04 Ultrasonic Sensor (Trig) | D9 |
| HC-SR04 Ultrasonic Sensor (Echo) | D10 |
| 4×4 Keypad (Rows) | D2, D3, D4, D5 |
| 4×4 Keypad (Cols) | D11, D12, D13, D6 |
| Servo Motor | D7 |
| MOSFET Output | D8 |

---

### 2. Temperature-Controlled Fan (`temp_fan_control.ino`)
An automatic fan speed controller based on ambient temperature readings.

**How it works:**
- A **TMP36 temperature sensor** reads the ambient temperature every second
- If the temperature exceeds **35°C**, a DC fan motor activates via PWM
- The fan turns off automatically when the temperature drops below the threshold

**Components:**
| Component | Pin |
|-----------|-----|
| TMP36 Temperature Sensor | A0 |
| DC Motor (via PWM) | D9 |

---

## Technologies
- **Language:** C++ (Arduino framework)
- **Platform:** Arduino Uno
- **Simulation:** [TinkerCAD Circuits](https://www.tinkercad.com/)
- **Libraries:** `Keypad.h`, `Servo.h`

---

## How to Run
1. Open [TinkerCAD](https://www.tinkercad.com/) and create a new Circuit
2. Add the components listed above and wire them according to the pin assignments
3. Paste the `.ino` code into the Code Editor
4. Click **"Start Simulation"**

Alternatively, upload the `.ino` files directly to a physical Arduino Uno using the [Arduino IDE](https://www.arduino.cc/en/software).

---

## Author
**Iasonas Zarogiannis**  
School of Mechanical Engineering, NTUA  
Academic Year 2025–2026
