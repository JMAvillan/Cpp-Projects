#include "IntegerList.h"
#include <iostream>
#include <cstdlib>
using namespace std;

IntegerList::IntegerList(int size)
{
	list = new int[size];
	numElements = size;
	for (int x = 0; x < size; x++)
		list[x] = 0;
}
IntegerList::~IntegerList()
{
	delete[] list;
}

//isValid member function.
//This private member function returns true if the argument 
//is a valid subscript, or false otherwise.

bool IntegerList::isValid(int element) const
{
	bool status;
	if (element < 0 || element >= numElements)
		status = false;
	else
		status = true;
	return status;
}

void IntegerList::setElement(int element, int value)
{
	if (isValid(element))
		list[element] = value;
	else
	{
		cout << "Error: Invalid subscript\n";
		exit(EXIT_FAILURE);
	}
}
int IntegerList::getElement(int index )const
{
	if (isValid(index))
		return list[index];
	else {
		cout << "Error: Invalid subscript\n";
		exit(EXIT_FAILURE);
	}
}
void IntegerList::sortList()
{
	int startScan, minIndex, minValue;
	for (startScan = 0; startScan < (numElements - 1); startScan++)
	{
		minIndex = startScan;
		minValue = list[startScan];
		for (int index = startScan + 1; index < numElements; index++)
		{
			if (list[index] < minValue)
			{
				minValue = list[index];
				minIndex = index;
			}
		}
		list[minIndex] = list[startScan];
		list[startScan] = minValue;
	}
}