// AM2320.h

#ifndef _AM2320_h
#define _AM2320_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#define AM2320_address (0xB8 >> 1)

class AM2320
{
	public:
	AM2320();
	float t;
	float h;
	int Read(void);
};

#endif

