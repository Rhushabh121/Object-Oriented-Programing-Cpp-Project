// CLASS: PriorityQueue.h
//
// Author: Rhushabh Patel, 7833416
//
// REMARKS: ...
//
//-----------------------------------------
#pragma once
#include "ListItem.h"
class Node;
//#include "Event.h"


class PriorityQueue{
private:
	Node* pFront; // front of queue.
	Node* pBack; // back of queue
	int pSize;
public:
	PriorityQueue();
	int getPSize();
	bool isPEmpty();
	void insert(ListItem* item);
	ListItem* getFront(); // look at first item in queue.
	ListItem* pDelete(); // remove first item from queue.
	void print();
	~PriorityQueue();


};

