void showMenu() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Motor Control Menu:");
  display.println("auto - Homing");
  display.println("manual x+10, x-10, y+10, y-10");
  display.println("led R,G,B");
  display.display();
}

void handleCommand(String cmd) {
  if (cmd == "auto") {
    motor1.home();
    motor2.home();
    Serial.println("Auto Homing Done.");
  } else if (cmd.startsWith("x+")) {
    int val = cmd.substring(2).toInt();
    motor1.move(val * stepSize);
  } else if (cmd.startsWith("x-")) {
    int val = cmd.substring(2).toInt();
    motor1.move(-val * stepSize);
  } else if (cmd.startsWith("y+")) {
    int val = cmd.substring(2).toInt();
    motor2.move(val * stepSize);
  } else if (cmd.startsWith("y-")) {
    int val = cmd.substring(2).toInt();
    motor2.move(-val * stepSize);
  } else if (cmd.startsWith("led")) {
    setLEDColor(cmd);
  } else if (cmd.startsWith("step")) {
    stepSize = cmd.substring(4).toInt();
  } else {
    Serial.println("Invalid command.");
  }
  showMenu();
}

void setLEDColor(String cmd) {
  if (cmd == "led R") {
    analogWrite(LED_R_PIN, 255);
    analogWrite(LED_G_PIN, 0);
    analogWrite(LED_B_PIN, 0);
  } else if (cmd == "led G") {
    analogWrite(LED_R_PIN, 0);
    analogWrite(LED_G_PIN, 255);
    analogWrite(LED_B_PIN, 0);
  } else if (cmd == "led B") {
    analogWrite(LED_R_PIN, 0);
    analogWrite(LED_G_PIN, 0);
    analogWrite(LED_B_PIN, 255);
  } else {
    analogWrite(LED_R_PIN, 0);
    analogWrite(LED_G_PIN, 0);
    analogWrite(LED_B_PIN, 0);
  }
}