// CLASS: StartAssembly.h
//
// Author: Rhushabh Patel, 7833416
//
// REMARKS: ...
//
//-----------------------------------------
#pragma once
#include "Event.h"
#include "PartArrival.h"

class StartAssembly : public Event
{
private:
	int pNumber;
public:
	StartAssembly(int time, Simulation*sim, int PNumber);
	void processEvent();
	~StartAssembly();

};

