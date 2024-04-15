#ifndef STRUCTURE_HEADER
#define STRUCTURE_HEADER

#include <Arduino.h>

#include "ESP32-BLE-Keyboard/BleKeyboard.h"
#include "scanner/KeyScanner.h"
#include "keycode/keyCode.h"
#include "config.h"

typedef CustomKey Layer[COLUMNS][ROWS];
enum rgbEffect{
  BOUNCE,
  WAVE,
  WAVE1,
  PLASMA, // TODO
  RAINBOW,
  LED_OFF
};

#endif