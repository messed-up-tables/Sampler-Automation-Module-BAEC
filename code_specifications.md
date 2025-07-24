# Goal
The 2DoF device is used to position the toolhead at specific positions. One axis is linear vertical Z-axis, another one is rotatinal R-axis. The device can be programmed to follow specific set-points, or can be manually controlled. The control can be done by two ways, one is via serial communication, another one is via a user interface. The user interface is a display and a rotary encoder with a switch. 

# Hardware Setup
- Microcontroller: Arduino Nano
- Z-axis motor: NEMA 17 
- R-axis motor: NEMA 14
- Motor driver (both): A4988
- Power Supply: AC to 12V SMPS
- DC-DC Buck Module: XL4015 12V to 5V
- Rotary encoder with button
- OLED display with SSD1306
- Limit switches

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



# Workflow
```mermaid
  graph TD;
      A-->B;
      A-->C;
      B-->D;
      C-->D;
``` 