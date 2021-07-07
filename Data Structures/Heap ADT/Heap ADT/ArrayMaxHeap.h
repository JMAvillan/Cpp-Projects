//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Array-based implementation of the ADT heap.
 Listing 17-2.
 @file ArrayMaxHeap.h */

#ifndef _ARRAY_MAX_HEAP
#define _ARRAY_MAX_HEAP

//#include "HeapInterface.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class ArrayMaxHeap : public HeapInterface<ItemType>
{
private:
	static const int ROOT_INDEX = 0;        // Helps with readability
	static const int DEFAULT_CAPACITY = 21; // Small capacity to test for a full heap
	ItemType* items;                        // Array of heap items
	int itemCount;                          // Current count of heap items
	int maxItems;                           // Maximum capacity of the heap

	// ---------------------------------------------------------------------
	// Most of the private utility methods use an array index as a parameter
	// and in calculations. This should be safe, even though the array is an
	// implementation detail, since the methods are private.
	// ---------------------------------------------------------------------

	// Returns the array index of the left child (if it exists).
	int getLeftChildIndex(const int nodeIndex) const;

	// Returns the array index of the right child (if it exists).
	int getRightChildIndex(int nodeIndex) const;

	// Returns the array index of the parent node.
	int getParentIndex(int nodeIndex) const;

	// Tests whether this node is a leaf.
	bool isLeaf(int nodeIndex) const;

	// Converts a semiheap to a heap.
	void heapRebuild(int subTreeRootIndex);

	// Creates a heap from an unordered array.
	void heapCreate();

public:
	ArrayMaxHeap();
	ArrayMaxHeap(const ItemType someArray[], const int arraySize);
	virtual ~ArrayMaxHeap();

	// HeapInterface Public Methods:
	bool isEmpty() const;
	int getNumberOfNodes() const;
	int getHeight() const;
	ItemType peekTop() const throw(PrecondViolatedExcep);
	bool add(const ItemType& newData);
	bool remove();
	void clear();
}; // end ArrayMaxHeap

template<class ItemType>
int ArrayMaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const
{
	return (2 * nodeIndex) + 1;
}  // end getLeftChildIndex

template<class ItemType>
int ArrayMaxHeap<ItemType>::getRightChildIndex(const int nodeIndex) const
{
	return (2 * nodeIndex) + 2;
}  // end getRightChildIndex

template<class ItemType>
int ArrayMaxHeap<ItemType>::getParentIndex(int nodeIndex) const
{
	return (floor((nodeIndex - 1) / 2));
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isLeaf(int nodeIndex) const
{
	return (getRightChildIndex(nodeIndex) == NULL && getLeftChildIndex(nodeIndex) == NULL);
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(int subTreeRootIndex)
{

	int rightChildIndex, largeChildIndex;
	largeChildIndex = getLeftChildIndex(subTreeRootIndex);
	if (isLeaf())
	{
		rightChildIndex = largeIndex + 1;
		if (this->items[rightChildIndex] > this->items[largeChildIndex])
		{
			largeChildIndex = rightChildIndex;
		}
		if (this->items[ROOT_INDEX] < this->items[largeChildIndex])
		{
			//swap
			ItemType temp;
			temp.add(this->peekTop());
			this->items[ROOT_INDEX] = this->items[largeChildIndex];
			this->items[largeChildIndex] = temp.peekTop();
			heapRebuild(largeChildIndex);
		}
	}
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::heapCreate()
{
	for (int index = itemCount / 2; index >= 0; index--)
	{
		heapRebuild(index);
	}  // end for
}  // end heapCreate

template<class ItemType>
bool ArrayMaxHeap<ItemType>::add(const ItemType& newData)
{
	this->itemCount[this->itemCount] = newData;
	int newDataIndex = this->itemCount,
		parentIndex;S
	while ((newDataIndex>=0) && !inPlace())
}
template<class ItemType>
bool ArrayMaxHeap<ItemType>::remove()
{
	//copy the item from the last node into the root
	this->items[0] = this->items[this->itemCount];

	//remove the last node
	this->itemCount--;
	
	this->heapRebuild(0);
}

template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(const ItemType someArray[], const int arraySize) :
	itemCount(arraySize), maxItems(2 * arraySize)
{
	// Allocate the array
	items = new ItemType[2 * arraySize];

	// Copy given values into the array
	for (int i = 0; i < itemCount; i++)
		items[i] = someArray[i];

	// Reorganize the array into a heap
	heapCreate();
} // end constructor

template<class ItemType>
ItemType ArrayMaxHeap<ItemType>::peekTop() const throw(PrecondViolatedExcep)
{
	if (isEmpty())
		throw PrecondViolatedExcep("Attempted peek into an empty heap.");

	return items[0];
} // end peekTop



#endif
