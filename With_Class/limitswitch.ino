class LimitSwitch {
public:
  int pin;
  LimitSwitch(int p) { pin = p; pinMode(pin, INPUT_PULLUP); }
  bool isPressed() { return digitalRead(pin) == LOW; }
};
