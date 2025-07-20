LimitSwitch limit1(LIMIT1_PIN);
LimitSwitch limit2(LIMIT2_PIN);
Motor motor1(MOTOR1_DIR_PIN, MOTOR1_STEP_PIN, &limit1);
Motor motor2(MOTOR2_DIR_PIN, MOTOR2_STEP_PIN, &limit2);

// === Setup ===
void setup() {
  Serial.begin(9600);
  pinMode(LED_R_PIN, OUTPUT);
  pinMode(LED_G_PIN, OUTPUT);
  pinMode(LED_B_PIN, OUTPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  display.display();

  showMenu();
}