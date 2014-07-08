#ifndef H_SHIFT_REGISTER
#define H_SHIFT_REGISTER 1

#include <Arduino.h>
#include "ShiftRegisterPin.h"
#include "Pin.h"

#define SHIFT_REGISTER_NUM_PINS 8

class Pin;
class ShiftRegisterPin;

class ShiftRegister {
	private:
		Pin* clock;
		Pin* latch;
		Pin* data;
		ShiftRegisterPin* pins[SHIFT_REGISTER_NUM_PINS];
		int value;
	public:
		ShiftRegister(Pin*, Pin*, Pin*);
		ShiftRegisterPin* getPin(int);
		void write(int);
		void setBit(int, int);
		int read();
};

#endif