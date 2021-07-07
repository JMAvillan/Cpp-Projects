#pragma once
#include "SimpleVector.h"
using namespace std;

template <class T>
class SearchableVector : public SimpleVector<T>
{
public:
	SearchableVector();
	SearchableVector(int size);
	SearchableVector(const SearchableVector&);
	
	// Accessor to find an item
	int findItem(const T);

};

template <class T>
SearchableVector<T>::SearchableVector() : SimpleVector<T>()
{ }

template <class T>
SearchableVector<T>::SearchableVector(int size) : SimpleVector<T>(size)
{ }

template < class T>
SearchableVector<T>::SearchableVector(const SearchableVector & obj) : SimpleVector<T>(obj.size())
{
 for (int count = 0; count < this->size(); count++)
this->operator[](count) = obj[count];
}

//********************************************************
// findItem function *
// This function searches for item. If item is found *
// the subscript is returned. Otherwise −1 is returned. *
 //********************************************************

 template < class T>
 int SearchableVector<T>::findItem(const T item)
{
	 for (int count = 0; count <= this->size(); count++)
	 {
		 if (this->getElementAt(count) == item)
		return count;
		
	 }
	 return -1;
 }
