#ifndef HID_KEY
#define HID_KEY

#include <Arduino.h>

const uint8_t KEY_NONE = 0x00; // No key pressed
const uint8_t KEY_ERR_OVF = 0x01; //  Keyboard Error Roll Over - used for all slots if too many keys are pressed ("Phantom key")

const uint8_t KEY_A = 0x04; // Keyboard a and A
const uint8_t KEY_B = 0x05; // Keyboard b and B
const uint8_t KEY_C = 0x06; // Keyboard c and C
const uint8_t KEY_D = 0x07; // Keyboard d and D
const uint8_t KEY_E = 0x08; // Keyboard e and E
const uint8_t KEY_F = 0x09; // Keyboard f and F
const uint8_t KEY_G = 0x0a; // Keyboard g and G
const uint8_t KEY_H = 0x0b; // Keyboard h and H
const uint8_t KEY_I = 0x0c; // Keyboard i and I
const uint8_t KEY_J = 0x0d; // Keyboard j and J
const uint8_t KEY_K = 0x0e; // Keyboard k and K
const uint8_t KEY_L = 0x0f; // Keyboard l and L
const uint8_t KEY_M = 0x10; // Keyboard m and M
const uint8_t KEY_N = 0x11; // Keyboard n and N
const uint8_t KEY_O = 0x12; // Keyboard o and O
const uint8_t KEY_P = 0x13; // Keyboard p and P
const uint8_t KEY_Q = 0x14; // Keyboard q and Q
const uint8_t KEY_R = 0x15; // Keyboard r and R
const uint8_t KEY_S = 0x16; // Keyboard s and S
const uint8_t KEY_T = 0x17; // Keyboard t and T
const uint8_t KEY_U = 0x18; // Keyboard u and U
const uint8_t KEY_V = 0x19; // Keyboard v and V
const uint8_t KEY_W = 0x1a; // Keyboard w and W
const uint8_t KEY_X = 0x1b; // Keyboard x and X
const uint8_t KEY_Y = 0x1c; // Keyboard y and Y
const uint8_t KEY_Z = 0x1d; // Keyboard z and Z
const uint8_t KEY_1 = 0x1e; // Keyboard 1 and !
const uint8_t KEY_2 = 0x1f; // Keyboard 2 and @
const uint8_t KEY_3 = 0x20; // Keyboard 3 and #
const uint8_t KEY_4 = 0x21; // Keyboard 4 and $
const uint8_t KEY_5 = 0x22; // Keyboard 5 and %
const uint8_t KEY_6 = 0x23; // Keyboard 6 and ^
const uint8_t KEY_7 = 0x24; // Keyboard 7 and &
const uint8_t KEY_8 = 0x25; // Keyboard 8 and *
const uint8_t KEY_9 = 0x26; // Keyboard 9 and (
const uint8_t KEY_0 = 0x27; // Keyboard 0 and )
const uint8_t KEY_ENTER = 0x28; // Keyboard Return (ENTER)
const uint8_t KEY_ESC = 0x29; // Keyboard ESCAPE
const uint8_t KEY_BACKSPACE = 0x2a; // Keyboard DELETE (Backspace)
const uint8_t KEY_TAB = 0x2b; // Keyboard Tab
const uint8_t KEY_SPACE = 0x2c; // Keyboard Spacebar
const uint8_t KEY_MINUS = 0x2d; // Keyboard - and _
const uint8_t KEY_EQUAL = 0x2e; // Keyboard = and +
const uint8_t KEY_LEFTBRACE = 0x2f; // Keyboard [ and {
const uint8_t KEY_RIGHTBRACE = 0x30; // Keyboard ] and }
const uint8_t KEY_BACKSLASH = 0x31; // Keyboard \ and |
const uint8_t KEY_HASHTILDE = 0x32; // Keyboard Non-US # and ~
const uint8_t KEY_SEMICOLON = 0x33; // Keyboard ; and :
const uint8_t KEY_APOSTROPHE = 0x34; // Keyboard ' and "
const uint8_t KEY_GRAVE = 0x35; // Keyboard ` and ~
const uint8_t KEY_COMMA = 0x36; // Keyboard , and <
const uint8_t KEY_DOT = 0x37; // Keyboard . and >
const uint8_t KEY_SLASH = 0x38; // Keyboard / and ?
const uint8_t KEY_CAPSLOCK = 0x39; // Keyboard Caps Lock

