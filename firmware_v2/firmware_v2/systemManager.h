#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include "axis.h"
#include "config.h"
#include "rotaryEncoder.h"

class SystemManager {
private:
    Axis zAxis;
    Axis rAxis;
    rotaryEncoder rEnc;
    int rPos;
    int machineState;

public:
    SystemManager()
        : zAxis(Z_DIR_PIN, Z_STEP_PIN, Z_EN_PIN, Z_LIMIT_PIN),
          rAxis(R_DIR_PIN, R_STEP_PIN, R_EN_PIN, R_LIMIT_PIN),
          rEnc(ENC_CLK, ENC_DT,ENC_SW) {}

    void begin() {
        zAxis.begin();
        rAxis.begin();
        rEnc.begin();
        machineState = 0;
        rAxis.setMultiplier(5);
        zAxis.setMultiplier(20);


    }

    void update() {
        //rPos = rPos + rEnc.readRotation();
        //rAxis.moveTo(rPos);

    }

    void testManual() {
        if(rEnc.readButton() == 1) {
            machineState = !machineState;
            Serial.print("Machine state: ");
            Serial.print(machineState);
        }

        switch(machineState) {
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
