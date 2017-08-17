// tempSensor.h

#ifndef _TEMPSENSOR_h
#define _TEMPSENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class TempSensorClass
{
 protected:


 public:
	void init();
};

extern TempSensorClass TempSensor;

#endif

