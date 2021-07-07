#pragma once
#include <iostream>
using namespace std;
class NumArray
{
private:
	const int DEFAULT_SIZE = 3;
	double* list;			//pointer to the array
	int numElements;	//Number of elements
	bool isValid(int) const;	//Validates subscripts

public:
	//overloading operators
	friend ostream & operator << (ostream& out, const NumArray& objList);
	friend istream & operator >> (istream& in, NumArray& objList);
	NumArray& operator=(const NumArray& objList);
	bool operator ==(const NumArray& objList)const;
	bool operator != (const NumArray& objList)const;
	double operator [](int subs) const;
	
	NumArray();
	NumArray(int);
	NumArray(const NumArray&);
	~NumArray();
	double getElement(int) const;
	double getNumElement() const;
	void sortList();				//array list will be sorted once created
	double getHighest()const;
	double getLowest()const;
	double getAverage()const;
};

