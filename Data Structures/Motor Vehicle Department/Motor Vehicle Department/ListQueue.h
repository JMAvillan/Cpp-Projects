#ifndef _LIST_QUEUE
#define _LIST_QUEUE

#include "LinkedList.h"
#include "PrecondViolatedExcep.h"


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
	ItemType getEntry(int position) const;
	int getLenght() const;
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

template <class ItemType>
ItemType ListQueue<ItemType>::getEntry(int position) const {
	return listPtr->getEntry(position);
}

template<class ItemType>
void ListQueue<ItemType>::display() const {
	//ListQueue<ItemType> temp = listPtr;
	for (int i = 1; i <= listPtr->getLength(); i++) {
		cout << i << ". " << listPtr->getEntry(i) << endl;
	}
}


template<class ItemType>
int ListQueue<ItemType>::getLenght() const {
	return this->listPtr->getLength();
}


#endif