// CLASS: Event.cpp
//
// Author: Rhushabh Patel, 7833416
//
// REMARKS: the purpose of this class is to make products of the parts given
//
//-----------------------------------------
#include "Event.h"
#include "StartAssembly.h"
#include "EndAssembly.h"
#include "ProductArrival.h"

Event::Event(int theTime, Simulation *theSim) :eventTime(theTime), sim (theSim) {}
Event::~Event() {}
int Event::getTime(){ return eventTime; }

int Event::compareTo(OrderedItem* other) {
	int currentTime = eventTime;
	int otherTime  = dynamic_cast<Event*>(other)->getTime();
	return currentTime - otherTime;
}// compareTo
