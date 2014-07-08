#include "ShiftRegister.h"

ShiftRegister::ShiftRegister(Pin* clock, Pin* latch, Pin* data) {
	this->clock = clock;
	this->latch = latch;
	this->data = data;
	this->value = 0;
}

/**
 * Get the pin associated with the given offset.
 * If the pin has not been created, it will first be created (lazy loading).
 *
 * @param int offset
 * @return ShiftRegisterPin*
 */
ShiftRegisterPin* ShiftRegister::getPin(int offset) {
	ShiftRegisterPin* pin;

	pin = this->pins[offset];
	if (pin == NULL) {
		pin = new ShiftRegisterPin(this, offset);
		this->pins[offset] = pin;
	}
	
	return pin;
}

/**
 * Read an int from the shift register.
 *
 * @return int the int read from the shift register
 */
int ShiftRegister::read() {
	boolean state;
	int value = 0;
	this->latch->write(LOW);
	this->latch->write(HIGH);

	for (int i = 0; i < SHIFT_REGISTER_NUM_PINS; i++) {
		this->clock->write(LOW);
		state = this->data->read();
		value |= state << i;
		this->clock->write(HIGH);
	}

	this->latch->write(LOW);

	return value;
}

/**
 * Write an int to the shift register.
 *
 * @param int value the value to write to the shift register
 */
void ShiftRegister::write(int value) {
	byte state;
	this->latch->write(HIGH);
	this->latch->write(LOW);

	for (byte i = 0; i < 8; i++) {
		state = !!(value & (1 << (7 - i)));
		this->data->write(state);
		this->clock->write(HIGH);
		this->clock->write(LOW);
	}

	this->latch->write(HIGH);
}

/**
 * Set a bit (some Qi) of the shift register.
 *
 * @param int index
 * @param int value
 */
void ShiftRegister::setBit(int index, int value) {
	this->value = ((~(0x1 << index)) & this->value) | (value << index);
	this->write(this->value);
}