// #include <BleKeyboard.h>
#include <Arduino.h>
#include <FastLED.h>
#include <BleKeyboard.h>

#include "modules/rgbHandle_.h"
#include "scanner/KeyScanner.h"
#include "keycode/keyCode.h"

// COLUMNS
uint8_t columnPins[COLUMNS] = { GPIO_NUM_19, GPIO_NUM_18, GPIO_NUM_5, GPIO_NUM_17, GPIO_NUM_16, GPIO_NUM_4};
// ROWS
uint8_t rowPins[ROWS] = { GPIO_NUM_36, GPIO_NUM_39, GPIO_NUM_34, GPIO_NUM_35, GPIO_NUM_32, GPIO_NUM_33, GPIO_NUM_25, GPIO_NUM_26, GPIO_NUM_27, GPIO_NUM_14, GPIO_NUM_12, GPIO_NUM_13, GPIO_NUM_23, GPIO_NUM_22, GPIO_NUM_21};

// keyMap
Layer keyMap[2] = {
  {
    {     KC::ESC    ,     KC::F1    ,     KC::F2    ,     KC::F3    ,     KC::F4    ,     KC::F5    ,     KC::F6    ,     KC::F7    ,     KC::F8    ,     KC::F9    ,    KC::F10    ,    KC::F11    ,    KC::F12    ,   KC::SYSRQ   , KC::SCROLLLOCK },
    {  KC::HASHTILDE ,     KC::N1    ,     KC::N2    ,     KC::N3    ,     KC::N4    ,     KC::N5    ,     KC::N6    ,     KC::N7    ,     KC::N8    ,     KC::N9    ,     KC::N0    ,   KC::MINUS   ,   KC::EQUAL   , KC::BACKSPACE ,   KC::INSERT   },
    {     KC::TAB    ,     KC::Q     ,     KC::W     ,     KC::E     ,     KC::R     ,     KC::T     ,     KC::Y     ,     KC::U     ,     KC::I     ,     KC::O     ,     KC::P     ,   KC::LBRACE  ,   KC::RBRACE  , KC::BACKSLASH ,   KC::DELETE   },
    {   KC::CAPSLOCK ,     KC::A     ,     KC::S     ,     KC::D     ,     KC::F     ,     KC::G     ,     KC::H     ,     KC::J     ,     KC::K     ,     KC::L     ,    KC::SCLN   ,    KC::QUOT   ,   KC::ENTER   ,  KC::PAGEDOWN ,    KC::NONE    },
    {    KC::LSHIFT  ,     KC::Z     ,     KC::X     ,     KC::C     ,     KC::V     ,     KC::B     ,     KC::N     ,     KC::M     ,   KC::COMMA   ,    KC::DOT    ,   KC::SLASH   ,   KC::RSHIFT  ,    KC::END    ,   KC::PAGEUP  ,    KC::NONE    },
    {    KC::LCTRL   ,    KC::LGUI   ,    KC::LALT   ,   KC::SPACE   ,    KC::RALT   ,   KC::LM(1)   ,   KC::PROPS   ,   KC::RCTRL   ,    KC::LEFT   ,    KC::DOWN   ,   KC::RIGHT   ,     KC::UP    ,    KC::HOME   ,   KC::PAUSE   ,    KC::NONE    }
  },
  {
    {     KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE    },
    {     KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE    },
    {     KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE    },
    {     KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE    },
    {     KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE    },
    {     KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,   KC::LM(0)   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE    }
  }
};

Layer *currLayer = &keyMap[0];
BleKeyboard bleKeyboard;
MatrixKeyPad matrixKeyPad = MatrixKeyPad(columnPins, rowPins, COLUMNS, ROWS);
// rgb handel
CRGB leds[NUM_PIXELS] = {0};
RgbHandle rgbHandle = RgbHandle(leds, NUM_PIXELS);

void eventListener(KeyEvent event)
{
  Serial.printf("Key Pad Update %u:%u -> %d\n\r", event.row, event.colume, event.pess);
  // if (!bleKeyboard.isConnected())
  //   return;
  CustomKey key = (*currLayer)[event.colume][event.row];
  if (key.arg == NULL) {
    Serial.println("|-- key none");
    return;
  }
  switch (key.type)
  {
  case KeyType::KEYBOARD_KEY:
    Serial.printf("|-- send KEYBOARD_KEY key: %d \n\r", *((uint8_t *)key.arg));
    if (event.pess)
      bleKeyboard.press(*((uint8_t *)key.arg));
    else
      bleKeyboard.release(*((uint8_t *)key.arg));
    break;

  case KeyType::MEDIA_KEY:
    Serial.printf("|-- send MEDIA key: %d %d \n\r", *(uint16_t *)key.arg);
    if (event.pess)
      bleKeyboard.press((uint8_t *)key.arg);
    else
      bleKeyboard.release((uint8_t *)key.arg);
    break;

  case KeyType::LAYER_KEY:
    LayerData *data = (LayerData *)key.arg;
    currLayer = &keyMap[data->indexLayer];
    Serial.println("|-- change layer");
    break;
  }
}

void setup()
{
  Serial.begin(115200);
  bleKeyboard.setName(KEYBOARD_NAME);
  bleKeyboard.begin();
  matrixKeyPad.addEventListener(eventListener);
  FastLED.addLeds<WS2812, PIN_WS2812>(leds, NUM_PIXELS);
  delay(1000);
  Serial.println("Keyboard start");
}

void loop()
{
  matrixKeyPad.update();
  rgbHandle.update();
}
