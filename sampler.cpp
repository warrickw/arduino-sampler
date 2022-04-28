#include "sampler.h"
#include <Arduino.h>

/**
	Create a sampler with the specified delay between samples
 */
Sampler::Sampler(unsigned long delay_ms) : delay_us(delay_ms * 1000)
{
}

/**
	Initialize an unconfigured sampler
 */
Sampler::Sampler()
{
	delay_us = 0;
}

void Sampler::setDelayMs(unsigned long delay)
{
	// Set the delay
	delay_us = delay * 1000;
}

void Sampler::setDelayUs(unsigned long delay)
{
	// Set the delay
	delay_us = delay;
}

unsigned int Sampler::getDelayMs()
{
	return delay_us / 1000;
}

unsigned long Sampler::getDelayUs()
{
	return delay_us;
}

unsigned int Sampler::getFrequency()
{
	return 1000 / (delay_us / 1000);
}

/**
	Set the frequency that this sampler should sample at
 */
void Sampler::setFrequency(int frequency)
{
	// Set the delay by using the frequency
	delay_us = (int)1000.0 / (float)frequency * 1000.0;
}

/**
	Enable the sampler
 */
void Sampler::enable()
{
	enabled = true;
	last_trigger_us = micros();
}

/**
	Enable the sampler, which will cause it to trigger instantly
 */
void Sampler::enable_and_trigger()
{
	enabled = true;
	last_trigger_us = micros() - delay_us;
}

/**
	Disable the sampler
 */
void Sampler::disable()
{
	enabled = false;
}

/**
	Returns true if this sampler is ready to take another sample
 */
bool Sampler::shouldSample()
{
	if (!enabled)
		return false;

	if (micros() - last_trigger_us >= delay_us)
	{
		last_trigger_us = micros();
		return true;
	}
	else
	{
		return false;
	}
}