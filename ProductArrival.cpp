// CLASS: ProductArrival.cpp
//
// Author: Rhushabh Patel, 7833416
//
// REMARKS: we get an fully assembled product here 
//
//-----------------------------------------

#include "ProductArrival.h"
#include "Event.h"
#include "Simulation.h"
#include "StartAssembly.h"
#include "PartArrival.h"
#include <iostream>
#include <string>
using namespace std;

ProductArrival::ProductArrival(int T, Simulation* S, int N) :Event(T,S) , pNumber(N){}

void ProductArrival::processEvent()
{
	Event* startAssembly;
	if (pNumber == 2) {
		cout << "Time " << Event::getTime() << ":" << "Product Arrival" << endl;
		sim->setTotalProduct();
		sim->produtRemove();
		sim->removePart(2);
		sim->produtRemove();
	}
	else if (!sim->isFinishingBusy() && (pNumber == 1|| pNumber == 0))
	{
		startAssembly = new StartAssembly(Event::getTime(), sim, pNumber);
		startAssembly->processEvent();
	}
}

ProductArrival::~ProductArrival() {}
