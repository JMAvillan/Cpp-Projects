#ifndef _ARRAY_BAG
#define _ARRAY_BAG
#include <iostream>
#include "SpeakerInfo.h"

using namespace std;

template<class ItemType>
class ArrayBag
{
private:
	static const int DEFAULT_CAPACITY = 6; // Small size to test for a full bag
	ItemType items[DEFAULT_CAPACITY];      // Array of bag items
	int itemCount;                         // Current count of bag items 
	int maxItems;                          // Max capacity of the bag

	// Returns either the index of the element in the array items that
	// contains the given target or -1, if the array does not contain 
	// the target.
	int getIndexOf(const ItemType& target) const;

public:
	ArrayBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
	//vector<ItemType> toVector() const;

	bool addToBeginning(const ItemType& anEntry);
	bool addToIndex(const ItemType& anEntry, int index);
	bool completelyRemove(const ItemType& anEntry);
	int binarySearch(int first, int mid, const ItemType& target);
	void sort();

	void showInfo()const;
	void askInfo();
	int getMaxItems()const;
	void incrementToIndex(int index);
	bool checkRemainding(int x);
	bool checkBlankSpaces();

	//Operator Overloading
	bool operator== (const ArrayBag<ItemType>& aBag) const;
	int operator== (const ItemType& anItem) const;
	friend ostream& operator << (ostream& out, const ArrayBag<ItemType>& aBag);
	friend istream& operator >> (istream& in, ArrayBag<ItemType>& aBag);
	const ItemType& operator [] (int) const;
	ItemType& operator [] (int);


}; // end ArrayBag

template<class ItemType>
ArrayBag<ItemType>::ArrayBag() : itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if

	return hasRoomToAdd;
}  // end add

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
	int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		ItemType temp;
		itemCount--;
		items[locatedIndex] = temp;
	}  // end if

	return canRemoveItem;
}  // end remove

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
	int curIndex = 0;       // Current array index
	while (curIndex < itemCount)
	{
		if (items[curIndex] == anEntry)
		{
			frequency++;
		}  // end if

		curIndex++;          // Increment to next entry
	}  // end while

	return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

//template<class ItemType>
//vector<ItemType> ArrayBag<ItemType>::toVector() const
//{
//	vector<ItemType> bagContents;
//	for (int i = 0; i < itemCount; i++)
//		bagContents.push_back(items[i]);
//
//	return bagContents;
//}  // end toVector

// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
	int result = -1;
	int searchIndex = 0;

	// If the bag is empty, itemCount is zero, so loop is skipped
	while (!found && (searchIndex < itemCount))
	{
		if (items[searchIndex] == target)
		{
			found = true;
			result = searchIndex;
		}
		else
		{
			searchIndex++;
		}  // end if
	}  // end while

	return result;
}  // end getIndexOf

template <class ItemType>
bool ArrayBag<ItemType>::addToBeginning(const ItemType& anEntry)
{ 
	this->addToIndex(anEntry, 0);
}
template <class ItemType>
bool ArrayBag<ItemType>::addToIndex(const ItemType& anEntry, int index)
{
	bool inBounds = index <= this->maxItems; //&& index < this->itemCount;

	if (inBounds)
	{
		this->items[index] = anEntry;
		incrementToIndex(index);
		return true;
	}
	return false; //not in bounds or list is full;
}

template <class ItemType>
void ArrayBag<ItemType>::incrementToIndex(int index)
{
	if (index >= this->itemCount)
	{
		itemCount++;
		incrementToIndex(index);
		if (this->itemCount == index)
			itemCount++;
	}// end if statement
}//end incrementToIndex

template <class ItemType>
bool ArrayBag<ItemType>::completelyRemove(const ItemType& anEntry)
{
	int locatedIndex = getIndexOf(anEntry);
	bool canRemove = !isEmpty() && locatedIndex != -1;
	if (canRemove)
	{
		this->remove(anEntry);
		for (int x = locatedIndex; x < itemCount; x++)
		{
			(*this)[x] = (*this)[x+1];
		}
		checkRemainding(1);
		return true;
	}
	return false;
}

