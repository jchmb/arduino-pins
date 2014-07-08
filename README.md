Arduino Pins Library
====================

This Arduino library provides a basic framework for an uniform treatment of pins. 
The Arduino Pins library generalizes the concept of a Pin in such a way that it no longer matters whether the
pin is directly connected to the Arduino, or indirectly, as "virtual" pins, e.g., when using shift register input/output pins.
You can treat them all in the same way. This can save a lot of time. In most situations, this library can therefore be very helpful.
However, it is not perfect. There are some trade-offs when using the library. Its usage may not always be appropriate. It is up to you to decide.