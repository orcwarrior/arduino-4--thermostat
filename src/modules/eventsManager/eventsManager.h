// eventsManager.h

#ifndef _EVENTSMANAGER_h
#define _EVENTSMANAGER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class ILoopHandler {
  public:
  ILoopHandler(); 
  ~ILoopHandler();
  virtual void onLoop() = 0; // To override by deriving classes
};		
class ISetupHandler {
  public:
  ISetupHandler();
  ~ISetupHandler();
  virtual void onSetup() = 0; // To override by deriving classes
};
// Generic handler:
class IEventHandler {
  public:
  IEventHandler();
  ~IEventHandler();
  virtual void onEvent(const char* eventName) = 0; // To override...
  void registerToEvent(const char* eventName);
  };
class EventsManagerClass
{
  protected:


  public:
  void init();
  void registerEventHandler();
  void callEvent(const char* eventName, int passedData); // TODO: int, cmon
};

extern EventsManagerClass EventsManager;

#endif