const uint8_t KEY_F1 = 0x3a; // Keyboard F1
const uint8_t KEY_F2 = 0x3b; // Keyboard F2
const uint8_t KEY_F3 = 0x3c; // Keyboard F3
const uint8_t KEY_F4 = 0x3d; // Keyboard F4
const uint8_t KEY_F5 = 0x3e; // Keyboard F5
const uint8_t KEY_F6 = 0x3f; // Keyboard F6
const uint8_t KEY_F7 = 0x40; // Keyboard F7
const uint8_t KEY_F8 = 0x41; // Keyboard F8
const uint8_t KEY_F9 = 0x42; // Keyboard F9
const uint8_t KEY_F10 = 0x43; // Keyboard F10
const uint8_t KEY_F11 = 0x44; // Keyboard F11
const uint8_t KEY_F12 = 0x45; // Keyboard F12

const uint8_t KEY_SYSRQ = 0x46; // Keyboard Print Screen
const uint8_t KEY_SCROLLLOCK = 0x47; // Keyboard Scroll Lock
const uint8_t KEY_PAUSE = 0x48; // Keyboard Pause
const uint8_t KEY_INSERT = 0x49; // Keyboard Insert
const uint8_t KEY_HOME = 0x4a; // Keyboard Home
const uint8_t KEY_PAGEUP = 0x4b; // Keyboard Page Up
const uint8_t KEY_DELETE = 0x4c; // Keyboard Delete Forward
const uint8_t KEY_END = 0x4d; // Keyboard End
const uint8_t KEY_PAGEDOWN = 0x4e; // Keyboard Page Down
const uint8_t KEY_RIGHT = 0x4f; // Keyboard Right Arrow
const uint8_t KEY_LEFT = 0x50; // Keyboard Left Arrow
const uint8_t KEY_DOWN = 0x51; // Keyboard Down Arrow
const uint8_t KEY_UP = 0x52; // Keyboard Up Arrow

const uint8_t KEY_NUMLOCK = 0x53; // Keyboard Num Lock and Clear
const uint8_t KEY_KPSLASH = 0x54; // Keypad /
const uint8_t KEY_KPASTERISK = 0x55; // Keypad *
const uint8_t KEY_KPMINUS = 0x56; // Keypad -
const uint8_t KEY_KPPLUS = 0x57; // Keypad +
const uint8_t KEY_KPENTER = 0x58; // Keypad ENTER
const uint8_t KEY_KP1 = 0x59; // Keypad 1 and End
const uint8_t KEY_KP2 = 0x5a; // Keypad 2 and Down Arrow
const uint8_t KEY_KP3 = 0x5b; // Keypad 3 and PageDn
const uint8_t KEY_KP4 = 0x5c; // Keypad 4 and Left Arrow
const uint8_t KEY_KP5 = 0x5d; // Keypad 5
const uint8_t KEY_KP6 = 0x5e; // Keypad 6 and Right Arrow
const uint8_t KEY_KP7 = 0x5f; // Keypad 7 and Home
const uint8_t KEY_KP8 = 0x60; // Keypad 8 and Up Arrow
const uint8_t KEY_KP9 = 0x61; // Keypad 9 and Page Up
const uint8_t KEY_KP0 = 0x62; // Keypad 0 and Insert
const uint8_t KEY_KPDOT = 0x63; // Keypad . and Delete

const uint8_t KEY_102ND = 0x64; // Keyboard Non-US \ and |
const uint8_t KEY_COMPOSE = 0x65; // Keyboard Application
const uint8_t KEY_POWER = 0x66; // Keyboard Power
const uint8_t KEY_KPEQUAL = 0x67; // Keypad =