template <class ItemType>
bool ArrayBag<ItemType>::checkRemainding(int x)
{
	ItemType temp;
	bool inBounds = !(x + this->itemCount >= this->maxItems);
		if (inBounds)
		{
			if (!((*this)[itemCount + x] == temp) && (this->itemCount + x < this->maxItems))
			{
				this->addToIndex(temp, itemCount + x);
				itemCount--;
			}
			else
				return true;

			checkRemainding(++x);
		}
		return false;
}
template <class ItemType>
bool ArrayBag<ItemType>::checkBlankSpaces()
{
	ItemType check;
	bool swap;
	int blankItems = this->getFrequencyOf(check);
	do 
	{ItemType temp;
		swap = false;
		int endBlankItems = 0;
		for (int x = this->itemCount - 1; x >= 0; x--)
		{
			if ((*this)[x] == temp)
				endBlankItems++;
			else
				x = -1;
		}
		if (endBlankItems == blankItems)
		{
			this->itemCount -= blankItems;
			return true;
		}

		for (int count = 0; count < this->itemCount; count++)
		{
			 if ((*this)[count] == temp && count + 1 != this->itemCount)
			{
				temp = (*this)[count + 1];
				(*this)[count + 1] = (*this)[count];
				(*this)[count] = temp;
				swap = true;
			}
		}
	} while (swap);
	return true;
}

template <class ItemType>
int ArrayBag<ItemType>::getMaxItems() const
{
	return maxItems;
}

template <class ItemType>
int ArrayBag<ItemType>::binarySearch(int first, int last, const ItemType& target) {
	int index;
	if (first > last)
		index = -1;
	else
	{
		int mid = (first + last) / 2;
		if (target == (*this)[mid])
			index = mid;
		else if (target < (*this)[mid])
			index = binarySearch( first, mid - 1, target);
		else
			index = binarySearch(mid + 1, last, target);
	}
	return index;
}
template<class ItemType>
void ArrayBag<ItemType>::sort()
{
	bool swap;
	ItemType temp;

	do {
		swap = false;
		for (int count=0; count < this->itemCount; count++)
		{
			if (count+1 !=this->itemCount)
			if ((*this)[count] > (*this)[count + 1])
			{
				temp = (*this)[count];
				(*this)[count] = (*this)[count + 1];
				(*this)[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
	checkBlankSpaces();
}

template<class ItemType>
void ArrayBag<ItemType>::showInfo() const {

	cout << "List Details:\n";
	for (int x = 0; x < this->itemCount; x++)
	{
		cout << x + 1 << "." << (*this)[x];
	}
}

template<class ItemType>
void ArrayBag<ItemType>::askInfo() {
	for (int x = 0; x < this->getMaxItems(); x++)
	{
		if (x != 0)
		cin.ignore();
		cout << "Speaker #" << x + 1 << endl;
		cin >> (*this)[x];
		itemCount++;
		cout << endl;
	}
	this->sort();
}

/************************************
*		Operator Overloading		*
************************************/
template <class ItemType>
bool ArrayBag<ItemType>::operator== (const ArrayBag<ItemType>& aBag) const
{
	if (this->getCurrentSize() != aBag.getCurrentSize())
		return false;

	for (int x = 0; x < this->getCurrentSize(); x++)
	{
		if (aBag[x] != (*this)[x])
		{
			return false;
		}
	}

	return true;
}

template <class ItemType>
int ArrayBag<ItemType>::operator== (const ItemType& anItem) const
{
	return this->getIndexOf(anItem);
}
template <class ItemType>
ostream& operator << (ostream& out, const ArrayBag<ItemType>& aBag)
{
	aBag.showInfo();
	return out;
}

template <class ItemType>
istream& operator >> (istream& in, ArrayBag<ItemType>& aBag)
{
	//cout << "Enter the following information: \n";
		aBag.askInfo();
		return in;
}

template<class ItemType>
const ItemType& ArrayBag<ItemType>::operator [] (int index) const
{
	return items[index];
}

template<class ItemType>
ItemType& ArrayBag<ItemType>::operator [] (int index)
{
	return items[index];
}
#endif