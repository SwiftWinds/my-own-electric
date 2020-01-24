#include "Arduino.h"
#include <Servo.h>

#define BAUD_RATE 9600

#define BUTTON_PIN 2
#define SERVO_PIN 5

#define ACTIVE_ROTATION 180
#define INACTIVE_ROTATION 0


Servo servo;

void setup() {
    Serial.begin(BAUD_RATE);
    servo.attach(SERVO_PIN);
}

void loop() {
    if (digitalRead(BUTTON_PIN)) {
        servo.write(ACTIVE_ROTATION);
    } else {
        servo.write(INACTIVE_ROTATION);
    }
}

