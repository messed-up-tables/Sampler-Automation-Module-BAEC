#include "motorController.h"
#include "config.h"



motorController rMotor(R_DIR_PIN, R_STEP_PIN, R_EN_PIN);

void initialize() {
  rMotor.begin();
  rMotor.dir(1);
  rMotor.enable();
}

void test1() {
  digitalWrite(R_DIR_PIN,HIGH);
  rMotor.step();
}


