#ifndef CUSTOM_KEY_CODE
#define CUSTOM_KEY_CODE

#include <Arduino.h>
#include "useHidKey.h"
#include "../structure.h"

namespace KC
{
    static const CustomKey NONE = {KeyType::KEYBOARD_KEY, NULL}; // No key pressed
    static const CustomKey ERR_OVF = {KeyType::KEYBOARD_KEY, (void*) &KEY_ERR_OVF}; //  Keyboard Error Roll Over - used for all slots if too many keys are pressed ("Phantom key")
    static const CustomKey A = {KeyType::KEYBOARD_KEY, (void*) &KEY_A}; // Keyboard a and A
    static const CustomKey B = {KeyType::KEYBOARD_KEY, (void*) &KEY_B}; // Keyboard b and B
    static const CustomKey C = {KeyType::KEYBOARD_KEY, (void*) &KEY_C}; // Keyboard c and C
    static const CustomKey D = {KeyType::KEYBOARD_KEY, (void*) &KEY_D}; // Keyboard d and D
    static const CustomKey E = {KeyType::KEYBOARD_KEY, (void*) &KEY_E}; // Keyboard e and E
    static const CustomKey F = {KeyType::KEYBOARD_KEY, (void*) &KEY_F}; // Keyboard f and F
    static const CustomKey G = {KeyType::KEYBOARD_KEY, (void*) &KEY_G}; // Keyboard g and G
    static const CustomKey H = {KeyType::KEYBOARD_KEY, (void*) &KEY_H}; // Keyboard h and H
    static const CustomKey I = {KeyType::KEYBOARD_KEY, (void*) &KEY_I}; // Keyboard i and I
    static const CustomKey J = {KeyType::KEYBOARD_KEY, (void*) &KEY_J}; // Keyboard j and J
    static const CustomKey K = {KeyType::KEYBOARD_KEY, (void*) &KEY_K}; // Keyboard k and K
    static const CustomKey L = {KeyType::KEYBOARD_KEY, (void*) &KEY_L}; // Keyboard l and L
    static const CustomKey M = {KeyType::KEYBOARD_KEY, (void*) &KEY_M}; // Keyboard m and M
    static const CustomKey N = {KeyType::KEYBOARD_KEY, (void*) &KEY_N}; // Keyboard n and N
    static const CustomKey O = {KeyType::KEYBOARD_KEY, (void*) &KEY_O}; // Keyboard o and O
    static const CustomKey P = {KeyType::KEYBOARD_KEY, (void*) &KEY_P}; // Keyboard p and P
    static const CustomKey Q = {KeyType::KEYBOARD_KEY, (void*) &KEY_Q}; // Keyboard q and Q
    static const CustomKey R = {KeyType::KEYBOARD_KEY, (void*) &KEY_R}; // Keyboard r and R
    static const CustomKey S = {KeyType::KEYBOARD_KEY, (void*) &KEY_S}; // Keyboard s and S
    static const CustomKey T = {KeyType::KEYBOARD_KEY, (void*) &KEY_T}; // Keyboard t and T
    static const CustomKey U = {KeyType::KEYBOARD_KEY, (void*) &KEY_U}; // Keyboard u and U
    static const CustomKey V = {KeyType::KEYBOARD_KEY, (void*) &KEY_V}; // Keyboard v and V
    static const CustomKey W = {KeyType::KEYBOARD_KEY, (void*) &KEY_W}; // Keyboard w and W
    static const CustomKey X = {KeyType::KEYBOARD_KEY, (void*) &KEY_X}; // Keyboard x and X
    static const CustomKey Y = {KeyType::KEYBOARD_KEY, (void*) &KEY_Y}; // Keyboard y and Y
    static const CustomKey Z = {KeyType::KEYBOARD_KEY, (void*) &KEY_Z}; // Keyboard z and Z
    static const CustomKey N1 = {KeyType::KEYBOARD_KEY, (void*) &KEY_1}; // Keyboard 1 and !
    static const CustomKey N2 = {KeyType::KEYBOARD_KEY, (void*) &KEY_2}; // Keyboard 2 and @
    static const CustomKey N3 = {KeyType::KEYBOARD_KEY, (void*) &KEY_3}; // Keyboard 3 and #
    static const CustomKey N4 = {KeyType::KEYBOARD_KEY, (void*) &KEY_4}; // Keyboard 4 and $
    static const CustomKey N5 = {KeyType::KEYBOARD_KEY, (void*) &KEY_5}; // Keyboard 5 and %
    static const CustomKey N6 = {KeyType::KEYBOARD_KEY, (void*) &KEY_6}; // Keyboard 6 and ^
    static const CustomKey N7 = {KeyType::KEYBOARD_KEY, (void*) &KEY_7}; // Keyboard 7 and &
    static const CustomKey N8 = {KeyType::KEYBOARD_KEY, (void*) &KEY_8}; // Keyboard 8 and *
    static const CustomKey N9 = {KeyType::KEYBOARD_KEY, (void*) &KEY_9}; // Keyboard 9 and (
    static const CustomKey N0 = {KeyType::KEYBOARD_KEY, (void*) &KEY_0}; // Keyboard 0 and )
    static const CustomKey ENTER = {KeyType::KEYBOARD_KEY, (void*) &KEY_ENTER}; // Keyboard Return (ENTER)
    static const CustomKey ESC = {KeyType::KEYBOARD_KEY, (void*) &KEY_ESC}; // Keyboard ESCAPE
    static const CustomKey BACKSPACE = {KeyType::KEYBOARD_KEY, (void*) &KEY_BACKSPACE}; // Keyboard DELETE (Backspace)
    static const CustomKey TAB = {KeyType::KEYBOARD_KEY, (void*) &KEY_TAB}; // Keyboard Tab
    static const CustomKey SPACE = {KeyType::KEYBOARD_KEY, (void*) &KEY_SPACE}; // Keyboard Spacebar
    static const CustomKey MINUS = {KeyType::KEYBOARD_KEY, (void*) &KEY_MINUS}; // Keyboard - and _
    static const CustomKey EQUAL = {KeyType::KEYBOARD_KEY, (void*) &KEY_EQUAL}; // Keyboard = and +
    static const CustomKey LBRACE = {KeyType::KEYBOARD_KEY, (void*) &KEY_LEFTBRACE}; // Keyboard [ and {
    static const CustomKey RBRACE = {KeyType::KEYBOARD_KEY, (void*) &KEY_RIGHTBRACE}; // Keyboard ] and }
    static const CustomKey BACKSLASH = {KeyType::KEYBOARD_KEY, (void*) &KEY_BACKSLASH}; // Keyboard \ and |
    static const CustomKey HASHTILDE = {KeyType::KEYBOARD_KEY, (void*) &KEY_HASHTILDE}; // Keyboard Non-US # and ~
    static const CustomKey SCLN = {KeyType::KEYBOARD_KEY, (void*) &KEY_SEMICOLON}; // Keyboard ; and :
    static const CustomKey QUOT = {KeyType::KEYBOARD_KEY, (void*) &KEY_APOSTROPHE}; // Keyboard ' and "
    static const CustomKey GRAVE = {KeyType::KEYBOARD_KEY, (void*) &KEY_GRAVE}; // Keyboard ` and ~
    static const CustomKey COMMA = {KeyType::KEYBOARD_KEY, (void*) &KEY_COMMA}; // Keyboard , and <
    static const CustomKey DOT = {KeyType::KEYBOARD_KEY, (void*) &KEY_DOT}; // Keyboard . and >
    static const CustomKey SLASH = {KeyType::KEYBOARD_KEY, (void*) &KEY_SLASH}; // Keyboard / and ?
    static const CustomKey CAPSLOCK = {KeyType::KEYBOARD_KEY, (void*) &KEY_CAPSLOCK}; // Keyboard Caps Lock
    static const CustomKey F1 = {KeyType::KEYBOARD_KEY, (void*) &KEY_F1}; // Keyboard F1
    static const CustomKey F2 = {KeyType::KEYBOARD_KEY, (void*) &KEY_F2}; // Keyboard F2
    static const CustomKey F3 = {KeyType::KEYBOARD_KEY, (void*) &KEY_F3}; // Keyboard F3
    static const CustomKey F4 = {KeyType::KEYBOARD_KEY, (void*) &KEY_F4}; // Keyboard F4
    static const CustomKey F5 = {KeyType::KEYBOARD_KEY, (void*) &KEY_F5}; // Keyboard F5
    static const CustomKey F6 = {KeyType::KEYBOARD_KEY, (void*) &KEY_F6}; // Keyboard F6
    static const CustomKey F7 = {KeyType::KEYBOARD_KEY, (void*) &KEY_F7}; // Keyboard F7
    static const CustomKey F8 = {KeyType::KEYBOARD_KEY, (void*) &KEY_F8}; // Keyboard F8
    static const CustomKey F9 = {KeyType::KEYBOARD_KEY, (void*) &KEY_F9}; // Keyboard F9
    static const CustomKey F10 = {KeyType::KEYBOARD_KEY, (void*) &KEY_F10}; // Keyboard F10
    static const CustomKey F11 = {KeyType::KEYBOARD_KEY, (void*) &KEY_F11}; // Keyboard F11
    static const CustomKey F12 = {KeyType::KEYBOARD_KEY, (void*) &KEY_F12}; // Keyboard F12
    static const CustomKey SYSRQ = {KeyType::KEYBOARD_KEY, (void*) &KEY_SYSRQ}; // Keyboard Print Screen
    static const CustomKey SCROLLLOCK = {KeyType::KEYBOARD_KEY, (void*) &KEY_SCROLLLOCK}; // Keyboard Scroll Lock
    static const CustomKey PAUSE = {KeyType::KEYBOARD_KEY, (void*) &KEY_PAUSE}; // Keyboard Pause
    static const CustomKey INSERT = {KeyType::KEYBOARD_KEY, (void*) &KEY_INSERT}; // Keyboard Insert
    static const CustomKey HOME = {KeyType::KEYBOARD_KEY, (void*) &KEY_HOME}; // Keyboard Home
    static const CustomKey PAGEUP = {KeyType::KEYBOARD_KEY, (void*) &KEY_PAGEUP}; // Keyboard Page Up
    static const CustomKey DELETE = {KeyType::KEYBOARD_KEY, (void*) &KEY_DELETE}; // Keyboard Delete Forward
    static const CustomKey END = {KeyType::KEYBOARD_KEY, (void*) &KEY_END}; // Keyboard End
    static const CustomKey PAGEDOWN = {KeyType::KEYBOARD_KEY, (void*) &KEY_PAGEDOWN}; // Keyboard Page Down
    static const CustomKey RIGHT = {KeyType::KEYBOARD_KEY, (void*) &KEY_RIGHT}; // Keyboard Right Arrow
    static const CustomKey LEFT = {KeyType::KEYBOARD_KEY, (void*) &KEY_LEFT}; // Keyboard Left Arrow
    static const CustomKey DOWN = {KeyType::KEYBOARD_KEY, (void*) &KEY_DOWN}; // Keyboard Down Arrow
    static const CustomKey UP = {KeyType::KEYBOARD_KEY, (void*) &KEY_UP}; // Keyboard Up Arrow
    static const CustomKey NUMLOCK = {KeyType::KEYBOARD_KEY, (void*) &KEY_NUMLOCK}; // Keyboard Num Lock and Clear
    static const CustomKey KPSLASH = {KeyType::KEYBOARD_KEY, (void*) &KEY_KPSLASH}; // Keypad /
    static const CustomKey KPASTERISK = {KeyType::KEYBOARD_KEY, (void*) &KEY_KPASTERISK}; // Keypad *
    static const CustomKey KPMINUS = {KeyType::KEYBOARD_KEY, (void*) &KEY_KPMINUS}; // Keypad -
    static const CustomKey KPPLUS = {KeyType::KEYBOARD_KEY, (void*) &KEY_KPPLUS}; // Keypad +
    static const CustomKey KPENTER = {KeyType::KEYBOARD_KEY, (void*) &KEY_KPENTER}; // Keypad ENTER
    static const CustomKey KP1 = {KeyType::KEYBOARD_KEY, (void*) &KEY_KP1}; // Keypad 1 and End
    static const CustomKey KP2 = {KeyType::KEYBOARD_KEY, (void*) &KEY_KP2}; // Keypad 2 and Down Arrow
    static const CustomKey KP3 = {KeyType::KEYBOARD_KEY, (void*) &KEY_KP3}; // Keypad 3 and PageDn
    static const CustomKey KP4 = {KeyType::KEYBOARD_KEY, (void*) &KEY_KP4}; // Keypad 4 and Left Arrow
    static const CustomKey KP5 = {KeyType::KEYBOARD_KEY, (void*) &KEY_KP5}; // Keypad 5
    static const CustomKey KP6 = {KeyType::KEYBOARD_KEY, (void*) &KEY_KP6}; // Keypad 6 and Right Arrow
    static const CustomKey KP7 = {KeyType::KEYBOARD_KEY, (void*) &KEY_KP7}; // Keypad 7 and Home
    static const CustomKey KP8 = {KeyType::KEYBOARD_KEY, (void*) &KEY_KP8}; // Keypad 8 and Up Arrow
    static const CustomKey KP9 = {KeyType::KEYBOARD_KEY, (void*) &KEY_KP9}; // Keypad 9 and Page Up
    static const CustomKey KP0 = {KeyType::KEYBOARD_KEY, (void*) &KEY_KP0}; // Keypad 0 and Insert
    static const CustomKey KPDOT = {KeyType::KEYBOARD_KEY, (void*) &KEY_KPDOT}; // Keypad . and Delete
    static const CustomKey K102ND = {KeyType::KEYBOARD_KEY, (void*) &KEY_102ND}; // Keyboard Non-US \ and |
    static const CustomKey COMPOSE = {KeyType::KEYBOARD_KEY, (void*) &KEY_COMPOSE}; // Keyboard Application
    static const CustomKey POWER = {KeyType::KEYBOARD_KEY, (void*) &KEY_POWER}; // Keyboard Power
    static const CustomKey KPEQUAL = {KeyType::KEYBOARD_KEY, (void*) &KEY_KPEQUAL}; // Keypad =
    static const CustomKey F13 = {KeyType::KEYBOARD_KEY, (void*) &KEY_F13}; // Keyboard F13
    static const CustomKey F14 = {KeyType::KEYBOARD_KEY, (void*) &KEY_F14}; // Keyboard F14
    static const CustomKey F15 = {KeyType::KEYBOARD_KEY, (void*) &KEY_F15}; // Keyboard F15
    static const CustomKey F16 = {KeyType::KEYBOARD_KEY, (void*) &KEY_F16}; // Keyboard F16
    static const CustomKey F17 = {KeyType::KEYBOARD_KEY, (void*) &KEY_F17}; // Keyboard F17
    static const CustomKey F18 = {KeyType::KEYBOARD_KEY, (void*) &KEY_F18}; // Keyboard F18
    static const CustomKey F19 = {KeyType::KEYBOARD_KEY, (void*) &KEY_F19}; // Keyboard F19
    static const CustomKey F20 = {KeyType::KEYBOARD_KEY, (void*) &KEY_F20}; // Keyboard F20
    static const CustomKey F21 = {KeyType::KEYBOARD_KEY, (void*) &KEY_F21}; // Keyboard F21
    static const CustomKey F22 = {KeyType::KEYBOARD_KEY, (void*) &KEY_F22}; // Keyboard F22
    static const CustomKey F23 = {KeyType::KEYBOARD_KEY, (void*) &KEY_F23}; // Keyboard F23
    static const CustomKey F24 = {KeyType::KEYBOARD_KEY, (void*) &KEY_F24}; // Keyboard F24
    static const CustomKey OPEN = {KeyType::KEYBOARD_KEY, (void*) &KEY_OPEN}; // Keyboard Execute
    static const CustomKey HELP = {KeyType::KEYBOARD_KEY, (void*) &KEY_HELP}; // Keyboard Help
    static const CustomKey PROPS = {KeyType::KEYBOARD_KEY, (void*) &KEY_PROPS}; // Keyboard Menu
    static const CustomKey FRONT = {KeyType::KEYBOARD_KEY, (void*) &KEY_FRONT}; // Keyboard Select
    static const CustomKey STOP = {KeyType::KEYBOARD_KEY, (void*) &KEY_STOP}; // Keyboard Stop
    static const CustomKey AGAIN = {KeyType::KEYBOARD_KEY, (void*) &KEY_AGAIN}; // Keyboard Again
    static const CustomKey UNDO = {KeyType::KEYBOARD_KEY, (void*) &KEY_UNDO}; // Keyboard Undo
    static const CustomKey CUT = {KeyType::KEYBOARD_KEY, (void*) &KEY_CUT}; // Keyboard Cut
    static const CustomKey COPY = {KeyType::KEYBOARD_KEY, (void*) &KEY_COPY}; // Keyboard Copy
    static const CustomKey PASTE = {KeyType::KEYBOARD_KEY, (void*) &KEY_PASTE}; // Keyboard Paste
    static const CustomKey FIND = {KeyType::KEYBOARD_KEY, (void*) &KEY_FIND}; // Keyboard Find
    static const CustomKey MUTE = {KeyType::KEYBOARD_KEY, (void*) &KEY_MUTE}; // Keyboard Mute
    static const CustomKey VOLUMEUP = {KeyType::KEYBOARD_KEY, (void*) &KEY_VOLUMEUP}; // Keyboard Volume Up
    static const CustomKey VOLUMEDOWN = {KeyType::KEYBOARD_KEY, (void*) &KEY_VOLUMEDOWN}; // Keyboard Volume Down
    static const CustomKey KPCOMMA = {KeyType::KEYBOARD_KEY, (void*) &KEY_KPCOMMA}; // Keypad Comma
    static const CustomKey RO = {KeyType::KEYBOARD_KEY, (void*) &KEY_RO}; // Keyboard International1
    static const CustomKey KATAKANAHIRAGANA = {KeyType::KEYBOARD_KEY, (void*) &KEY_KATAKANAHIRAGANA}; // Keyboard International2
    static const CustomKey YEN = {KeyType::KEYBOARD_KEY, (void*) &KEY_YEN}; // Keyboard International3
    static const CustomKey HENKAN = {KeyType::KEYBOARD_KEY, (void*) &KEY_HENKAN}; // Keyboard International4
    static const CustomKey MUHENKAN = {KeyType::KEYBOARD_KEY, (void*) &KEY_MUHENKAN}; // Keyboard International5
    static const CustomKey KPJPCOMMA = {KeyType::KEYBOARD_KEY, (void*) &KEY_KPJPCOMMA}; // Keyboard International6
    static const CustomKey HANGEUL = {KeyType::KEYBOARD_KEY, (void*) &KEY_HANGEUL}; // Keyboard LANG1
    static const CustomKey HANJA = {KeyType::KEYBOARD_KEY, (void*) &KEY_HANJA}; // Keyboard LANG2
    static const CustomKey KATAKANA = {KeyType::KEYBOARD_KEY, (void*) &KEY_KATAKANA}; // Keyboard LANG3
    static const CustomKey HIRAGANA = {KeyType::KEYBOARD_KEY, (void*) &KEY_HIRAGANA}; // Keyboard LANG4
    static const CustomKey ZENKAKUHANKAKU = {KeyType::KEYBOARD_KEY, (void*) &KEY_ZENKAKUHANKAKU}; // Keyboard LANG5 
    static const CustomKey KPLEFTPAREN = {KeyType::KEYBOARD_KEY, (void*) &KEY_KPLEFTPAREN}; // Keypad (
    static const CustomKey KPRIGHTPAREN = {KeyType::KEYBOARD_KEY, (void*) &KEY_KPRIGHTPAREN}; // Keypad )
    static const CustomKey LCTRL = {KeyType::KEYBOARD_KEY, (void*) &KEY_LEFTCTRL}; // Keyboard Left Control
    static const CustomKey LSHIFT = {KeyType::KEYBOARD_KEY, (void*) &KEY_LEFTSHIFT}; // Keyboard Left Shift
    static const CustomKey LALT = {KeyType::KEYBOARD_KEY, (void*) &KEY_LEFTALT}; // Keyboard Left Alt
    static const CustomKey LGUI = {KeyType::KEYBOARD_KEY, (void*) &KEY_LEFTMETA}; // Keyboard Left GUI
    static const CustomKey RCTRL = {KeyType::KEYBOARD_KEY, (void*) &KEY_RIGHTCTRL}; // Keyboard Right Control
    static const CustomKey RSHIFT = {KeyType::KEYBOARD_KEY, (void*) &KEY_RIGHTSHIFT}; // Keyboard Right Shift
    static const CustomKey RALT = {KeyType::KEYBOARD_KEY, (void*) &KEY_RIGHTALT}; // Keyboard Right Alt
    static const CustomKey RGUI = {KeyType::KEYBOARD_KEY, (void*) &KEY_RIGHTMETA}; // Keyboard Right GUI

