// CLASS: PartArrival.cpp
//
// Author: Rhushabh Patel, 7833416
//
// REMARKS: when parts will arrive it will cause an event start assembly 
//
//-----------------------------------------

#include "PartArrival.h"
#include <string>
#include "Simulation.h"
#include "StartAssembly.h"
#include "Event.h"
#include "ListItem.h"
#include "ProductArrival.h"
using namespace std;

PartArrival::PartArrival(int a, Simulation* s,int p) :Event(a, s), pNumber(p){}

void PartArrival::processEvent()
{ 
	Event* startAssembly;
	Event* partArrives = new PartArrival(Event::getTime(), sim, pNumber);
	sim->insertPart(partArrives,pNumber);
	
	if (!sim->isMainBusy() &&!sim->partQueueIsEmpty(0) && !sim->partQueueIsEmpty(1) )
	{
		if (sim->partTime(1) > sim->partTime(0))
		{
			startAssembly = new StartAssembly(Event::getTime(), sim, pNumber);
			sim->SetDepartureTime(sim->partTime(1) );
		}
		else
		{
			startAssembly = new StartAssembly(Event::getTime(), sim, 0);
			sim->SetDepartureTime(sim->partTime(0) );
		}

		startAssembly->processEvent();
	}
	else if(!sim->isFinishingBusy() && !sim->partQueueIsEmpty(2))
	{
		startAssembly = new StartAssembly(Event::getTime(), sim, pNumber);
		startAssembly->processEvent();
	}
	else
	{
		sim->getNextArrival();
	}
}
PartArrival::~PartArrival() {}

