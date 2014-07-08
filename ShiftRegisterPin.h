#ifndef H_SHIFT_REGISTER_PIN
#define H_SHIFT_REGISTER_PIN 1

#include <Arduino.h>
#include "Pin.h"
#include "ShiftRegister.h"

class ShiftRegister;

/**
 * The ShiftRegisterPin is a virtual pin derived from the Pin base class.
 * It can be treated as any other Pin, regardless of its implementation.
 * However, in order to retrieve ShiftRegisterPin instances, a ShiftRegister instance must
 * be created, with given clock, latch and data Pins, which can then provide ShiftRegisterPins
 * with ShiftRegisterPin* ShiftRegister::getPin(int).
 *
 * You cannot just instantiate ShiftRegisterPins; you need the ShiftRegister.
 */
class ShiftRegisterPin : Pin {
	private:
		ShiftRegister* shiftRegister;
		int index;
	public:
		ShiftRegisterPin(ShiftRegister*, int);
		int read();
		void write(int);
};

#endif