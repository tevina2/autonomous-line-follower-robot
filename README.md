# Autonomous Line-Following Robotic Vehicle

An embedded systems project implementing an autonomous mobile robotic platform capable of real-time surface tracking and heading correction using an infrared sensor array and differential drive steering.

## System Overview
The robot tracks high-contrast pathways (e.g., black electrical tape on light surface) using optical reflectance sensing. Sensor outputs are processed in real time to calculate heading deviations, feeding differential PWM signals to dual DC motors via an H-bridge driver.

## Hardware Stack
- **Microcontroller:** ATmega328P / Arduino Uno
- **Sensors:** Infrared (IR) Reflectance Sensor Array (TCRT5000)
- **Actuation:** Dual DC Gear Motors with differential chassis
- **Motor Controller:** L298N Dual H-Bridge Driver
- **Power:** 7.4V Li-ion battery pack with regulated 5V logic supply

## Control Logic & System Flow
1. **Sensing:** Continuous digital/analog sampling of reflectance levels to distinguish track boundaries.
2. **Decision Matrix:** 
   - `[0, 0]` Normal straight navigation (balanced PWM).
   - `[1, 0]` Off-axis left detection -> differential deceleration of left wheel to pivot.
   - `[0, 1]` Off-axis right detection -> differential deceleration of right wheel to pivot.
   - `[1, 1]` Terminal condition / cross-junction -> failsafe halt.
3. **Safety & Stability:** PWM speed calibration to eliminate mechanical chassis drift and overshoot during aggressive cornering.

## Repository Structure
- `src/`: Core embedded source code.
- `docs/`: System schematics and architecture notes.
- 
