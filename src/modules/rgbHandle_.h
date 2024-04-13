#ifndef RGB_HANDLE_HEARD
#define RGB_HANDLE_HEARD
#include <Arduino.h>
#include <pixeltypes.h>
#include "../structure.h"

uint8_t ledMap[NUM_PIXELS] = {
    7, 36, 50, 65, 79, 101, 115, 129, 144, 165, 180, 194, 208, 226, 241, 255, 7, 22, 36, 50, 65, 79, 93, 108, 122, 136,
    151, 165, 180, 201, 226, 241, 255, 11, 29, 43, 57, 72, 86, 101, 115, 129, 144, 158, 172, 187, 205, 226, 241, 255, 13,
    32, 47, 61, 75, 90, 104, 119, 133, 147, 162, 176, 199, 16, 40, 54, 68, 83, 97, 111, 126, 140, 154, 169, 196, 241, 9,
    27, 45, 99, 153, 171, 189, 207, 226, 241, 255};

class RgbHandle
{
private:
    CRGB *leds;
    int countLed;
    rgbEffect effect = rgbEffect::WAVE;
    uint8_t hubOffset = 0;
    uint8_t showLeds = 0;
    uint16_t delayTime = 200;
    unsigned long lastTime = 0;
public:

    void rainbowEffect();
    void waveEffect();
    RgbHandle(CRGB *ledBuff, uint8_t countLed);
    ~RgbHandle();
    void update();
};


RgbHandle::RgbHandle(CRGB *ledBuff, uint8_t countLed)
{
  this->leds = ledBuff;   
  this->countLed = countLed;
}

RgbHandle::~RgbHandle()
{
}

void RgbHandle::update(){
    if (millis() - lastTime < delayTime) return;
    lastTime = millis();

    switch (effect)
    {
    case rgbEffect::RAINBOW:
        rainbowEffect();
        break;
    
    case rgbEffect::WAVE:
        waveEffect();
        break;
    }

    if (effect != LED_OFF) FastLED.show();
}

void RgbHandle::rainbowEffect() {
    uint8_t culumn;
    for (uint8_t i = 0; i < NUM_PIXELS; i++)
    {
        culumn = ledMap[i];
        leds[i] = CHSV(culumn + hubOffset, 255, 255);
    }
    hubOffset-=10;
}

void RgbHandle::waveEffect() {
    uint8_t culumn;
    bool showAll = true;
    for (uint8_t i = 0; i < NUM_PIXELS; i++)
    {
        culumn = ledMap[i];
        if (culumn >= showLeds + 10) {
            showAll = false;
            continue;
        }
        leds[i] = CHSV(hubOffset, 255, 255);
    }
    showLeds += 10;
    if (showAll) hubOffset+=25;
}

#endif