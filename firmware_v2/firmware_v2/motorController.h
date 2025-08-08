#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include <Arduino.h>

class motorController {
  const int dirPin, stepPin, enPin;
  unsigned long lastStepTime = 0;
  unsigned int stepInterval = 800; // in microseconds // prev 200 
  bool stepState = false;

public:
  motorController(int dir, int step, int en) 
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

  void setStepInterval(unsigned int us) {
  stepInterval = us;
  }

  bool stepTick() {
    //unsigned long now = micros();
    if (micros() - lastStepTime >= stepInterval) {
      lastStepTime = micros();
      stepState = !stepState;
      digitalWrite(stepPin, stepState);
      return stepState == LOW; // return true when pulse completed (HIGH→LOW)
    }
    return false;
  }
  
  /*
  void step() {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(2);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2);
  }*/
};

#endif
