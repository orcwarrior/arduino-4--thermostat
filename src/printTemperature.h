// temperaturePrinter.h

#ifndef _TEMPERATUREPRINTER_h
#define _TEMPERATUREPRINTER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#define TEMP_OFF -9999					    

static inline void printTemperature(Adafruit_GFX &display, double temp, int row)
							  
#endif