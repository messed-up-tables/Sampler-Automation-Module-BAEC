#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include <Arduino.h>

class motorController {
  const int dirPin, stepPin, enPin;
  unsigned long lastStepTime = 0;
  unsigned int stepInterval = 2; // in microseconds
  bool stepState = false;

public:
  motorController(const int dir, const int step, const int en) 
    : dirPin(dir), stepPin(step), enPin(en) {}

  void begin() {
    pinMode(dirPin, OUTPUT);
    pinMode(stepPin, OUTPUT);
    pinMode(enPin, OUTPUT);
    disable();
  }

    void enable() {
    digitalWrite(enPin, LOW); // LOW to enable A4988
  }

  void disable() {
    digitalWrite(enPin, HIGH); // HIGH to disable A4988
  }

  void dir(bool direction) {
    digitalWrite(dirPin, direction);
  }

  void step() {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(800);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(800);
  }

};

#endif