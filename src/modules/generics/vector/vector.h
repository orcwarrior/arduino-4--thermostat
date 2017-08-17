// vector.h

#ifndef _VECTOR_h
#define _VECTOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class VectorClass
{
 protected:


 public:
	void init();
};

extern VectorClass Vector;

#endif

