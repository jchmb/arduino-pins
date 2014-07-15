#include "DebugPin.h"

DebugPin::DebugPin(char* label) {
	this->label = label;
}

int DebugPin::read() {
	Serial.write("DebugPin [");
	Serial.write(label);
	Serial.write("]");
	Serial.write(" has been read.");
	Serial.write("\n");
	return 0;
}

void DebugPin::write(int value) {
	Serial.write("DebugPin [");
	Serial.write(label);
	Serial.write("]");
	Serial.write(" has been written to (");
	Serial.write(value);
	Serial.write("]");
	Serial.write("\n");
}