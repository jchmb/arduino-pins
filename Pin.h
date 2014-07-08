#ifndef H_PIN
#define H_PIN 1

/**
 * Abstract base class and interface for pin-based readers and writers.
 *
 * Functions to implement:
 * int Pin::read()
 * void Pin::write(int)
 */
class Pin {
	public:
		/**
		 * Read an int from the pin.
		 *
		 * @return int
		 */
		virtual int read();

		/**
		 * Write an int to the pin.
		 *
		 * @param int
		 */
		virtual void write(int);
};

#endif