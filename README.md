Arduino Pins Library
====================

This is a Work In Progress project. Some features may be missing. Not everything may be working. If you encounter some problem, please contact me and I will have a look at it.

This Arduino library provides a basic framework for an uniform treatment of pins. 
The Arduino Pins library generalizes the concept of a Pin in such a way that it no longer matters whether the
pin is directly connected to the Arduino, or indirectly, as "virtual" pins, e.g., when using shift register input/output pins.
You can treat them all in the same way. This can save a lot of time. In most situations, this library can therefore be very helpful.
However, it is not perfect. There are some trade-offs when using the library. Its usage may not always be appropriate. It is up to you to decide whether this is the case.

Any implementation of Pin has implemented void Pin::write(int) and int Pin::read(). You can easily add your own implementation. Currently there are three implementations:
the RawPin, the ShiftRegisterPin, and the DebugPin; the latter two being "virtual" pins.

To use the "direct" Arduino pins in this framework, you simple have to create an instance of the RawPin class with the pin number as an argument for the constructor.
The RawPin implementations of void Pin::write(int) and int Pin::read() are very simple.

To use the "indirect" or "virtual" pins in this framework, e.g., some shift register pin Qi, as any other Arduino pin, you need to create an instance of the
ShiftRegister class first. The constructor of the ShiftRegister class requires three arguments, which are all implementations of the Pin class. It is recommended
that you provide instances of the RawPin class here, but in principle, this is not required. In any case, you need to provide the clock pin, the latch pin
and the data pin. After you have instantiated the ShiftRegister class, you can retrieve ShiftRegisterPins, i.e., "virtual" pins, from it. 
These can be retrieved by the ShiftRegisterPin* ShiftRegister::getPin(int) function. It will be created on demand, since not every pin is necessarily used.
After this, the ShiftRegisterPin can be treated as any other Pin. 

Also, the DebugPin can be used as a replacement of any Pin. With the help of the DebugPin, you can see on the serial monitor when certain calls are made during runtime.
