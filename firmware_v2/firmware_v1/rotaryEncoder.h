#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H

class rotaryEncoder {
  const int clkPin, dtPin, swPin;
  int clkState;
  int btnState;
  int dtState;
  int reading;
  int lastClkState;
  int lastBtnState;
  int lastDtState;
  bool buttonPressed = false;
  unsigned long lastBtnTime = 0;
  unsigned long lastClkTime = 0;
  unsigned long lastDtTime = 0;
  const unsigned long debounceDelay = 10;
  const unsigned long holdDelay = 2000;

public:
  rotaryEncoder(int clk, int dt, int sw)
    : clkPin(clk), dtPin(dt), swPin(sw) {}

  void begin() {
    pinMode(clkPin, INPUT);
    pinMode(dtPin, INPUT);
    pinMode(swPin, INPUT_PULLUP);
    lastClkState = digitalRead(clkPin);
    buttonPressed == false;
  }

  int readRotation(){
    
    if((millis()-lastClkTime)<debounceDelay) {
      return 0;
    }
/*
    if((millis()-lastDtTime)>debounceDelay) {
      return 0;
    }*/

    if((millis()-lastClkTime)>debounceDelay) {
      clkState = digitalRead(clkPin);
      if(clkState != lastClkState) {
        lastClkTime = millis();
      }
    }

    if((millis()-lastDtTime)>debounceDelay) {
      dtState = digitalRead(dtPin);
      if(dtState != lastDtState) {
        lastDtTime = millis();
      }
    }

    if (clkState == 1 && lastClkState == 0 ) {
      lastClkState = clkState;
      if (dtState == 1) {
        lastDtState = dtState;
        return 1;
      }
      else {
        lastDtState = dtState;
        return -3;
      }
    }

    lastClkState = clkState;
    lastDtState = dtState;
    return 0;
  }

/*
  int readRotation() {
    //clkState = digitalRead(clkPin);
    //if (clkState != lastClkState ) {
    if (clkState == 0 && lastClkState == 1 ) {
      lastClkState = clkState;
      if (digitalRead(dtPin) == 1) return 1;
      else return -1;
    }
    lastClkState = clkState;
    return 0;
  }
*/

  int readButton() {
    btnState = digitalRead(swPin);
    if(btnState == 0 && lastBtnState == 1) {
      lastBtnTime = millis();
      lastBtnState = btnState;
      buttonPressed = true;
      return 0;
    }
    else if(buttonPressed == true && (millis()-lastBtnTime) > holdDelay) {
      buttonPressed = false;
      return -1;
    }
    else if(buttonPressed == true && btnState == 1){
      lastBtnState = btnState;
      buttonPressed = false;
      return 1;
    }
    lastBtnState = btnState;
    return 0;
  }


  /*
  bool readButton() {
    bool reading = !digitalRead(swPin);
    if (reading && !buttonPressed && (millis() - lastBtnTime > debounceDelay)) {
      lastBtnTime = millis();
      buttonPressed = true;
      return true;
    } else if (!reading) {
      buttonPressed = false;
    }
    return false;
  }
  */

  void debug(){
    Serial.print(digitalRead(clkPin));
    Serial.print(" ");
    Serial.print(digitalRead(dtPin));
  }
};

#endif
