#include "Arduino.h"
#include <Servo.h>

#define BAUD_RATE 9600

#define SERVO_PIN 5
#define SENSOR_PIN 0

Servo servo;

void setup() {
    Serial.begin(BAUD_RATE);
    servo.attach(SERVO_PIN);
}

void loop() {
    auto pos = analogRead(SENSOR_PIN);

    auto sensorValue = map(pos, 0, 1023, 0, 179);

    servo.write(sensorValue);
    delay(15);

    Serial.println(sensorValue);
}

