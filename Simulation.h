// CLASS: Simulation.h
//
// Author: Rhushabh Patel, 7833416
//
// REMARKS: 
//
//-----------------------------------------
#pragma once
#include <fstream>
#include "ListItem.h"
#include <string>
using namespace std;

class PriorityQueue; // Priority Queue
class Queue; // Queue class - provided to you
class Event; // Event - given to you. 

class Simulation {
private:
    ifstream ifile; // input file to read.
    int simulationTime; // what is the current time of the simulation?
    PriorityQueue *eventList; // priority queue of Events.
    Queue* productQueue; // queue of partially assembled products (for finishing station).
    Queue** partQueues; // *array* of queues of parts for the stations.
    int  mainAssemblyTime; //  how long does the main station take?
    int  finishingAssemblyTime; //  how long does the finishing station take?
	bool mainBusy; // is the main station busy?
	bool finishingBusy; // is the finishing station busy?
    int arrivingT;
    int departureT;
    int totalTime;
    int mainStationTime;
    int finishingStationTime;
    int totalProduct;

public:
    Simulation();

	// you need methods to manipulate product and part queues.
	// [add them here.]
   void removePart(int part);

    void productInsert();
    void produtRemove();
    bool productCheck();
    
    bool partQueueIsEmpty(int i);
    void insertPart(ListItem*item, int pNumber);
        
    int getSimulationTime();
    void setSimulationTime(int time);

    int getTotalTime();
    void setTotalTime(int time);

    int getMainAssemblyTime();
    int getFinishingAssemblyTime();

    int partTime(int pNumber);
        // main method for driving the simulation
    void runSimulation(char* fileName);
    void Summary();

	// add an event to event queue.
	void addEvent (Event*); 

	// read next arrival from file and add it to the event queue. 
    void getNextArrival();
	
	// getters and setters for station statuses.
	bool isMainBusy();
	bool isFinishingBusy();
	void setMainStatus(bool);
	void setFinishingStatus(bool);

    int getMainStationTime();
    void setMainStationTime(int time);

    int getFinishingStationTime();
    void setFinishingStationTime(int time);

    int getTotalProduct();
    void setTotalProduct();

    int getDepartureTime();
    void SetDepartureTime(int time);
    ~Simulation();

};// class Simulation
