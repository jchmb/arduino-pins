#include "ShiftRegisterPin.h"

ShiftRegisterPin::ShiftRegisterPin(ShiftRegister* shiftRegister, int index) {
	this->shiftRegister = shiftRegister;
	this->index = index;
}

int ShiftRegisterPin::read() {
	int value = this->shiftRegister->read();
	int state = (value >> this->index) & 1;
	return state;
}

void ShiftRegisterPin::write(int value) {
	this->shiftRegister->setBit(this->index, value);
}