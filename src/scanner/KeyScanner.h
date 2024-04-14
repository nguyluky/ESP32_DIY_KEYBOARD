
#ifndef KEYS_CANNER
#define KEYS_CANNER
#include <Arduino.h>
#include "../config.h"
struct KeyEvent
{
    byte colume, row;
    bool pess;
};

class MatrixKeyPad
{
private:
    virtual void pin_mode(byte pinNum, byte mode) { pinMode(pinNum, mode); }
	virtual void pin_write(byte pinNum, boolean level) { digitalWrite(pinNum, level); }
	virtual int  pin_read(byte pinNum) { return digitalRead(pinNum); }
    void (*eventListener)(KeyEvent);
    bool lastStatus[ROWS][COLUMNS][2] = {};
    uint8_t *columnPins;
    uint8_t *rowPins;
    uint8_t columns;
    uint8_t rows;
    unsigned long lastTime = 0;
public:
    unsigned long delayTime = 10;
    MatrixKeyPad(uint8_t *colume, uint8_t *row, uint8_t columes, uint8_t rows);
    void scanner();
    void update();
    void addEventListener(void (*listener)(KeyEvent));
};

#endif