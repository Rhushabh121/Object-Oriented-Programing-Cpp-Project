// CLASS: Simulation.cpp
//
// Author: Rhushabh Patel, 7833416
//
// REMARKS: the purpose of this class is to make products of the parts given
//
//-----------------------------------------

#include "Simulation.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "PriorityQueue.h"
#include "Event.h"
#include "Queue.h"
#include "OrderedItem.h"
#include "PartArrival.h"
#include "StartAssembly.h"
#include "EndAssembly.h"
#include "ProductArrival.h"

using namespace std;

Simulation::Simulation() {
	mainAssemblyTime = 0;
	mainBusy = 0;
	finishingBusy = 0;
	finishingAssemblyTime = 0;
	productQueue = new Queue();
	eventList = new PriorityQueue();
	simulationTime = 0;
	partQueues = new Queue *[3];
	partQueues[0] = new Queue();
	partQueues[1] = new Queue();
	partQueues[2] = new Queue();
	totalTime = 0;
	mainStationTime = 0;
	finishingStationTime = 0;
	totalProduct = 0;
	arrivingT = 0;
	departureT = 0;
}
int Simulation::getSimulationTime() { return simulationTime; }
void Simulation::setSimulationTime(int time) { simulationTime = time; }

// main method for driving the simulation
void Simulation::runSimulation(char* fileName){
	//string line;
	ifile.open(fileName);

	if(!ifile.is_open())
	{
		cout << "Cannot open file" << endl;
	}
	else {
		string line;
		string name;
		getline(ifile, line);
		istringstream iss(line);
		iss >> mainAssemblyTime;
		iss >> finishingAssemblyTime;
		if (!ifile.eof()) {
			getNextArrival();
		}
	}
}
void Simulation::getNextArrival() {
	string line;
	int pNumber = 0;
	int time = 0;
	if (!ifile.eof())
	{
		getline(ifile, line);

		istringstream iss(line);
		iss >> time;
		iss >> pNumber;
		Event* partArrival = new PartArrival(time, this, pNumber);// chnage
		simulationTime = time;
		cout << "Time " << time << ":" << "Part Arrival of P" << pNumber << endl;

		addEvent(partArrival);

		while (!eventList->isPEmpty())
		{
			partArrival = dynamic_cast<Event*>(eventList->pDelete());
			if (partArrival != nullptr) 
			{
				partArrival->processEvent();
			}
		}
		if (!ifile.eof()) {
			getNextArrival();
		}
	}
	else
	{
		ifile.close();
	}

}

void Simulation::Summary()//implement it 
{
	cout << endl << endl;
	cout << "The number of items that have been completely assembled is : " << totalProduct << endl;
	cout << "The avearge time to complerely build a product is " << (totalTime / totalProduct) << endl;
	cout << "The number of parts P0 that are left in queue is : " << partQueues[0]->getSize() << endl;
	cout << "The number of parts P1 that are left in queue is : " << partQueues[1]->getSize() << endl;
	cout << "The number of parts P2 that are left in queue is : " << partQueues[2]->getSize() << endl;
	cout << "The number of partialy assembled products that are left in the queue is : " << productQueue->getSize() << endl;
}

// insert method for parts which will insert different parts in there own queue
void Simulation::insertPart(ListItem* item, int pNumber)
{
	partQueues[pNumber]->enqueue(item);
}
// remove part from given part name
void Simulation::removePart(int part)
{
	partQueues[part]->dequeue();
}
// check part queue is empty
bool Simulation::partQueueIsEmpty(int i)
{
	return partQueues[i]->isEmpty();
}
// it will return the time of entered part
int Simulation::partTime(int pNumber)
{
	return ((Event*)partQueues[pNumber]->getFront())->getTime();
}
//will insert parts from parts queue
void Simulation::productInsert()
{
	productQueue->enqueue(partQueues[0]->dequeue());
	productQueue->enqueue(partQueues[1]->dequeue());
}
// remove method for product queue
void Simulation::produtRemove()
{
	productQueue->dequeue();
	productQueue->dequeue();
}
// product queue is empty check method
bool Simulation::productCheck()
{
	return productQueue->isEmpty();
}

// add an event to event queue.
void Simulation::addEvent(Event* event){
	eventList->insert(event);
}

// read next arrival from file and add it to the event queue.


// getters and setters for station statuses.
void Simulation::setTotalTime(int time)
{
	totalTime += time;
}
int Simulation::getTotalTime()
{
	return totalTime;
}
bool Simulation::isMainBusy() { return mainBusy; }
bool Simulation::isFinishingBusy() { return finishingBusy; }
void Simulation::setMainStatus(bool status) { mainBusy = status; }
void Simulation::setFinishingStatus(bool status) { finishingBusy = status; }
int Simulation::getMainAssemblyTime() {
	return mainAssemblyTime;
}
int Simulation::getFinishingAssemblyTime() {
	return finishingAssemblyTime;
}
int Simulation::getMainStationTime()
{
	return mainStationTime;
}
void Simulation::setMainStationTime(int time)
{
	mainStationTime = time;
}
int Simulation::getFinishingStationTime()
{
	return finishingStationTime;
}
void Simulation::setFinishingStationTime(int time)
{
	finishingStationTime = time;
}
int Simulation::getTotalProduct()
{
	return totalProduct;
}
void Simulation::setTotalProduct()
{
	totalProduct += 1;
}
int Simulation::getDepartureTime()
{
	return departureT;
}
void Simulation::SetDepartureTime(int time)
{
	departureT = time;
}



Simulation::~Simulation(){}
