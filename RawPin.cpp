#include "RawPin.h"

/**
 * Create a new instance of RawPin with the given pin number.
 *
 * @param int pinNumber
 */
RawPin::RawPin(int pinNumber) {
	this->pinNumber = pinNumber;
	pinMode(pinNumber, OUTPUT);
}

/**
 * Set the mode of this pin, e.g., INPUT or OUTPUT.
 *
 * @param int mode
 */
void RawPin::setMode(int mode) {
	pinMode(this->pinNumber, mode);
}

/**
 * Read a value from the raw pin.
 *
 * @return int
 */ 
int RawPin::read() {
	return (int) digitalRead(this->pinNumber);
}

/**
 * Write a value to the raw pin.
 *
 * @param int value
 */
void RawPin::write(int value) {
	digitalWrite(this->pinNumber, value);
}