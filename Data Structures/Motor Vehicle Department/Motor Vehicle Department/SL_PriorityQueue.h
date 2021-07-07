#ifndef SL_PRIORITY_QUEUE
#define SL_PRIORITY_QUEUE

#include "LinkedSorted.h"
#include "PrecondViolatedExcep.h"
using namespace std;

template<class ItemType>
class SL_PriorityQueue
{
private:
    LinkedSortedList<ItemType>* slistPtr;  // Pointer to sorted list of
                                           // items in the priority queue

public:
    SL_PriorityQueue();
    SL_PriorityQueue(const SL_PriorityQueue& pq);
    ~SL_PriorityQueue();

    bool isEmpty() const;
    bool add(const ItemType& newEntry);
    bool remove();
    int getLenght() const;
    ItemType getEntry(int index) const;
    int getNodeIndexBefore(const ItemType& anEntry) const;
    void insertSpecial(const ItemType& newEntry);
    int getPosition(const ItemType& newEntry) const;
    void removeSorted(const ItemType& newEntry);


    /** @throw PrecondViolatedExcep if priority queue is empty. */
    ItemType peek() const throw(PrecondViolatedExcep);

}; // end SL_PriorityQueue

template <class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue() {
    slistPtr = new LinkedSortedList<ItemType>();
}

template <class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue(const SL_PriorityQueue& pq)
{
    slistPtr->copyChain(pq.slistPtr);
}

template< class ItemType>
SL_PriorityQueue<ItemType>::~SL_PriorityQueue() {
    delete slistPtr;
    slistPtr = nullptr;
}

template<class ItemType>
bool SL_PriorityQueue<ItemType>::add(const ItemType& newEntry)
{
    slistPtr->insertSorted(newEntry);
    return true;
}  // end add

template<class ItemType>
bool SL_PriorityQueue<ItemType>::remove()
{
    // The highest priority item is at the end of the sorted list
    return slistPtr->remove(slistPtr->getLength());
}  // end remove

template <class ItemType>
bool SL_PriorityQueue<ItemType>::isEmpty() const {
    return slistPtr->isEmpty();
}

template <class ItemType>
ItemType SL_PriorityQueue<ItemType>::peek() const throw(PrecondViolatedExcep)
{
    try {
        if (isEmpty())
            throw PrecondViolatedExcep("List is empty.\n");
        else
        {
            return slistPtr->getEntry(slistPtr->getLength());
        }
    }
    catch (PrecondViolatedExcep e) {
        e;
    }

}

template <class ItemType>
ItemType SL_PriorityQueue<ItemType>::getEntry(int index) const {
   return slistPtr->getEntry(index);
}


template <class ItemType>
int SL_PriorityQueue<ItemType>::getLenght() const {
  return slistPtr->getLength();

}

template<class ItemType>
int SL_PriorityQueue<ItemType>::getNodeIndexBefore(const ItemType& anEntry) const
{
   return slistPtr->getNodeIndexBefore(anEntry);
}

template <class ItemType>
void SL_PriorityQueue<ItemType>::insertSpecial(const ItemType& newEntry) {
    slistPtr->insertSpecial(newEntry);
}

template <class ItemType>
int SL_PriorityQueue<ItemType>::getPosition(const ItemType& newEntry) const
{
return this->slistPtr->getPosition(newEntry);
}

template <class ItemType>
void SL_PriorityQueue<ItemType>::removeSorted(const ItemType& newEntry) {

    this->slistPtr->removeSorted(newEntry);
}

#endif

