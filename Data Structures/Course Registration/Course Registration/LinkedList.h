#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class LinkedList
{
private:
	Node<ItemType>* headPtr; // Pointer to first node in the chain;
							 // (contains the first entry in the list)
	int itemCount;           // Current count of list items 
	//Node<ItemType>* tailPtr;

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
	bool insert(int newPosition, const ItemType& newEntry) throw(PrecondViolatedExcep);
	bool remove(int position);
	void clear();

	/** @throw PrecondViolatedExcep if position < 1 or
									   position > getLength(). */
	ItemType getEntry(int position) const throw(PrecondViolatedExcep);

	/** @throw PrecondViolatedExcep if position < 1 or
									   position > getLength(). */
	//void setEntry(int position, const ItemType& newEntry)	throw(PrecondViolatedExcep);

	bool removeIntact(int anEntry);
	ItemType operator [] (int);
}; // end LinkedList

#include <cassert>

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), /*tailPtr(nullptr)*/ itemCount(0)
{
}  // end default constructor

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) : headPtr(aList.headPtr),/* tailPtr(aList.tailPtr)*/ itemCount(aList.itemCount)
{
}  // end copy constructor

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
	clear();
	/*while (headPtr != NULL) {
		Node<ItemType>* current = headPtr;
		headPtr = headPtr->getNext();
		delete current;
	}*/
	//tailPtr = NULL;
	//itemCount = 0;
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
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry) throw (PrecondViolatedExcep)
{
	bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
	bool toErase = false;
	Node<ItemType>* currPtr;
	if (newPosition > itemCount)
		currPtr = nullptr;
	else
		currPtr = getNodeAt(newPosition);

	if (ableToInsert)
	{
		// Create a new node containing the new entry 
		Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

		// Attach node to beginning of list when list is not empty
		if (newPosition == 1 && itemCount != 0)
		{
				// Insert new node at beginning of chain
				newNodePtr->setNext(headPtr->getNext());
				newNodePtr->setPrev(headPtr->getPrevious());
				headPtr = newNodePtr;
				toErase = true;
				//tailPtr = newNodePtr;

				//newNodePtr->previous = headPtr->previous;
				//headPtr->previous->next = newNodePtr;
				//headPtr->previous = newNodePtr;
				//newNodePtr->next = headPtr;
		}
		//add to empty list
		else if (newPosition <= itemCount + 1 && itemCount !=0)
		{
			Node<ItemType>* prevPtr;
			Node<ItemType>* nextPtr;

			// Find node that will be before new node
			if (newPosition > itemCount)
			{
				prevPtr = getNodeAt(itemCount);
				nextPtr = nullptr;
			}
			else
			{
				prevPtr = getNodeAt(newPosition)->getPrevious();
				nextPtr = getNodeAt(newPosition)->getNext();
				nextPtr->setPrev(newNodePtr);
			}

			// Insert new node after node to which prevPtr points
			newNodePtr->setNext(nextPtr);
			newNodePtr->setPrev(prevPtr);
			prevPtr->setNext(newNodePtr);
			toErase = true;

			
		}
		else
		{
			// Insert new node at beginning of chain	
			newNodePtr->setNext(headPtr);
			//headPtr->setPrev(newNodePtr);
			headPtr = newNodePtr;
			toErase = true;
		}
	}// end if
	else
		{
			string message = "Error: New position has to exist in the list or be a new addition to the list.\n";
		/*	message += "(Cannot be higher than ";
			message += static_cast((string)(getLenght() + 1));
			message += " as of this moment.)";*/
			throw PrecondViolatedExcep(message);
		}

	if (toErase)
		{
			delete currPtr;
			currPtr = nullptr;
			if (newPosition == itemCount + 1)
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
			//headPtr->setPrev(curPtr->getPrevious()); //Is this right?
		}
		else if (position > 1 || position < itemCount)
		{
			// Find node that is before the one to delete
			Node<ItemType>* prevPtr = getNodeAt(position)->getPrevious();
			Node<ItemType>* prevPtr2 = prevPtr->getPrevious();

			// Point to node to delete
			curPtr = prevPtr->getNext();

			// Disconnect indicated node from chain by connecting the
			// prior node with the one after
			prevPtr->setNext(curPtr->getNext());

			prevPtr->setPrev(prevPtr2); 
			
		}
		else {
			// Find node that is before the one to delete
			Node<ItemType>* prevPtr = getNodeAt(position - 1);

			// Point to node to delete
			curPtr = prevPtr->getNext();

			// Disconnect indicated node from chain by connecting the
			// prior node with the one after
			prevPtr->setNext(curPtr->getNext());
			//
			//tailPtr = prevPtr;
			prevPtr->setPrev(curPtr->getPrevious()); //TODO check if this is right
		}// end if

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
//template<class ItemType>
//void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry)
//throw(PrecondViolatedExcep) {
//	bool ableToSet = (position >= 1) && (position <= itemCount);
//	if (ableToSet)
//	{
//		Node<ItemType>* nodePtr = getNodeAt(position);
//		nodePtr->setItem(newEntry);
//	}
//	else
//	{
//		string message = "setEntry() called with an empty list or ";
//		message = message + "invalid position.";
//		throw(PrecondViolatedExcep(message));
//	}  // end if
//} //end setEntry

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
			//This I added to test whether the skip node is tailPtr
			else if (skipNode == this->tailPtr) {
				//tailPtr = lastNode; //If this is the same as if the last else if, then the course
				//of action is to assign last node to tailPtr.
			}
			//TODO check if this makes sense
			else
			{
				lastNode->setNext(curNode->getNext());
				//Maybe the code we need to deal with the previous pointer stuff
				lastNode->setPrev(curNode->getPrevious()); //lastNode->next->previous =curNode->getPrevious()... nope.
				lastNode->getNext()->setPrevious(curNode->getPrevious()); //is this it?
				//
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
	return getEntry[index];
}
#endif 