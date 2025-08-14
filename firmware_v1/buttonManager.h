#ifndef BUTTON_H
#define BUTTON_H

enum ButtonState {
    NOT_PRESSED,
    PRESS,
    HOLD
};

class Button {

private:
    int pin;
    bool lastBtnState;
    bool btnState;
    unsigned long currentTime;
    unsigned long lastBtnTime = 0;
    unsigned long pressStartTime = 0;
    unsigned long holdThreshold = 1000;
    int state, currentState;
    bool buttonPressed;
    bool debounced = 0;

    static const unsigned long debounceDelay = 30;

public:
    Button(int _pin): pin(_pin) {} ;

    void begin() {
        pinMode(pin,INPUT);
        buttonPressed = 0;
    }
    void update() {
        if((millis()-lastBtnTime) < debounceDelay) {
            debounced = 1;
            return;
        }

        btnState = digitalRead(pin);

        if(lastBtnState == 0 && btnState == 1) {
            if(!debounced) {
                lastBtnTime = millis();
                return;
            }
            state = 4; // rising edge
            debounced = 0;
            lastBtnState = btnState;
        }
        else if (lastBtnState == 0 && btnState == 0) {
            if((millis()-lastBtnTime)>holdThreshold && buttonPressed == 0) {
                state = 3;
                buttonPressed = 1;
            }
            else {
                state = 2;
            }
            lastBtnState = btnState; 
        }
        else if (lastBtnState == 1 && btnState == 0) {
            if(!debounced) {
                lastBtnTime = millis();
                return;
            }
            state = 1; // rising edge
            debounced = 0;
            lastBtnState = btnState;
        }
        else {
            state = 0;
            buttonPressed = 0;
        }
    }

    /*
    void update(){
        btnState = digitalRead(pin);

        if(btnState == lastBtnState) {
            lastBtnTime = millis();
        }

        if(btnState == 0 && lastBtnState == 1) {
        lastBtnTime = millis();
        lastBtnState = btnState;
        buttonPressed = true;
        state = 1;
        }

        else if(buttonPressed == true && (millis()-lastBtnTime) > holdThreshold) {
        buttonPressed = false;
        state = -1;
        }

        else if(buttonPressed == true && btnState == 1){
        lastBtnState = btnState;
        buttonPressed = false;
        state = 0;
        }

        lastBtnState = btnState;
        return 0;
    }*/

    /*
    void update(){
      reading = digitalRead(pin);
      currentTime = millis();

      // Debounce
      if (reading != lastReading) {
          lastDebounceTime = currentTime;
      }

      if ((currentTime - lastDebounceTime) > debounceDelay) {
          if (reading == HIGH && lastReading == LOW) {
              // Button just pressed
              pressStartTime = currentTime;
              state = 0;  // Will determine type after release or hold
          }

          if (reading == HIGH && (currentTime - pressStartTime) > holdThreshold) {
              state = 1;
          }

          if (reading == LOW && lastReading == HIGH) {
              // Button just released
              if ((currentTime - pressStartTime) < holdThreshold) {
                  state = 2;
              }
          }
      }

      lastReading = reading;
    }*/

    int getState() {
      currentState = state;
      //state = 0;  // Reset after reading
      return currentState;
    }
};

#endif
