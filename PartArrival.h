// CLASS: PartArrival.h
//
// Author: Rhushabh Patel, 7833416
//
// REMARKS: ...
//
//-----------------------------------------
#pragma once
#include <string>
#include "Event.h"
using namespace std;

class PartArrival : public Event
{
private:
	int pNumber;
public:
	PartArrival(int time, Simulation *sim, int pNumber);
	void processEvent();
	~PartArrival();

};


