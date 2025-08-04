# Goal
The 2DoF device is used to position the toolhead at specific positions. One axis is linear vertical Z-axis, another one is rotatinal R-axis. The device can be programmed to follow specific set-points, or can be manually controlled. The control can be done by two ways, one is via serial communication, another one is via a user interface. The user interface is a display and a rotary encoder with a switch. 

## Hardware Setup
- Microcontroller: Arduino Nano
- Z-axis motor: NEMA 17 
- R-axis motor: NEMA 14
- Motor driver (both): A4988
- Power Supply: AC to 12V SMPS
- DC-DC Buck Module: XL4015 12V to 5V
- Rotary encoder with button 
- OLED display with SSD1306
- Limit switches (debouncing circuit with 10ms debounce)

## Coding Style
- Arduino IDE 
- Object Oriented, Modular, Reusable
- Implementation requirements
  - State machine : idle, moving, homing, manual input, program_run
  - constant velocity movements
- Reduce Library usage
- short comments for organizing
- use const int for pins and parameters
- Code without the display for now.
---

- main 
  -  systemManager
    - axis
      - motor
    - uiManager
      - serialManager
      - display
      - rotaryEncoder

---
- class: motorController
  - parameters
    - dirPin
    - stepPin
    - enPin
  - functions
    - constructor()
    - begin()
    - enable()
    - disable()
    - dir()
    - step()
- class : axis
  - parameters
    - targetPos
    - currentPos
    - limitSwPin
    - isHomed
  - functions
    - constructor()
    - begin()
    - home()
    - move()
    - moveDelta() //not sure about the name
- class : rotaryEncoder
  - parameters
    - clkPin
    - dtPin
    - swPin
    - lastClkState
    - lastBtnState
    - buttonPressed
    - lastBtnTime
  - functions
    - begin()
    - readRotation()
    - readButton()
- class : serialManager
  - parameters
    - command
    - value
    - message
  - functions
    - begin()
    - available()
    - processCommand()
    - readCommand()
    - readValue()
    - printMessage()
    - printText()

# Wiring

| Arduino Pins | Z - Axis Motor Driver Pins |
| --- | -------------------------- |
| D2 | DIR  |
| D3 | STEP |
| D4 | ENABLE |
---
| Arduino Pins | R - Axis Motor Driver Pins |
| --- | -------------------------- |
| D5 | DIR  |
| D6 | STEP |
| D7 | ENABLE |
---
| Arduino Pins | LED Pins |
| --- | -------------------------- |
| D9  | R |
| D10 | G |
| D11 | B |
---
| Arduino Pins | Rotary Encoder Pins |
| --- | -------------------------- |
| A1 | SW  |
| A2 | DT  |
| A3 | CLK |
---
| Arduino Pins | Display Pins |
| --- | -------------------------- |
| A4 | SDA |
| A5 | SCL |
---
| Arduino Pins | Limit Switch Pins |
| --- | -------------------------- |
| A6 | SDA |
| A7 | SCL |




