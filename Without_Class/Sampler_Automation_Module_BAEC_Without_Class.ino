// -----------------------------------------
// Stepper Motor Control System (No Classes)
// -----------------------------------------

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Motor 1 Pins
#define M1_STEP_PIN 6
#define M1_DIR_PIN 5

// Motor 2 Pins
#define M2_STEP_PIN 8
#define M2_DIR_PIN 7

// Limit Switches
#define LIMIT_1 A0
#define LIMIT_2 A1

// RGB LED Pins
#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11

// Movement Parameters (Adjustable)
int stepDelay = 800; // microseconds
int stepCount_1mm = 10;
int stepCount_5mm = 50;
int stepCount_10mm = 100;

int moveStep = stepCount_1mm; // default move step size
unsigned long maxHomeTime = 5000; // milliseconds

// States
bool autoMode = false;
bool manualMode = false;
bool homingDone = false;

void setup() {
  Serial.begin(9600);

  pinMode(M1_STEP_PIN, OUTPUT);
  pinMode(M1_DIR_PIN, OUTPUT);
  pinMode(M2_STEP_PIN, OUTPUT);
  pinMode(M2_DIR_PIN, OUTPUT);

  pinMode(LIMIT_1, INPUT_PULLUP);
  pinMode(LIMIT_2, INPUT_PULLUP);

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  
  showMenu();
  homeAll();
}


void stopAll() {
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
  showStatus("STOPPED");
}

// ----- LOOP -----
void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();

    if (cmd == 'a') {
      autoRoutine();
    } else if (cmd == 'm') {
      manualMode = true;
      showStatus("Manual Mode Ready");
    } else if (cmd == 's') {
      stopAll();
    } else if (cmd == '1') {
      moveStep = stepCount_1mm;
      showStatus("Set 1mm Step");
    } else if (cmd == '5') {
      moveStep = stepCount_5mm;
      showStatus("Set 5mm Step");
    } else if (cmd == '0') {
      moveStep = stepCount_10mm;
      showStatus("Set 10mm Step");
    } else if (manualMode) {
      manualControl(cmd);
    }
  }
}
