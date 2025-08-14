#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include "axis.h"
#include "config.h"
#include "rotaryEncoder.h"
#include "buttonManager.h"
#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

//U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   // All Boards without Reset of the Display


class SystemManager {
private:
    Axis zAxis;
    Axis rAxis;
    rotaryEncoder rEnc;
    Button up,dwn,sel;
    U8G2_SSD1306_128X64_NONAME_F_SW_I2C disp;
    int rPos;
    int state;
    bool stateChange = 1;

public:
    SystemManager()
        : zAxis(Z_DIR_PIN, Z_STEP_PIN, Z_EN_PIN, Z_LIMIT_PIN),
          rAxis(R_DIR_PIN, R_STEP_PIN, R_EN_PIN, R_LIMIT_PIN),
          rEnc(ENC_CLK, ENC_DT,ENC_SW),
          up(BTN_A),
          dwn(BTN_C),
          sel(BTN_B),
          disp(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE) {}

    void begin() {
        zAxis.begin();
        rAxis.begin();
        rEnc.begin();
        state = 0;
        rAxis.setMultiplier(5);
        zAxis.setMultiplier(20);
        up.begin();
        dwn.begin();
        sel.begin();
        disp.begin();


    }

    void update() {
        up.update();
        dwn.update();
        sel.update();
        zAxis.moveToTarget();
        rAxis.moveToTarget();
        switch(state) {
            case 0: // manual, r-axis
            manual_mode_raxis();
            break;

            case 1:
            manual_mode_zaxis();
            break;

            case 2:
            menu();
            break;
        }

    }

    int manual_mode_raxis() { // state = 0
        if(sel.getState() == 3) { //state change
            state = 2;
        }
        else if(sel.getState()==4) { // toggle to z axis
            state = 1;
            Serial.println("manual mode z-axis");
            disp.clearBuffer();					// clear the internal memory
            //disp.setFont(u8g2_font_ncenB08_tr);	// choose a suitable font
            //disp.drawStr(0,10,"z axis");	// write something to the internal memory
            disp.setFont(u8g2_font_open_iconic_arrow_4x_t);	// choose a suitable font
            disp.drawStr(0,40,"PS");
            disp.sendBuffer();           
        }
        else if(up.getState() == 2) {
            Serial.println("r ++");
            rAxis.updateTargetInc();
            //rAxis.moveToTarget();
        }
        else if(dwn.getState() == 2) {
            Serial.println("r --");
            rAxis.updateTargetDec();
            //rAxis.moveToTarget();
        }

        
        
    }

    int manual_mode_zaxis() { // state = 1
        if(sel.getState() == 3) { //state change
            state = 2;
            stateChange = 1;
        }
        else if(sel.getState()==4) { // toggle to r axis
            state = 0;
            Serial.println("manual mode r-axis");
            disp.clearBuffer();					// clear the internal memory
            //disp.setFont(u8g2_font_ncenB08_tr);	// choose a suitable font
            //disp.drawStr(0,10,"r axis");	// write something to the internal memory
            disp.setFont(u8g2_font_open_iconic_arrow_4x_t);	// choose a suitable font
            disp.drawStr(0,40,"QR");
            disp.sendBuffer();
        }
        else if(up.getState() == 2) {
            Serial.println("z ++");
            zAxis.updateTargetInc();
            //zAxis.moveToTarget();
        }
        else if(dwn.getState() == 2) {
            Serial.println("z --");
            zAxis.updateTargetDec();
            //zAxis.moveToTarget();
        }
        
    }

    int menu() {
        if(stateChange) {
            disp.clearBuffer();					// clear the internal memory
            disp.setFont(u8g2_font_ncenB08_tr);	// choose a suitable font
            //disp.drawStr(0,10,"r axis");	// write something to the internal memory
            //disp.setFont(u8g2_font_open_iconic_arrow_4x_t);	// choose a suitable font
            disp.drawStr(0,40,"MENU");
            disp.sendBuffer();
            stateChange = 0;
        }
        if(sel.getState() == 3) { //state change
            state = 0;
            stateChange = 1;
        }
    }

    void testButton() {
        up.update();
        dwn.update();
        sel.update();
        Serial.print(up.getState());
        Serial.print(" ");
        Serial.print(dwn.getState());
        Serial.print(" ");
        Serial.print(sel.getState());
        Serial.println();
        //Serial.println(buttTest.getState());
        /*{
            case 2:
            Serial.println("pressed ");
            break;
            case 1:
            Serial.println("hold  ");
            break;
        }*/
    }

    void testManual() {
        if(rEnc.readButton() == 1) {
            state = !state;
            Serial.print("Machine state: ");
            Serial.print(state);
        }

        switch(state) {
        case 0: 
            Serial.print("  R-axis, target: ");
            rAxis.updateTarget(rEnc.readRotation());
            rAxis.moveToTarget();
            Serial.print(rAxis.getTarget());
            break;

        case 1:
            Serial.print("  Z-axis, target: ");
            zAxis.updateTarget(rEnc.readRotation());
            zAxis.moveToTarget();
            Serial.print(zAxis.getTarget());
            break;
        }
    }

    void testEncoder() {
        //Serial.print(rEnc.readButton());
        
        rAxis.updateTarget(rEnc.readRotation());
        Serial.print(rAxis.getTarget());
        rAxis.moveToTarget();
        
        //rEnc.debug();
    }
    void testMotor() {
        /*
        rAxis.moveTo(500);
        rAxis.moveTo(0);
        */
        if(millis() < 5000) {
            rAxis.moveTo(500);
            zAxis.moveTo(200);
        }
        
        else {
            rAxis.moveTo(0);
            zAxis.moveTo(0);
        }
    }


};

#endif
