void autoRoutine() {
  showStatus("Running Auto Mode");
  // Sample sequence
  moveMotor(M1_DIR_PIN, M1_STEP_PIN, stepCount_10mm, true);
  delay(500);
  moveMotor(M2_DIR_PIN, M2_STEP_PIN, stepCount_10mm, true);
  delay(500);
  moveMotor(M1_DIR_PIN, M1_STEP_PIN, stepCount_10mm, false);
  delay(500);
  moveMotor(M2_DIR_PIN, M2_STEP_PIN, stepCount_10mm, false);
  delay(500);
  showStatus("Auto Done");
}