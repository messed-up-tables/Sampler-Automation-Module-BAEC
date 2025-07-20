void showMenu() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Stepper Control");
  display.println("[a] Auto Mode");
  display.println("[m] Manual Mode");
  display.println("[s] Stop All");
  display.println("[1/5/0] Step mm");
  display.display();
}

void showStatus(const char* msg) {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(msg);
  display.display();
}