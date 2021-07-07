#ifndef _LINKED_SORTED_LIST
#define _LINKED_SORTED_LIST

#include "SortedListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class LinkedSortedList : public SortedListInterface<ItemType>
{
private:
	Node<ItemType>* headPtr; // Pointer to first node in the chain
	int itemCount;           // Current count of list items

	// Locates the node that is before the node that should or does
	// contain the given entry.
	// @param anEntry  The entry to find.
	// @return  Either a pointer to the node before the node that contains
	//    or should contain the given entry, or nullptr if no prior node exists.
	Node<ItemType>* getNodeBefore(const ItemType& anEntry) const;

	// Locates the node at a given position within the chain.
	Node<ItemType>* getNodeAt(int position) const;

	// Returns a pointer to a copy of the chain to which origChainPtr points.
	Node<ItemType>* copyChain(const Node<ItemType>* origChainPtr);

public:
	LinkedSortedList();
	LinkedSortedList(const LinkedSortedList<ItemType>& aList);
	virtual ~LinkedSortedList();

	void insertSorted(const ItemType& newEntry);
	bool removeSorted(const ItemType& anEntry);
	int getPosition(const ItemType& newEntry) const;

	// The following methods are the same as given in ListInterface:
	bool isEmpty() const;
	int getLength() const;
	bool remove(int position);
	void clear();
	ItemType getEntry(int position) const throw(PrecondViolatedExcep);
}; // end LinkedSortedList

template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList<ItemType>& aList)
{
	headPtr = copyChain(aList.headPtr);
}  // end copy constructor

template<class ItemType>
void LinkedSortedList<ItemType>::insertSorted(const ItemType& newEntry)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
	Node<ItemType>* prevPtr = getNodeBefore(newEntry);

	if (isEmpty() || (prevPtr == nullptr)) // Add at beginning
	{
		newNodePtr->setNext(headPtr);
		headPtr = newNodePtr;
	}
	else // Add after node before
	{
		Node<ItemType>* aftPtr = prevPtr->getNext();
		newNodePtr->setNext(aftPtr);
		prevPtr->setNext(newNodePtr);
	} // end if

	itemCount++;
} // end insertSorted

// Private Methods:

template<class ItemType>
Node<ItemType>* LinkedSortedList<ItemType>::copyChain(const Node<ItemType>* origChainPtr)
{
	Node<ItemType>* copiedChainPtr;
	if (origChainPtr == nullptr)
	{
		copiedChainPtr = nullptr;
	}
	else
	{
		// Build new chain from given one
		copiedChainPtr = new Node<ItemType>(origChainPtr->getItem());
		copiedChainPtr->setNext(copyChain(origChainPtr->getNext()));
	}  // end if

	return copiedChainPtr;
}  // end copyChain

template<class ItemType>
Node<ItemType>* LinkedSortedList<ItemType>::getNodeBefore(const ItemType& anEntry) const
{
	Node<ItemType>* curPtr = headPtr;
	Node<ItemType>* prevPtr = nullptr;

	while ((curPtr != nullptr) && (anEntry > curPtr->getItem()))
	{
		prevPtr = curPtr;
		curPtr = curPtr->getNext();
	} // end while

	return prevPtr;
} // end getNodeBefore

template<class ItemType>
bool LinkedSortedList<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedSortedList<ItemType>::getLength() const
{
	return itemCount;
}  // end getLength

template<class ItemType>
bool LinkedSortedList<ItemType>::remove(int position)
{
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	if (ableToRemove)
	{
		// Remove entry by shifting all entries after the one at
		// position toward the beginning of the array
		// (no shift if position == itemCount)
		for (int fromIndex = position, toIndex = fromIndex - 1; fromIndex < itemCount;
			fromIndex++, toIndex++)
			items[toIndex] = items[fromIndex];

		itemCount--;  // Decrease count of entries
	}  // end if

	return ableToRemove;
}  // end remove

template<class ItemType>
void LinkedSortedList<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
ItemType LinkedSortedList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
{
	// Enforce precondition
	bool ableToGet = (position >= 1) && (position <= itemCount);
	if (ableToGet)
		return items[position - 1];
	else
	{
		string message = "getEntry() called with an empty list or ";
		message = message + "invalid position.";
		throw(PrecondViolatedExcep(message));
	}  // end if
}  // end getEntry


#endif