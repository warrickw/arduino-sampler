#ifndef sampler_h
#define sampler_h

#include "Arduino.h"

/**
	Provides a simple class to control sample rates running in an event loop
 */
class Sampler {
	public:
		// Construct a new Sampler with the given delay (in ms) between samples
		Sampler(int delay_ms);
		// Construct a new sampler (will have 'no' delay between samples, so you should call setDelay or setFrequency)
		Sampler();
		// Set the delay between samples
		void setDelayMs(int delay);
		void setDelayUs(unsigned long delay);
		// Set the frequency to sample (eg, 5hz - 5 times per second)
		void setFrequency(int frequency);
		// Get the delay between samples
		int getDelayMs();
		unsigned long getDelayUs();
		// Get the sample frequency
		int getFrequency();
		// Returns true if a sample should be taken
		bool shouldSample();
		// Enable this sampler (it will always return false from shouldSample unless it is enabled)
		void enable();
		// Enable this sampler (it will always return false from shouldSample unless it is enabled)
		void enable_and_trigger();
		// Disable this sampler, causing it to always return false from shouldSample
		void disable();
	private:
		// Whether this sampler is enabled or not
		bool enabled = false;
		// The delay between samples
		unsigned long delay_us = 0;
		// The time that the next sample should be triggered
		unsigned long last_trigger_us = 0;
};

#endif