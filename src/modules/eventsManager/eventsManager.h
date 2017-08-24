// eventsManager.h

#ifndef _EVENTSMANAGER_h
#define _EVENTSMANAGER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "../generics/hashMap/hashMap.h"
#include "../generics/vector/vector.h"
#include "Event.h"

#include "../delegate/delegate.h"


class EventListenerData { // ListenerDelegate
	public:
	EventListenerData(void* listener, void (*callback)(void*));
	const void* listener;
	const void (*callback)(void*);
};

// TODO: Singleton
class EventsManagerClass  {
	protected:
	// HashMap<const char*, IEventsHandler> eventHandlersMap;

	public:
	EventsManagerClass();
	~EventsManagerClass();
	//  void registerEventHandler(IEventsHandler handler, HandlerFunc handlerFuncPtr) {			  };
	// Events:
	void registerEvent(Event* e);
	void removeEvent(Event* e);
	void fireEvent(Event* e, void* arg=NULL);
	
	// EventListeners:
	bool listen(const char* eventName); // TODO: delegate
};


#endif

