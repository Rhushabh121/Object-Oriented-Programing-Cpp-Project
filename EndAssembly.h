// CLASS: EndAssembly.h
//
// Author: Rhushabh Patel, 7833416
//
// REMARKS: ...
//
//-----------------------------------------
#pragma once
#include "Event.h"
#include "PartArrival.h"
class EndAssembly : public Event
{
private:
	int pNumber;
public:
	
	EndAssembly(int time, Simulation * sim, int pNumber);
	void processEvent();
	~EndAssembly();
};

