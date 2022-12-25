// CLASS: EndAssembly.cpp
//
// Author: Rhushabh, 7833416
//
// REMARKS: the assembiling of the parts will be end here of both station 
//			if finishing station then our product is ready to use
//-----------------------------------------

#include "EndAssembly.h"
#include "ProductArrival.h"
#include "StartAssembly.h"
#include "Simulation.h"
#include "Event.h"
#include <iostream>
#include <string>
using namespace std;

EndAssembly::EndAssembly(int T, Simulation* S, int N) : Event(T, S), pNumber(N) {}


void EndAssembly::processEvent()
{
	Event* startAssembly;
	Event* productArrival;
	
	if (pNumber <=1 )
	{
		sim->setMainStatus(0);
		sim->productInsert();
		sim->setMainStationTime(Event::getTime());
		if (!sim->isMainBusy() && !sim->partQueueIsEmpty(0) && !sim->partQueueIsEmpty(1))
		{
			startAssembly = new StartAssembly(sim->partTime(1), sim, pNumber);
			cout << "Time " << sim->partTime(1) << ":" << "End Assembly At Main station" << endl;
			startAssembly->processEvent();
		}
	}
	if (pNumber == 2)
	{
		sim->setFinishingStatus(0);
		sim->setFinishingStationTime(Event::getTime());
		sim->setTotalTime(sim->getMainStationTime() + sim->getFinishingStationTime() - sim->getDepartureTime());
		if (!sim->partQueueIsEmpty(2))
		{
			productArrival = new ProductArrival(Event::getTime(), sim, pNumber);
			cout << "Time " << productArrival->getTime() << ":" << "End Assembly At Finishing station" << endl;
			productArrival->processEvent();
		}
	}
	
}







EndAssembly::~EndAssembly(){}
