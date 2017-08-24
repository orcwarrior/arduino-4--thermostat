/*
* IEventListener.h
*
* Created: 17.08.2017 20:14:38
*  Author: orcwa
*/


#ifndef Event_H_
#define Event_H_

#include "eventsManager.h"

class Event {
	public:
	Event(const char* eventName, bool enabled = true) {
		this->name = eventName;
		this->enabled = enabled;
		//EventsManager->registerEvent(this);
	}
	~Event() {
		//EventsManager->removeEvent(this);
		delete this->name;
	}
	void fire(void* arg = NULL) {
		// EventsManager.fireEvent(this, arg);
	}
	
	const char* getName() { return this->name; };
	bool IsEnabled() const { return enabled; }
	
	protected:
	const char* name;
	bool enabled;
};


#endif /* Event_H_ */