#include "config.h"
#include "systemManager.h"

SystemManager sys;


/*
bool i = 0;
ISR(TIMER2_COMPA_vect)
{
  OCR2A += 25000; // Advance The COMPA Register
  // Handle The Timer Interrupt
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}*/

void setup() {
    Serial.begin(9600);
    Serial.end();
    sys.begin();
    Serial.println("2DoF Controller Ready. Type 'home' or 'move z 200 1'");
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
/*
  TCCR2A = 0;           // Init Timer1A
  TCCR2B = 0;           // Init Timer1B
  TCCR2B |= B00000011;  // Prescaler = 64
  OCR2A = 25000;        // Timer Compare1A Register
  TIMSK2 |= B00000010;  // Enable Timer COMPA Interrupt
  pinMode(LED_BUILTIN, OUTPUT);*/
}

void loop() {

  //sys.testEncoder();
  sys.testManual();
  //sys.testMotor();
  Serial.println();
}
