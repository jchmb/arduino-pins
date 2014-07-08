#ifndef H_RAW_PIN
#define H_RAW_PIN 1

#include <Arduino.h>
#include "Pin.h"

class RawPin : Pin {
	private:
		int pinNumber;
	public:
		RawPin(int);
		int read();
		void write(int);
		void setMode(int);
};

#endif