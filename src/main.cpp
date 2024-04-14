// #include <BleKeyboard.h>
// #include <Arduino.h>
// // #include <FastLED.h>

// // #include "modules/rgbHandle_.h"
// #include "scanner/KeyScanner.h"
// #include "keycode/keyCode.h"


// // ================================================================
// //                     ROW AND COLUMN CONFIG
// // ================================================================
// uint8_t columnPins[COLUMNS] = {
//     GPIO_NUM_33,
//     GPIO_NUM_32, 
//     GPIO_NUM_35, 
//     GPIO_NUM_34, 
//     GPIO_NUM_39, 
//     GPIO_NUM_36 
// };
// uint8_t rowPins[ROWS] = {
//     GPIO_NUM_25,
//     GPIO_NUM_26,
//     GPIO_NUM_27,
//     GPIO_NUM_14,
//     GPIO_NUM_12,
//     GPIO_NUM_13,
//     GPIO_NUM_23,
//     GPIO_NUM_22,
//     GPIO_NUM_21,
//     GPIO_NUM_19,
//     GPIO_NUM_18,
//     GPIO_NUM_5,
//     GPIO_NUM_17,
//     GPIO_NUM_16,
//     GPIO_NUM_4
// };


// // ================================================================
// //                              KEYMAP
// // ================================================================
// Layer keyMap[2] = {
//   {
//     {     KC::ESC    ,     KC::F1    ,     KC::F2    ,     KC::F3    ,     KC::F4    ,     KC::F5    ,     KC::F6    ,     KC::F7    ,     KC::F8    ,     KC::F9    ,    KC::F10    ,    KC::F11    ,    KC::F12    ,   KC::SYSRQ   , KC::SCROLLLOCK },
//     {  KC::HASHTILDE ,     KC::N1    ,     KC::N2    ,     KC::N3    ,     KC::N4    ,     KC::N5    ,     KC::N6    ,     KC::N7    ,     KC::N8    ,     KC::N9    ,     KC::N0    ,   KC::MINUS   ,   KC::EQUAL   , KC::BACKSPACE ,   KC::INSERT   },
//     {     KC::TAB    ,     KC::Q     ,     KC::W     ,     KC::E     ,     KC::R     ,     KC::T     ,     KC::Y     ,     KC::U     ,     KC::I     ,     KC::O     ,     KC::P     ,   KC::LBRACE  ,   KC::RBRACE  , KC::BACKSLASH ,   KC::DELETE   },
//     {   KC::CAPSLOCK ,     KC::A     ,     KC::S     ,     KC::D     ,     KC::F     ,     KC::G     ,     KC::H     ,     KC::J     ,     KC::K     ,     KC::L     ,    KC::SCLN   ,    KC::QUOT   ,   KC::ENTER   ,  KC::PAGEDOWN ,    KC::NONE    },
//     {    KC::LSHIFT  ,     KC::Z     ,     KC::X     ,     KC::C     ,     KC::V     ,     KC::B     ,     KC::N     ,     KC::M     ,   KC::COMMA   ,    KC::DOT    ,   KC::SLASH   ,   KC::RSHIFT  ,    KC::END    ,   KC::PAGEUP  ,    KC::NONE    },
//     {    KC::LCTRL   ,    KC::LGUI   ,    KC::LALT   ,   KC::SPACE   ,    KC::RALT   ,   KC::LM(1)   ,   KC::PROPS   ,   KC::RCTRL   ,    KC::LEFT   ,    KC::DOWN   ,   KC::RIGHT   ,     KC::UP    ,    KC::HOME   ,   KC::PAUSE   ,    KC::NONE    }
//   },
//   {
//     {     KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE    },
//     {     KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE    },
//     {     KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE    },
//     {     KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE    },
//     {     KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE    },
//     {     KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::LM(0)  ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE   ,    KC::MVUP   ,    KC::NONE   ,    KC::NONE   ,    KC::NONE    }
//   }
// };

// // ================================================================
// //                           INIT VALUE
// // ================================================================
// Layer *currLayer = &keyMap[0];
// // CRGB leds[NUM_PIXELS] = {0};
// BleKeyboard bleKeyboard;
// MatrixKeyPad matrixKeyPad = MatrixKeyPad(columnPins, rowPins, COLUMNS, ROWS);
// // RgbHandle rgbHandle = RgbHandle(leds, NUM_PIXELS);

// void eventListener(KeyEvent event);

// // ================================================================
// //                              SETUP
// // ================================================================
// void setup()
// {
//     Serial.begin(115200);
//     matrixKeyPad.addEventListener(eventListener);
//     bleKeyboard.begin();
//     delay(1000);
//     Serial.println("keyboard started");
// }

// void loop()
// {
//     // matrixKeyPad.update();

//     // test
//     delay(5000);
//     Serial.println("delay 5s");
//     if (bleKeyboard.isConnected()) {
//       bleKeyboard.press(KEY_A);
//       bleKeyboard.release(KEY_A);
//     }

// }

// // ================================================================
// //                              EVENTLISTENER
// // ================================================================
// void eventListener(KeyEvent event)
// {
//     Serial.printf("Key Pad Update %u:%u -> %d\n\r", event.row, event.colume, event.pess);
//     if (!bleKeyboard.isConnected()) return;
//     CustomKey key = (*currLayer)[event.colume][event.row];
//     if (key.arg == NULL)
//     {
//         Serial.println("|-- key none");
//         return;
//     }
//     switch (key.type)
//     {
//     case KeyType::KEYBOARD_KEY:
//         Serial.printf("|-- send KEYBOARD_KEY key: %d \n\r", *((uint8_t *)key.arg));
//         if (event.pess)
//           bleKeyboard.press(*((uint8_t *)key.arg));
//         else
//           bleKeyboard.release(*((uint8_t *)key.arg));
//         break;

//     case KeyType::MEDIA_KEY:
//         Serial.printf("|-- send MEDIA key: %d %d \n\r", *(uint16_t *)key.arg);
//         if (event.pess)
//           bleKeyboard.press((uint8_t *)key.arg);
//         else
//           bleKeyboard.release((uint8_t *)key.arg);
//         break;

//     case KeyType::LAYER_KEY:
//         LayerData *data = (LayerData *)key.arg;
//         currLayer = &keyMap[data->indexLayer];
//         Serial.println("|-- change layer");
//         break;
//     }
// }
/**
 * This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete
 */
#include <BleKeyboard.h>
#include <Arduino.h>
BleKeyboard bleKeyboard;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
}

void loop() {
  if(bleKeyboard.isConnected()) {
    Serial.println("Sending 'Hello world'...");
    bleKeyboard.print("Hello world");

    delay(1000);

    Serial.println("Sending Enter key...");
    bleKeyboard.write(KEY_RETURN);

    delay(1000);

    Serial.println("Sending Play/Pause media key...");
    bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);

    delay(1000);

    // Serial.println("Sending Ctrl+Alt+Delete...");
    // bleKeyboard.press(KEY_LEFT_CTRL);
    // bleKeyboard.press(KEY_LEFT_ALT);
    // bleKeyboard.press(KEY_DELETE);
    // delay(100);
    // bleKeyboard.releaseAll();
  }

  Serial.println("Waiting 5 seconds...");
  delay(5000);
}
