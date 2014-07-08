Arduino Pins Library
====================

This is a Work In Progress project. Some features may be missing. Not everything may be working. If you encounter some problem, please contact me and I will have a look at it.

This Arduino library provides a basic framework for an uniform treatment of pins. 
The Arduino Pins library generalizes the concept of a Pin in such a way that it no longer matters whether the
pin is directly connected to the Arduino, or indirectly, as "virtual" pins, e.g., when using shift register input/output pins.
You can treat them all in the same way. This can save a lot of time. In most situations, this library can therefore be very helpful.
However, it is not perfect. There are some trade-offs when using the library. Its usage may not always be appropriate. It is up to you to decide.

This is what it can do:
<code>[for (byte b = 0; b < 3; b++) {<br>
		pins[b]->write(HIGH);<br>
		delay(500);<br>
		pins[b]->write(LOW);<br>
		delay(500);<br>
	}
</code>

Even though some pins may be directly connected to either the digital or analog pins, while other "virtual" pins are input/output pins of a shift register, for example.