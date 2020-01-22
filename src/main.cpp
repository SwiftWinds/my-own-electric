#include "Arduino.h"
#include <Servo.h>

#define BAUD_RATE 9600

#define BUTTON_PIN 2
#define SERVO_PIN 5

#define ACTIVE_ROTATION 180
#define INACTIVE_ROTATION 0


Servo servo;

enum state {
    BUTTON_NOT_PRESSED,
    BUTTON_PRESSED
};

state _state = BUTTON_NOT_PRESSED;

state getState() {
    return _state;
}

void setState(state newState) {
    _state = newState;
}

void setup() {
    Serial.begin(BAUD_RATE);
    servo.attach(SERVO_PIN);
}

void loop() {
    switch (getState()) {
        case BUTTON_NOT_PRESSED: {
            servo.write(INACTIVE_ROTATION);
            if (digitalRead(BUTTON_PIN)) {
                Serial.println(String("button was detected as on: ") + digitalRead(BUTTON_PIN));
                setState(BUTTON_PRESSED);
            }
        }
        case BUTTON_PRESSED: {
            servo.write(ACTIVE_ROTATION);
            if (!digitalRead(BUTTON_PIN)) {
                Serial.println(String("button was detected as off: ") + digitalRead(BUTTON_PIN));
                setState(BUTTON_NOT_PRESSED);
            }
        }
    }
}

