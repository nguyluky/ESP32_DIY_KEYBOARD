
#ifndef LAYER_HEADER
#define LAYER_HEADER

#include <Arduino.h>
#include "keyCode.h"

enum KEY_MODE: bool {
  TOGGLE,
  PRESS
};
struct LayerData
{

  KEY_MODE mode;
  uint8_t indexLayer;
  LayerData(KEY_MODE _mode, uint8_t index): mode(_mode), indexLayer(index) {};
};
#endif