//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT queue: ADT list implementation.
 Listing 14-1.
 @file ListQueue.h */

#ifndef _LIST_QUEUE
#define _LIST_QUEUE

#include "LinkedList.h"
#include "PreconditionViolatedExcep.h"


template<class ItemType>
class ListQueue
{
private:
	LinkedList<ItemType>* listPtr; // Pointer to list of queue items

public:
	ListQueue();
	ListQueue(const ListQueue& aQueue);
	~ListQueue();
	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();

	/** @throw  PrecondViolatedExcep if queue is empty. */
	ItemType peekFront() const throw(PrecondViolatedExcep);

	void display() const;
	// void fileFilter();
	 //bool fileCompare() const;
}; // end ListQueue

template<class ItemType>
ListQueue<ItemType>::ListQueue()
{
	listPtr = new LinkedList<ItemType>();
}  // end default constructor

template<class ItemType>
ListQueue<ItemType>::ListQueue(const ListQueue& aQueue) : listPtr(aQueue.listPtr)
{
}  // end copy constructor

template<class ItemType>
ListQueue<ItemType>::~ListQueue()
{
}  // end destructor

template<class ItemType>
bool ListQueue<ItemType>::isEmpty() const
{
	return listPtr->isEmpty();
}  // end isEmpty

template<class ItemType>
bool ListQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	return listPtr->insert(listPtr->getLength() + 1, newEntry);
}  // end enqueue

template<class ItemType>
bool ListQueue<ItemType>::dequeue()
{
	return listPtr->remove(1);
}  // end dequeue

template<class ItemType>
ItemType ListQueue<ItemType>::peekFront() const throw(PrecondViolatedExcep)
{
	if (isEmpty())
		throw PrecondViolatedExcep("peekFront() called with empty queue.");

	// Queue is not empty; return front
	return listPtr->getEntry(1);
}  // end peekFront
// End of implementation file.

template<class ItemType>
void ListQueue<ItemType>::display() const {
	//ListQueue<ItemType> temp = listPtr;
	for (int i = 1; i < listPtr->getLength(); i++) {
		cout << listPtr->getEntry(i) << endl;
	}
	cout << endl;
}
/*
template<class ItemType>
void ListQueue<ItemType>::fileFilter() {
	ListQueue<char>
	ifstream infile;
	infile.open("Character queue.txt");
	if (!infile)
		cout << "File failed to open!" << endl;
	infile >>

}
template<class ItemType>
bool ListQueue<ItemType>::fileCompare() const {}
/*10. File Filter
Write a program that opens a text file and reads its contents into a queue of characters.
The program should then dequeue each character, convert it to uppercase, and store
it in a second file.
11. File Compare
Write a program that opens two text files and reads their contents into two separate
queues.The program should then determine whether the files are identical by comparing
the characters in the queues.When two nonidentical characters are encountered,
the program should display a message indicating that the files are not the same.If both
queues contain the same set of characters, a message should be displayed indicating
that the files are identical.
*/
//#include "ListQueue.cpp"
#endif