/*
 * Autonomous Differential-Drive Line-Following Robot
 * Target: Arduino Uno / ATmega328P
 * Description: Infrared sensor-guided tracking using differential motor control.
 */

// Pin Definitions - Sensors
const int LEFT_SENSOR_PIN   = 2;
const int RIGHT_SENSOR_PIN  = 3;

// Pin Definitions - Motor Driver (L298N)
const int ENA = 5;  // PWM Speed Control Left Motor
const int IN1 = 6;  // Direction Pin 1 Left
const int IN2 = 7;  // Direction Pin 2 Left
const int IN3 = 8;  // Direction Pin 1 Right
const int IN4 = 9;  // Direction Pin 2 Right
const int ENB = 10; // PWM Speed Control Right Motor

// Base Speed Constants (0 - 255)
const int BASE_SPEED = 160;
const int TURN_SPEED = 130;

void setup() {
    pinMode(LEFT_SENSOR_PIN, INPUT);
    pinMode(RIGHT_SENSOR_PIN, INPUT);

    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
}

void loop() {
    // Read sensor state: 1 (Black line detected), 0 (White surface)
    int leftVal  = digitalRead(LEFT_SENSOR_PIN);
    int rightVal = digitalRead(RIGHT_SENSOR_PIN);

    if (leftVal == 0 && rightVal == 0) {
        // Line centered between sensors: drive straight
        driveForward(BASE_SPEED, BASE_SPEED);
    } 
    else if (leftVal == 1 && rightVal == 0) {
        // Line detected on left: pivot left
        pivotLeft(TURN_SPEED);
    } 
    else if (leftVal == 0 && rightVal == 1) {
        // Line detected on right: pivot right
        pivotRight(TURN_SPEED);
    } 
    else {
        // Both triggered (intersection or boundary): hold position
        stopMotors();
    }
}

void driveForward(int leftSpeed, int rightSpeed) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, leftSpeed);
    analogWrite(ENB, rightSpeed);
}

void pivotLeft(int speed) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
}

void pivotRight(int speed) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
}

void stopMotors() {
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
}

