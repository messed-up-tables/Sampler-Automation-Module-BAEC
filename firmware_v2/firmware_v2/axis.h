#ifndef AXIS_H
#define AXIS_H

#include "motorController.h"

class Axis {
  motorController motor;
  const int limitSwPin;
  long currentPos = 0;
  long targetPos = 0;
  long delta;
  bool isHomed = false;
  int inputMultiplier;

public:
  Axis(int dir, int step, int en, int limitPin)
    : motor(dir, step, en), limitSwPin(limitPin) {}

  void begin() {
    motor.begin();
    pinMode(limitSwPin, INPUT_PULLUP);
    currentPos = 0;
    targetPos = 0;
  }

  void home() {
    motor.enable();
    motor.dir(false); // move towards limit switch
    while (digitalRead(limitSwPin)) {
      //motor.step();
      delay(5);
    }
    currentPos = 0;
    isHomed = true;
  }

  void moveToTarget() {
    //if (!isHomed) return;
    delta = targetPos - currentPos;
    if(moveDelta(delta)) {
      if(delta>0) {
        currentPos++;
      }
      else if(delta<0) {
        currentPos--;
      }
      //Serial.print(currentPos);
      //Serial.print(" ");
    }
    
  }
  

  void moveTo(long pos) {
    //if (!isHomed) return;
    delta = pos - currentPos;
    if(moveDelta(delta)) {
      if(delta>0) {
        currentPos++;
      }
      else if(delta<0) {
        currentPos--;
      }
      //Serial.print(currentPos);
      //Serial.print(" ");
    }
    
  }

  bool moveDelta(long delta) {
    if(delta == 0){
      motor.disable();
      return;
    }
    motor.enable();
    motor.dir(delta>0);

    if(motor.stepTick()){
      return true;
    }
    return false;
  }




  long getPos() const {
    return currentPos;
  }

  long getTarget() {
    return targetPos;
  }
  void setTarget(long pos) {
    targetPos = pos;
  }

  void updateTarget(long delta) {
    targetPos += (delta*inputMultiplier);
  }

  void setMultiplier(int i) {
    inputMultiplier = i;
  }
  bool homed() const {
    return isHomed;
  }
};

#endif
