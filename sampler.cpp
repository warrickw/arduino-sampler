#include "sampler.h"

/**
	Create a sampler with the specified delay between samples
 */
Sampler::Sampler(int delay): delay(delay) {
	next_trigger = 0;
}

/**
	Initialize an unconfigured sampler
 */
Sampler::Sampler() {
	delay = 0;
	next_trigger = 0;
}

/**
 */
void Sampler::setDelay(int delay) {
	// Set the delay
	Sampler::delay = delay;
}

int Sampler::getDelay() {
	return delay;
}

int Sampler::getFrequency() {
	return 1000 / delay;
}

/**
	Set the frequency that this sampler should sample at
 */
void Sampler::setFrequency(int frequency) {
	// Set the delay by using the frequency
	Sampler::delay = 1000 / frequency;
}

/**
	Enable the sampler, which will cause it to trigger instantly
 */
void Sampler::enable() {
	enabled = true;
	next_trigger = 0;
}

/**
	Disable the sampler
 */ 
void Sampler::disable() {
	enabled = false;
}

/**
	Returns true if this sampler is ready to take another sample
 */
bool Sampler::shouldSample() {
	if(next_trigger < millis()) {
		next_trigger = millis() + delay;
		return true;
	}
	else {
		return false;
	}
}