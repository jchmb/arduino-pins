#include "ShiftRegisterPin.h"

ShiftRegisterPin::ShiftRegisterPin(ShiftRegister* shiftRegister, int index) {
	this->shiftRegister = shiftRegister;
	this->index = index;
}

int ShiftRegisterPin::read() {
	return this->shiftRegister->getBit(this->index);
}

void ShiftRegisterPin::write(int value) {
	this->shiftRegister->setBit(this->index, value);
}