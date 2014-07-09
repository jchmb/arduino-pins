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
		ShiftRegister* child;
		ShiftRegister* parent;
		int value;
		boolean autoUpdate;
		int mode;
	public:
		ShiftRegister(Pin*, Pin*, Pin*);
		ShiftRegisterPin* getPin(int);
		void write(int);
		int getBit(int);
		void setBit(int, int);
		void setOverflow(ShiftRegister*);
		void setParent(ShiftRegister*);
		void setChild(ShiftRegister*);
		void setMode(int);
		int read();
		void update();
		void setAutoUpdate(boolean);
};

#endif