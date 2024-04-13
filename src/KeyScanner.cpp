#include "KeyScanner.h"


MatrixKeyPad::MatrixKeyPad(uint8_t *colume, uint8_t *row, uint8_t columns, uint8_t rows) {
	this->columnPins = colume;
	this->rowPins = row;
	this->columns = columns;
	this->rows = rows;
}

void MatrixKeyPad::scanner() {

	for (byte r=0; r<rows; r++) {
		pinMode(rowPins[r],INPUT_PULLDOWN);
	}

	// Serial.println("------");
	for (byte c=0; c<columns; c++) {
		pinMode(columnPins[c],OUTPUT);
		digitalWrite(columnPins[c], HIGH);
		for (byte r=0; r<rows; r++) {
			lastStatus[r][c][0] = digitalRead(rowPins[r]);
			// Serial.printf("%d ", digitalRead(rowPins[r]));
		}
		// Serial.println();
		digitalWrite(columnPins[c],LOW);
	}
}


void MatrixKeyPad::update() {

	if (millis() - lastTime <= 10) return;
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