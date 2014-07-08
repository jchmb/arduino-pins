#include "Pin.h"
#include "RawPin.h"
#include "ShiftRegister.h"
#include "ShiftRegisterPin.h"

/*
 * Just a test to demonstrate the uniformity of direct and virtual pins
 * used interchangeably. The use of this has its ups and downsides.
 * For most purposes, it will probably have more ups than downs, 
 * but this is up to you to decide for yourself. 
 */

Pin* pins[3];
RawPin p1(2);
RawPin p2(3);
RawPin p3(4);
RawPin p4(5);
RawPin p5(6);
ShiftRegister sr((Pin*) &p1, (Pin*) &p2, (Pin*) &p3);
ShiftRegisterPin* srp1;
ShiftRegisterPin* srp2;

void setup() {
	Serial.begin(9600);

	srp1 = sr.getPin(0);
	srp2 = sr.getPin(1);

	pins[0] = (Pin*) &p4;
	pins[1] = (Pin*) srp1;
	pins[2] = (Pin*) srp2;
}

void loop() {
	for (byte b = 0; b < 3; b++) {
		pins[b]->write(HIGH);
		delay(500);
		pins[b]->write(LOW);
		delay(500);
	}
}