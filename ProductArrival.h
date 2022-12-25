// CLASS: ProductArrival.h
//
// Author: Rhushabh Patel, 7833416
//
// REMARKS: ...
//
//-----------------------------------------
#pragma once
#include <string>
#include "Event.h"
#include "PartArrival.h"
using namespace std;
class ProductArrival : public Event
{
private:
	int pNumber;
public:
	

	ProductArrival(int time, Simulation *sim, int pNumber);
	void processEvent();
	~ProductArrival();

};
