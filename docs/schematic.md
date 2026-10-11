## Hardware Interconnection & Pinout

### 1. Arduino Uno to L298N Motor Driver
| Arduino Pin | L298N Pin | Function |
| :--- | :--- | :--- |
| `D5` (PWM) | `ENA` | Left Motor Speed Control |
| `D6` | `IN1` | Left Motor Direction 1 |
| `D7` | `IN2` | Left Motor Direction 2 |
| `D8` | `IN3` | Right Motor Direction 1 |
| `D9` | `IN4` | Right Motor Direction 2 |
| `D10` (PWM) | `ENB` | Right Motor Speed Control |
| `GND` | `GND` | Common Ground Reference |

### 2. Arduino Uno to IR Sensors (TCRT5000)
| Arduino Pin | Sensor Pin | Function |
| :--- | :--- | :--- |
| `D2` | Left Sensor `OUT` | Left Track Digital Output |
| `D3` | Right Sensor `OUT` | Right Track Digital Output |
| `5V` | `VCC` | Sensor VCC Supply |
| `GND` | `GND` | Ground Reference |

### 3. Power Architecture
- **Motor Supply:** External 7.4V / 9V Battery Pack -> L298N `12V/VMS` and `GND`
- **Logic Supply:** 5V Regulated output -> Arduino Uno `5V` and Sensor `VCC`
- **Ground:** Common ground established across battery, driver, and Arduino.
- 
