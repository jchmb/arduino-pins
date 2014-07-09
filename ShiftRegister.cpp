#include "ShiftRegister.h"

ShiftRegister::ShiftRegister(Pin* clock, Pin* latch, Pin* data) {
	this->clock = clock;
	this->latch = latch;
	this->data = data;
	this->value = 0;
	this->parent = NULL;
	this->child = NULL;
	this->autoUpdate = true;
	this->mode = OUTPUT;
}

/**
 * Set the ShiftRegister that has its data pin connected to this ShiftRegister's overflow pin.
 * Use this whenever you are connecting multiple shift registers in series.
 *
 * @param ShiftRegister* overflow
 */
void ShiftRegister::setOverflow(ShiftRegister* overflow) {
	this->setChild(overflow);
	overflow->setParent(this);
}

/**
 * Set the parent of this ShiftRegister, which is the ShiftRegister 
 * that has its overflow pin connected to this ShiftRegister's data pin.
 *
 * @param ShiftRegister* parent
 */
void ShiftRegister::setParent(ShiftRegister* parent) {
	this->parent = parent;
}

/**
 * Set the child of this ShiftRegister, which is the ShiftRegister
 * that has its data pin connected to this ShiftRegister's overflow pin.
 *
 * @param ShiftRegister* child
 */
void ShiftRegister::setChild(ShiftRegister* child) {
	this->child = child;
}

/**
 * Set the mode of this ShiftRegister: INPUT or OUTPUT.
 *
 * @param int mode
 */
void ShiftRegister::setMode(int mode) {
	this->mode = mode;
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

	if (this->parent == NULL) {
		this->latch->write(LOW);
		this->latch->write(HIGH);
	}

	for (int i = 0; i < SHIFT_REGISTER_NUM_PINS; i++) {
		this->clock->write(LOW);
		state = this->data->read();
		value |= state << i;
		this->clock->write(HIGH);
	}

	if (this->child == NULL) {
		this->latch->write(LOW);
	} else {
		this->child->update();
	}

	return value;
}

void ShiftRegister::update() {
	if (this->mode == OUTPUT) {
		this->write(this->value);
	} else if (this->mode == INPUT) {
		this->value = this->read();
	}
}

/**
 * Write an int to the shift register.
 *
 * @param int value the value to write to the shift register
 */
void ShiftRegister::write(int value) {
	byte state;

	if (this->parent == NULL) {
		this->latch->write(HIGH);
		this->latch->write(LOW);
	}
	
	for (byte i = 0; i < 8; i++) {
		state = !!(value & (1 << (7 - i)));
		this->data->write(state);
		this->clock->write(HIGH);
		this->clock->write(LOW);
	}

	if (this->child == NULL) {
		this->latch->write(HIGH);
	} else {
		this->child->update();
	}
}

/**
 * Set a bit (from some Qi) of the shift register.
 *
 * @param int index
 * @param int value
 */
void ShiftRegister::setBit(int index, int value) {
	this->value = ((~(0x1 << index)) & this->value) | (value << index);
	if (this->autoUpdate) {
		this->update();
	}
}

/**
 * Retrieve a bit (from some Qi) of the shift register.
 *
 * @param int index
 * @return int
 */
int ShiftRegister::getBit(int index) {
	if (this->autoUpdate) {
		this->update();
	}
	return (this->value >> index) & 1;
}

/**
 * Set the auto update functionality on or off. Default is on.
 * This will call the void ShiftRegister::update() function whenever a bit is set.
 *
 * @param boolean autoUpdate
 */
void ShiftRegister::setAutoUpdate(boolean autoUpdate) {
	this->autoUpdate = autoUpdate;
}