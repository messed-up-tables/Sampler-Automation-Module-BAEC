// === Project: Stepper Motor UI with Limit Switch and RGB LED ===
// === Using Object-Oriented Programming ===

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <AccelStepper.h>

// === OLED Setup ===
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// === Motor Driver Pins ===
#define MOTOR1_STEP_PIN 6
#define MOTOR1_DIR_PIN  5
#define MOTOR2_STEP_PIN 8
#define MOTOR2_DIR_PIN  7

// === Limit Switch Pins ===
#define LIMIT1_PIN 12
#define LIMIT2_PIN 13

// === RGB LED Pins ===
#define LED_R_PIN 9
#define LED_G_PIN 10
#define LED_B_PIN 11

// === Homing Time Limit ===
const unsigned long MAX_HOME_TIME = 5000;

// === Step Sizes ===
int stepSize = 1; // 1 = 1mm, 5 = 5mm, etc.




void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    handleCommand(command);
  }
  motor1.run();
  motor2.run();
}


