void homeAll() {
  showStatus("Homing motors...");
  unsigned long startTime = millis();

  while (digitalRead(LIMIT_1) && millis() - startTime < maxHomeTime) {
    moveMotor(M1_DIR_PIN, M1_STEP_PIN, 1, false);
  }

  while (digitalRead(LIMIT_2) && millis() - startTime < maxHomeTime) {
    moveMotor(M2_DIR_PIN, M2_STEP_PIN, 1, false);
  }

  if (digitalRead(LIMIT_1) || digitalRead(LIMIT_2)) {
    stopAll();
    showStatus("Homing Failed");
  } else {
    homingDone = true;
    showStatus("Homing Done");
  }
}