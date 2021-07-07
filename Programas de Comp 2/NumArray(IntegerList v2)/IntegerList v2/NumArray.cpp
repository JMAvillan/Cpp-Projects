#include "NumArray.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//Overloading operators
ostream& operator << (ostream& out, const NumArray& objList)

	{ cout << "Full List:\n";
		for (int x = 0; x < objList.getNumElement(); x++)
		{
			
			out <<  objList.getElement(x) << " ";

		}
		cout << endl;
		out << "Highest value: " << objList.getHighest() << endl;
			out << "Lowest value: " << objList.getLowest()<< endl;
			out << "Average value: " << objList.getAverage() << endl;
		cout<< endl;
	return out;
}
 istream & operator >> (istream &in, NumArray &objList)
 {
	 for (int x = 0; x < objList.numElements; x++)
	 {
		 cout << (x + 1) << ". Enter number: ";
		 in >> objList.list[x];
	 }
	 objList.sortList();		//array list will be sorted once created
		 return in;
}


 NumArray& NumArray::operator=(const NumArray& objList)
 {
	 if (this->numElements != objList.getNumElement())
	 {
		 delete[]list;
		 this->numElements = objList.getNumElement();
		 list = new double[numElements];
		 for (int x = 0; x < this->numElements; x++)
		 {
			 this->list[x] = objList.getElement(x);
		 }
	 }
	 else 
		 for (int x = 0; x < this->numElements; x++)
		 {
			 this->list[x] = objList.getElement(x);
		 }
	 return *this;
}

 bool NumArray::operator ==(const NumArray& objList) const
 {
	 if (numElements != objList.getNumElement())
		  return false; // arrays of different number of elements
	 
	 for (int i = 0; i < numElements; ++i)
	 if (list[i] != objList.list[i])
	 return false; // Array contents

	 return true;
 }
 bool NumArray::operator != (const NumArray& objList) const
 {
	 if (numElements != objList.getNumElement())
		 return true; // arrays of different number of elements

	 for (int i = 0; i < numElements; ++i)
		 if (list[i] != objList.list[i])
			 return true; // Array contents

	 return false;
 }

 double NumArray::operator[](int subs) const
 {
	return this->getElement(subs);
 }

NumArray::NumArray()
{
	this->list = new double[DEFAULT_SIZE];
	this->numElements = DEFAULT_SIZE;
	for (int x = 0; x < DEFAULT_SIZE; x++)
		this->list[x] = 0;
}

NumArray::NumArray(int size)
{
	this->list = new double[size];
	this->numElements = size;
	for (int x = 0; x < this->numElements; x++)
		this->list[x] = 0;
}
NumArray::NumArray(const NumArray & obj)
{
	if (this->numElements != obj.numElements)
	{
		this->numElements = obj.numElements;
		this->list = new double[numElements];
		for (int x = 0; x < this->numElements; x++)
			this->list[x] = obj.getElement(x);
	}
	else
	{
		for (int x = 0; x < this->numElements; x++)
			this->list[x] = obj.getElement(x);
	}
}

NumArray::~NumArray()
{
	delete[] list;
}

//isValid member function.
//This private member function returns true if the argument 
//is a valid subscript, or false otherwise.

bool NumArray::isValid(int element) const
{
	bool status;
	if (element < 0 || element > numElements)
		status = false;
	else
		status = true;
	return status;
}

double NumArray::getElement(int index)const
{
	if (isValid(index))
		return this->list[index];
	else {
		cout << "Error: Invalid subscript\n";
		exit(EXIT_FAILURE);
	}
}
double NumArray::getNumElement() const
{
	return this-> numElements;
}
void NumArray::sortList()	//array list will be sorted once created
{
	int startScan, minIndex;
	double minValue;
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
	double NumArray::getHighest() const
	{
		return this->list[numElements-1];
	}

	double NumArray::getLowest() const
	{
		return this->list[0];
	}
	double NumArray::getAverage()const
	{
		double average=0;
		for (int x = 0; x < numElements; x++)
		{
			average += list[x];
		}
		average /= numElements;
		return average;
	}
