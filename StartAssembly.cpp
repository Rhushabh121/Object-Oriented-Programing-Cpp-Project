// CLASS: StartAssembly.cpp
//
// Author: Rhushabh Patel, 7833416
//
// REMARKS: it will start assembling the parts depend on which station 
//
//-----------------------------------------

#include "StartAssembly.h"
#include "Event.h"
#include "Simulation.h"
#include "EndAssembly.h"
#include <iostream>
#include <string>
using namespace std;

StartAssembly::StartAssembly(int T, Simulation*S, int N):Event(T,S), pNumber(N){}

void StartAssembly::processEvent(){
	int departureTime = sim->partTime(pNumber);
	Event* endAssembly;


	if ((pNumber == 0 || pNumber == 1) && !sim->isMainBusy())
	{
		cout << "Time " << departureTime << ":" << "Start Assembly At Main station" << endl;
		departureTime += sim->getMainAssemblyTime();
		sim->setMainStatus(1);
		endAssembly = new EndAssembly(departureTime, sim, pNumber);
		if (departureTime == sim->getSimulationTime())
		{
			endAssembly->processEvent();
		}
		else
		{
			sim->addEvent(endAssembly);
		}
	}
	else if(pNumber == 2 && !sim->partQueueIsEmpty(2) && !sim->isFinishingBusy())
	{
		cout << "Time " << departureTime << ":" << "Start Assembly At Finishing station" << endl;
		departureTime += sim->getFinishingAssemblyTime();
		sim->setFinishingStatus(1);
		endAssembly = new EndAssembly(departureTime, sim, pNumber);
		if (departureTime == sim->getSimulationTime())
		{
			endAssembly->processEvent();
		}
		else
		{
			sim->addEvent(endAssembly);
		}
	}
	

}




StartAssembly::~StartAssembly() {}