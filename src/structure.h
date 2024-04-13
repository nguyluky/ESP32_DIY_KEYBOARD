#ifndef STRUCTURE_HEADER
#define STRUCTURE_HEADER

#include "config.h"

enum KeyType {
    MOUSE_KEY,
    KEYBOARD_KEY,
    MEDIA_KEY,
    LAYER_KEY,
    LED_KEY,

};

struct CustomKey
{
    KeyType type;
    void *arg;
};

typedef CustomKey Layer[COLUMNS][ROWS];

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

enum rgbEffect{
  BOUNCE,
  WAVE,
  WAVE1,
  PLASMA, // TODO
  RAINBOW,
  LED_OFF
};

#endif