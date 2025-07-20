class Motor {
public:
  AccelStepper stepper;
  LimitSwitch* limitSwitch;
  Motor(int dirPin, int stepPin, LimitSwitch* limitSw)
    : stepper(AccelStepper::DRIVER, stepPin, dirPin), limitSwitch(limitSw) {
    stepper.setMaxSpeed(1000);
    stepper.setAcceleration(500);
  }
  void move(int steps) { stepper.move(steps); }
  void run() { stepper.run(); }
  void stop() { stepper.stop(); }
  void home() {
    unsigned long start = millis();
    stepper.setSpeed(-200);
    while (!limitSwitch->isPressed()) {
      stepper.runSpeed();
      if (millis() - start > MAX_HOME_TIME) {
        stop();
        Serial.println("Error: Homing timeout!");
        return;
      }
    }
    stepper.setCurrentPosition(0);
  }
};