const uint8_t KEY_F13 = 0x68; // Keyboard F13
const uint8_t KEY_F14 = 0x69; // Keyboard F14
const uint8_t KEY_F15 = 0x6a; // Keyboard F15
const uint8_t KEY_F16 = 0x6b; // Keyboard F16
const uint8_t KEY_F17 = 0x6c; // Keyboard F17
const uint8_t KEY_F18 = 0x6d; // Keyboard F18
const uint8_t KEY_F19 = 0x6e; // Keyboard F19
const uint8_t KEY_F20 = 0x6f; // Keyboard F20
const uint8_t KEY_F21 = 0x70; // Keyboard F21
const uint8_t KEY_F22 = 0x71; // Keyboard F22
const uint8_t KEY_F23 = 0x72; // Keyboard F23
const uint8_t KEY_F24 = 0x73; // Keyboard F24

const uint8_t KEY_OPEN = 0x74; // Keyboard Execute
const uint8_t KEY_HELP = 0x75; // Keyboard Help
const uint8_t KEY_PROPS = 0x76; // Keyboard Menu
const uint8_t KEY_FRONT = 0x77; // Keyboard Select
const uint8_t KEY_STOP = 0x78; // Keyboard Stop
const uint8_t KEY_AGAIN = 0x79; // Keyboard Again
const uint8_t KEY_UNDO = 0x7a; // Keyboard Undo
const uint8_t KEY_CUT = 0x7b; // Keyboard Cut
const uint8_t KEY_COPY = 0x7c; // Keyboard Copy
const uint8_t KEY_PASTE = 0x7d; // Keyboard Paste
const uint8_t KEY_FIND = 0x7e; // Keyboard Find
const uint8_t KEY_MUTE = 0x7f; // Keyboard Mute
const uint8_t KEY_VOLUMEUP = 0x80; // Keyboard Volume Up
const uint8_t KEY_VOLUMEDOWN = 0x81; // Keyboard Volume Down

const uint8_t KEY_KPCOMMA = 0x85; // Keypad Comma

const uint8_t KEY_RO = 0x87; // Keyboard International1
const uint8_t KEY_KATAKANAHIRAGANA = 0x88; // Keyboard International2
const uint8_t KEY_YEN = 0x89; // Keyboard International3
const uint8_t KEY_HENKAN = 0x8a; // Keyboard International4
const uint8_t KEY_MUHENKAN = 0x8b; // Keyboard International5
const uint8_t KEY_KPJPCOMMA = 0x8c; // Keyboard International6

const uint8_t KEY_HANGEUL = 0x90; // Keyboard LANG1
const uint8_t KEY_HANJA = 0x91; // Keyboard LANG2
const uint8_t KEY_KATAKANA = 0x92; // Keyboard LANG3
const uint8_t KEY_HIRAGANA = 0x93; // Keyboard LANG4
const uint8_t KEY_ZENKAKUHANKAKU = 0x94; // Keyboard LANG5 

const uint8_t KEY_KPLEFTPAREN = 0xb6; // Keypad (
const uint8_t KEY_KPRIGHTPAREN = 0xb7; // Keypad )

const uint8_t KEY_LEFTCTRL = 0xe0; // Keyboard Left Control
const uint8_t KEY_LEFTSHIFT = 0xe1; // Keyboard Left Shift
const uint8_t KEY_LEFTALT = 0xe2; // Keyboard Left Alt
const uint8_t KEY_LEFTMETA = 0xe3; // Keyboard Left GUI
const uint8_t KEY_RIGHTCTRL = 0xe4; // Keyboard Right Control
const uint8_t KEY_RIGHTSHIFT = 0xe5; // Keyboard Right Shift
const uint8_t KEY_RIGHTALT = 0xe6; // Keyboard Right Alt
const uint8_t KEY_RIGHTMETA = 0xe7; // Keyboard Right GUI

#endif