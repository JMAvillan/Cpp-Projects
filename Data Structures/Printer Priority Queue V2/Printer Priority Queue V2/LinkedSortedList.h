#ifndef _LINKED_SORTED_LIST
#define _LINKED_SORTED_LIST

#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class LinkedSortedList
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
   //bool removeSorted(const ItemType& anEntry);
   // int getPosition(const ItemType& newEntry) const;

    // The following methods are the same as given in ListInterface:
    bool isEmpty() const;
    int getLength() const;
    bool remove(int position);
    void clear();
    ItemType getEntry(int position) const throw(PrecondViolatedExcep);
}; // end LinkedSortedList

#include <cassert>

template <class ItemType>
LinkedSortedList<ItemType>:: LinkedSortedList(): headPtr(nullptr), itemCount(0) {
}

template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList<ItemType>& aList)
{
    headPtr = copyChain(aList.headPtr);
}  // end copy constructor
template <class ItemType>
LinkedSortedList<ItemType>::~LinkedSortedList()
{
    this->clear();
    delete headPtr;
}
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
Node<ItemType>* LinkedSortedList<ItemType>::getNodeAt(int position) const
{
    // Debugging check of precondition
    assert((position >= 1) && (position <= itemCount));

    // Count from the beginning of the chain
    Node<ItemType>* curPtr = headPtr;
    for (int skip = 1; skip < position; skip++)
        curPtr = curPtr->getNext();

    return curPtr;
}  // end getNodeAt

template<class ItemType>
bool LinkedSortedList<ItemType>::isEmpty() const
{
    return this->itemCount == 0;
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
        Node<ItemType>* curPtr = nullptr;
        if (position == 1)
        {
            // Remove the first node in the chain
            curPtr = headPtr; // Save pointer to node
            headPtr = headPtr->getNext();
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
void LinkedSortedList<ItemType>::clear()
{
    while (!isEmpty())
        remove(1);
}  // end clear

template<class ItemType>
ItemType LinkedSortedList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
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
#endif