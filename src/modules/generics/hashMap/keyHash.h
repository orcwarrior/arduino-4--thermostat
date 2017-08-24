// keyHash.h

#ifndef _KEYHASH_h
#define _KEYHASH_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
#include "hashMap.h"
   // Default hash function class
   
   template <typename K>
   struct KeyHash {
     unsigned long operator()(const K& key) const
     {
       return reinterpret_cast<unsigned long>(key) % TABLE_SIZE;
     }
   };
#endif