    static const CustomKey MNT = {KeyType::MEDIA_KEY, (void*) &KEY_MEDIA_NEXT_TRACK};
    static const CustomKey MPT = {KeyType::MEDIA_KEY, (void*) &KEY_MEDIA_PREVIOUS_TRACK};
    static const CustomKey MSTOP = {KeyType::MEDIA_KEY, (void*) &KEY_MEDIA_STOP};
    static const CustomKey MPAUSE = {KeyType::MEDIA_KEY, (void*) &KEY_MEDIA_PLAY_PAUSE};
    static const CustomKey MMUTE = {KeyType::MEDIA_KEY, (void*) &KEY_MEDIA_MUTE};
    static const CustomKey MVUP = {KeyType::MEDIA_KEY, (void*) &KEY_MEDIA_VOLUME_UP};
    static const CustomKey MVDOWN = {KeyType::MEDIA_KEY, (void*) &KEY_MEDIA_VOLUME_DOWN};
    static const CustomKey MWWW_HOME = {KeyType::MEDIA_KEY, (void*) &KEY_MEDIA_WWW_HOME};
    static const CustomKey MBROWSER = {KeyType::MEDIA_KEY, (void*) &KEY_MEDIA_LOCAL_MACHINE_BROWSER};
    static const CustomKey MCALCULATOR = {KeyType::MEDIA_KEY, (void*) &KEY_MEDIA_CALCULATOR};
    static const CustomKey MBOOKMARKS = {KeyType::MEDIA_KEY, (void*) &KEY_MEDIA_WWW_BOOKMARKS};
    static const CustomKey MSEARCH = {KeyType::MEDIA_KEY, (void*) &KEY_MEDIA_WWW_SEARCH};
    static const CustomKey MWSTOP = {KeyType::MEDIA_KEY, (void*) &KEY_MEDIA_WWW_STOP};
    static const CustomKey MWBACK = {KeyType::MEDIA_KEY, (void*) &KEY_MEDIA_WWW_BACK};
    static const CustomKey MCONSUMER_CONTROL_CONFIGURATION = {KeyType::MEDIA_KEY, (void*) &KEY_MEDIA_CONSUMER_CONTROL_CONFIGURATION};
    static const CustomKey MEMAIL_READER = {KeyType::MEDIA_KEY, (void*) &KEY_MEDIA_EMAIL_READER};

    static CustomKey LM(u_int8_t index, KEY_MODE mode = KEY_MODE::PRESS) {
        LayerData *data = new LayerData(mode, index);
        return {KeyType::LAYER_KEY, (void*) data};
    }
} // namespace KEY

#endif