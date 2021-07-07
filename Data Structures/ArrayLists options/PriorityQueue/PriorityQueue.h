/** ADT priority queue: ADT sorted list implementation.
 Listing 14-6.
 @file PriorityQueue.h */

#ifndef _PRIORITY_QUEUE
#define _PRIORITY_QUEUE

#include "LinkedSortedList.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class PriorityQueue{

private:
	LinkedSortedList<ItemType>* slistPtr;  // Pointer to sorted list of
										   // items in the priority queue

public:
	PriorityQueue();
	PriorityQueue(const PriorityQueue& pq);
	~PriorityQueue();

	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove();

	/** @throw PrecondViolatedExcep if priority queue is empty. */
	ItemType peek() const throw(PrecondViolatedExcep);
}; // end PriorityQueue

template<class ItemType>
bool PriorityQueue<ItemType>::add(const ItemType& newEntry)
{
	slistPtr->insertSorted(newEntry);
	return true;
}  // end add

template<class ItemType>
bool PriorityQueue<ItemType>::remove()
{
	// The highest priority item is at the end of the sorted list
	return slistPtr->remove(slistPtr->getLength());
}  // end remove


#endif
