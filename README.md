| Command       | Action                     |
| ------------- | -------------------------- |
| `home`        | Start homing               |
| `manual`      | Enter manual movement mode |
| `step 1`      | Set step size to 1 mm      |
| `step 5`      | Set step size to 5 mm      |
| `step 10`     | Set step size to 10 mm     |
| `led on/off`  | Turn RGB LED on/off        |
| `color r/g/b` | Change LED color           |
--------------------------------------------------------------------
| Pin   | Connection                 |
| ----- | -------------------------- |
| `D2`  | — (was rotary encoder SW)  |
| `D3`  | — (was rotary encoder DT)  |
| `D4`  | — (was rotary encoder CLK) |
| `D5`  | Motor1 DIR                 |
| `D6`  | Motor1 STEP                |
| `D7`  | Motor2 DIR                 |
| `D8`  | Motor2 STEP                |
| `D9`  | RGB LED (Red)              |
| `D10` | RGB LED (Green)            |
| `D11` | RGB LED (Blue)             |
| `D12` | Limit Switch 1             |
| `D13` | Limit Switch 2             |
| `A4`  | OLED SDA                   |
| `A5`  | OLED SCL                   |
-----------------------------------------------------------
🔧 Object-Oriented Code: Classes for motors and limit switches

🖥️ OLED User Interface: Menu-driven display using Adafruit library

🎛️ Manual Control: Move motors in user-defined step sizes (1mm, 5mm, 10mm)

🤖 Auto Homing: Both motors home to zero using limit switches

💡 RGB LED: Visual feedback for state or mode

🧠 Serial Control: Accepts commands via Serial Monitor

🚨 Safety Timeout: Max home time to prevent motor stall
