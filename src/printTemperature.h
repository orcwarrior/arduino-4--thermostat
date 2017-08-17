// printTemperature.h
#ifndef _printTemperature_h
#define _printTemperature_h

#define TEMP_OFF -9999

	#if defined(ARDUINO) && ARDUINO >= 100
		#include "Arduino.h"
	#else
		#include "WProgram.h"
	#endif
  
	#include <Adafruit_GFX.h>
	void printTemperature(Adafruit_GFX &display, double temp, int row, const char* caption);
							  
#endif