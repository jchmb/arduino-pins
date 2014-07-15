#ifndef H_DEBUG_PIN
#define H_DEBUG_PIN 1

#include <Arduino.h>
#include "Pin.h"

class DebugPin : Pin {
	private:
		char* label;
	public:
		DebugPin(char*);
		void write(int);
		int read();
};

#endif