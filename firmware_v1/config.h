#ifndef CONFIG_H
#define CONFIG_H

// Z-Axis Motor
const int Z_DIR_PIN    = 2;
const int Z_STEP_PIN   = 3;
const int Z_EN_PIN     = 4;
const int Z_LIMIT_PIN  = A6;

// R-Axis Motor
const int R_DIR_PIN    = 5;
const int R_STEP_PIN   = 6;
const int R_EN_PIN     = 7;
const int R_LIMIT_PIN  = A7;

// Interface
const int BTN_A = A1;
const int BTN_B = A2;
const int BTN_C = A3;


// Rotary encoder
const int ENC_CLK = A3;
const int ENC_DT = A2;
const int ENC_SW = A1;


// General
const int STEP_DELAY_MICROS = 1000;  // controls speed (1000us = ~500 steps/sec)

#endif
