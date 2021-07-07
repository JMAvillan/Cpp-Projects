#pragma once
class IntegerList
{
private:
	int* list;			//pointer to the array
	int numElements;	//NUmber of elements
	bool isValid(int) const;	//Validates subscripts

public:
	IntegerList(int);
	~IntegerList();
	void setElement(int, int);
	int getElement(int ) const;
	void sortList();
};

