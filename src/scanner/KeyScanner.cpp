#include "KeyScanner.h"


MatrixKeyPad::MatrixKeyPad(uint8_t *colume, uint8_t *row, uint8_t columns, uint8_t rows) {
	this->columnPins = colume;
	this->rowPins = row;
	this->columns = columns;
	this->rows = rows;


	for (byte r=0; r<rows; r++) {
		pin_mode(rowPins[r],OUTPUT);
		pin_write(rowPins[r], LOW);
	}

	for (byte i = 0; i < columns; i++)
	{
		pin_mode(columnPins[i], INPUT_PULLDOWN);
	}
	
}

void MatrixKeyPad::scanner() {
	// Serial.println("------");
	for (byte r=0; r<rows; r++) {
		digitalWrite(rowPins[r], HIGH);
		for (byte c=0; c<columns; c++) {
			lastStatus[r][c][0] = digitalRead(columnPins[c]);
		}
		digitalWrite(rowPins[r], LOW);
	}
}


void MatrixKeyPad::update() {

	if (millis() - lastTime < delayTime) return;
	lastTime = millis();
	this->scanner();

	for (uint8_t r = 0; r < rows; r++)
	{
		for (uint8_t c = 0; c < columns; c++)
		{
			if (lastStatus[r][c][0] != lastStatus[r][c][1]) {
				lastStatus[r][c][1] = lastStatus[r][c][0];
				// Serial.printf("key event %d:%d -> %d \n", r, c, lastStatus[r][c][0]);
				if (eventListener != NULL) {
					eventListener({c, r, lastStatus[r][c][0]});
				}
			}
		}
	}
}

void MatrixKeyPad::addEventListener(void (*listener)(KeyEvent)) {
	this->eventListener = listener;
}