#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class LinkedList
{
private:
	Node<ItemType>* headPtr; // Pointer to first node in the chain;
	Node<ItemType>* tailPtr; // (contains the first entry in the list)
	int itemCount;           // Current count of list items 

	// Locates a specified node in this linked list.
	// @pre  position is the number of the desired node;
	//       position >= 1 and position <= itemCount.
	// @post  The node is found and a pointer to it is returned.
	// @param position  The number of the node to locate.
	// @return  A pointer to the node at the given position.
	Node<ItemType>* getNodeAt(int position) const;

public:
	LinkedList();
	LinkedList(const LinkedList<ItemType>& aList);
	virtual ~LinkedList();

	bool isEmpty() const;
	int getLength() const;
	bool insert(int newPosition, const ItemType& newEntry);
	bool remove(int position);
	int roulette(int startingIndex,  int count);
	void clear();

	/** @throw PrecondViolatedExcep if position < 1 or
									   position > getLength(). */
	ItemType getEntry(int position) const throw(PrecondViolatedExcep);

	/** @throw PrecondViolatedExcep if position < 1 or
									   position > getLength(). */
	void setEntry(int position, const ItemType& newEntry)
		throw(PrecondViolatedExcep);

	bool removeIntact(int anEntry);
	ItemType operator [] (int);
	ItemType getPosition(int m);
}; // end LinkedList

#include <cassert>

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr),tailPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) : headPtr(aList.getEntry()), tailPtr(headPtr), itemCount(aList.getLength())
{
}  // end copy constructor

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
	clear();
}  // end destructor

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
	return itemCount;
}  // end getLength

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
	bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
	if (ableToInsert)
	{
		// Create a new node containing the new entry 
		Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

		// Attach new node to chain
		if (newPosition == 1 && itemCount != 0)
		{
			// Insert new node at beginning of chain
			newNodePtr->setNext(headPtr);
			headPtr = newNodePtr;
			tailPtr->setNext(headPtr);
		}
		else if (newPosition == 1)
		{
			// Insert new node at beginning of chain
			headPtr = newNodePtr;
			tailPtr=newNodePtr;
			newNodePtr->setNext(headPtr);

		}
		else //if (newPosition > 1 && newPosition < itemCount + 1)
		{
			// Find node that will be before new node
			Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);

			// Insert new node after node to which prevPtr points
			newNodePtr->setNext(prevPtr->getNext());
			prevPtr->setNext(newNodePtr);
			if	(itemCount + 1 == newPosition)
				tailPtr = newNodePtr;
		}  // end if
		//else {
		//	Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);

		//	// Insert new node after node to which prevPtr points
		//	newNodePtr->setNext(headPtr);
		//	prevPtr->setNext(newNodePtr);
		//}// end if
		itemCount++;  // Increase count of entries
	}
	return ableToInsert;
}  // end insert

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	if (ableToRemove)
	{
		Node<ItemType>* curPtr = nullptr;
		if (position == 1)
		{
			// Remove the first node in the chain
			curPtr = headPtr; // Save pointer to node
			headPtr = headPtr->getNext();
			tailPtr->setNext(headPtr);
		}
		else
		{
			// Find node that is before the one to delete
			Node<ItemType>* prevPtr = getNodeAt(position - 1);

			// Point to node to delete
			curPtr = prevPtr->getNext();

			// Disconnect indicated node from chain by connecting the
			// prior node with the one after
			prevPtr->setNext(curPtr->getNext());
			if(itemCount == position)
				tailPtr = prevPtr;

		}  // end if

		// Return node to system
		curPtr->setNext(nullptr);
		delete curPtr;
		curPtr = nullptr;

		itemCount--;  // Decrease count of entries
	}  // end if

	return ableToRemove;
}  // end remove

template<class ItemType>
void LinkedList<ItemType>::clear()
{
	while (!isEmpty())
		remove(1);
}  // end clear

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
{
	// Enforce precondition
	bool ableToGet = (position >= 1) && (position <= itemCount);
	if (ableToGet)
	{
		Node<ItemType>* nodePtr = getNodeAt(position);
		return nodePtr->getItem();
	}
	else
	{
		string message = "getEntry() called with an empty list or ";
		message = message + "invalid position.";
		throw(PrecondViolatedExcep(message));
	}  // end if
}  // end getEntry

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
	// Debugging check of precondition
	assert((position >= 1) && (position <= itemCount));

	// Count from the beginning of the chain
	Node<ItemType>* curPtr = headPtr;
	for (int skip = 1; skip < position; skip++)
		curPtr = curPtr->getNext();

	return curPtr;
}  // end getNodeAt
//  End of implementation file.

   /** @throw PrecondViolatedExcep if position < 1 or
									  position > getLength(). */
template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry)
throw(PrecondViolatedExcep) {
	bool ableToSet = (position >= 1) && (position <= itemCount);
	if (ableToSet)
	{
		Node<ItemType>* nodePtr = getNodeAt(position);
		nodePtr->setItem(newEntry);
	}
	else
	{
		string message = "setEntry() called with an empty list or ";
		message = message + "invalid position.";
		throw(PrecondViolatedExcep(message));
	}  // end if
} //end setEntry

template<class ItemType>
bool LinkedList<ItemType>::removeIntact(int anEntry)
{
	bool itemRemoved = false;
	if (!(isEmpty()))
	{
		Node<ItemType>* skipNode = getNodeAt(anEntry);
		Node<ItemType>* curNode = this->headPtr;
		Node<ItemType>* lastNode = new Node<ItemType>();
		while (curNode != nullptr && !itemRemoved)
		{
			if (curNode != skipNode)
			{
				lastNode = curNode;
				curNode = curNode->getNext();
			}
			else if (skipNode == this->headPtr)
			{
				headPtr = lastNode;
			}
			else
			{
				lastNode->setNext(curNode->getNext());

				skipNode->setNext(nullptr);
				delete skipNode;
				skipNode = nullptr;

				itemCount--;
				itemRemoved = true;

			}
		}
	}
	return itemRemoved;
}

template <class ItemType>
ItemType LinkedList<ItemType>::operator [] (int index)
{
	return getEntry(index);
}

template <class ItemType>
ItemType LinkedList<ItemType>::getPosition(int m) {
	Node<int>* ptr1 = headPtr, * ptr2 = headPtr;
	while (ptr1->getNext() != ptr1)
	{
		// Find m-th node 
		int count = 1;
		while (count != m)
		{
			ptr2 = ptr1;
			ptr1 = ptr1->getNext();
			count++;
		}

		/* Remove the m-th node */
		ptr2->setNext(ptr1->getNext());
		ptr1 = ptr2->getNext();
	}
	return ptr1->getItem();
}
#endif 
template <class ItemType>
int LinkedList<ItemType>::roulette(int startingIndex, int count)
{
	Node<ItemType>* currNode;
	int indexCounter;
	if (startingIndex > itemCount)
	{
		currNode = headPtr;
		indexCounter = 1;
	}
	else
	{
		currNode = getNodeAt(startingIndex);
		indexCounter = startingIndex;
	}

	Node<ItemType>* prevNode = nullptr;
	for (int x = 2; x <= count; x++)
	{
		if (indexCounter < itemCount)
		{
			prevNode = currNode;
			currNode = currNode->getNext();
			indexCounter++;
		}
		else
		{
			prevNode = currNode;
			currNode = currNode->getNext();
			indexCounter = 1;
		}

	}
	return	indexCounter;
}
