// CLASS: PriorityQueue.cpp
//
// Author: Rhushabh Patel, 7833416
//
// REMARKS: ...
//
//-----------------------------------------

#include "PriorityQueue.h"
#include "Node.h"
#include "Event.h"
#include "ListItem.h"
#include <iostream>
#include <string>
#include "Ordereditem.h"

using namespace std;

PriorityQueue::PriorityQueue() :pFront(nullptr), pBack(nullptr), pSize(0){}

int PriorityQueue::getPSize() { return pSize; }
bool PriorityQueue::isPEmpty() { return pSize == 0; }
ListItem* PriorityQueue::getFront()
{
	return pFront->getItem();
}

void PriorityQueue::insert(ListItem* item) {
	Node* curr = pFront;
	Event* newEvent;
	newEvent = dynamic_cast<Event*>(item);
	
	if (pFront== nullptr)
	{
		pFront = new Node(item, nullptr);//dynamic_cast<Event*>(item)
		pBack = pFront;
	}
	else {

		Node* prev = nullptr;
		Event * e = dynamic_cast<Event*>(pFront->getItem());
		while (e->compareTo(newEvent) > 0)
		{
			prev = curr;
			if (curr->getNext() != nullptr) {
				e = dynamic_cast<Event*>(curr->getItem());// edge case if any other class of event is added
				curr = curr->getNext();
			}
			else
			{
				break;
			}
		}
		if (curr != nullptr) {
			if (prev != nullptr)
			{
				Node* temp = new Node(item, curr);
				prev->setNext(temp);
			}
		}
		else if(curr == prev)
		{
			prev->setNext(new Node(item, nullptr));
			pBack = prev->getNext();
		}
			

		
	}
	pSize++;
}

ListItem* PriorityQueue::pDelete()
{
	ListItem* theItem = nullptr;
	Node* theNode = pFront;
	if (pFront != nullptr) {
		theItem = dynamic_cast<Event*> (pFront->getItem());
		// special case: removing last item
		if (pFront == pBack) {
			pFront = nullptr;
			pBack = nullptr;
		}
		else {
			pFront = pFront->getNext();
		}
		delete(theNode);
	}
	pSize--;
	return theItem;
}

void PriorityQueue::print()
{
	
	Node * curr = this->pFront;
	while (curr!=nullptr)
	{
		Event* newEve = dynamic_cast<Event*>( curr->getItem());
		cout << newEve->getTime() <<endl;
		curr = curr->getNext();
	}
}


// destructor
PriorityQueue::~PriorityQueue(){}