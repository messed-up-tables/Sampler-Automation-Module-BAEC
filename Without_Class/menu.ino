void manualControl(char dir) {
  showStatus("Manual Mode");

  switch (dir) {
    case 'l': moveMotor(M1_DIR_PIN, M1_STEP_PIN, moveStep, false); break;
    case 'r': moveMotor(M1_DIR_PIN, M1_STEP_PIN, moveStep, true); break;
    case 'u': moveMotor(M2_DIR_PIN, M2_STEP_PIN, moveStep, true); break;
    case 'd': moveMotor(M2_DIR_PIN, M2_STEP_PIN, moveStep, false); break;
  }
}