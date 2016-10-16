Arduino Sampler
==============

Many arduino projects require different actions to happen at fixed timer intervals - for example
sampling a sensor every 100ms, without adding simple delay() calls which would block the entire program
and not let anything else execute.

This simple library provides an easy way to run code at different sample rates and removes the boilderplate code
that you would otherwise have to write every time.

###Example Arduino sketch

The following is also provided in the library 'examples' folder.

````
	// Include the 'Arduino Sampler' library
	#include "sampler.h"

	// Create a sampler with a delay of 100ms between samples
	Sampler sampler(100);

	/**
	This is called to setup the sketch before loop() starts running
	*/
	void setup() {
	// Other configuration options:
	
	// Sample 5 times per second
	//sampler.setFrequency(5);
	
	// Set the sampler to sample at 100ms intervals
	//sampler.setDelay(100);
	
	
	
	// Enable the sampler - don't forget this
	sampler.enable();
	
	// Disable the sampler
	//sampler.disable();
	}

	/**
	This is called repeatedly back to back by the Arduino framework
	*/
	void loop() {
	// Surround the code to run at the sample rate with an if statement
	// calling sampler.shouldSample()
	if(sampler.shouldSample()) {
		// This code will run every 100ms while the sampler is enabled, as the sampler is configured
	}
	}
````

Installation
==============

1. From the command line 'cd' into the Arduino/libraries folder.
2. Enter 'git clone https://github.com/warrickw/arduino-sampler.git'
3. This will clone the library into your Arduino libraries.
4. Restart the Arduino IDE.
