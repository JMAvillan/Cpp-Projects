//#include "SimpleVector.h"
//
//template < class T>
//SimpleVector<T>::SimpleVector(int s)
//{
//	arraySize = s;
//	// Allocate memory for the array.
//	try
//	{
//		aptr = new T[s];
//	}
//	catch (bad_alloc)
//	{
//		memError();
//	}
//
//	// Initialize the array.
//	for (int count = 0; count < arraySize; count++)
//		*(aptr + count) = 0;
//}
//
////*******************************************
//// Copy Constructor for SimpleVector class. *
////*******************************************
//
//template < class T>
//SimpleVector<T>::SimpleVector(const SimpleVector& obj)
//{
//	// Copy the array size.
//	arraySize = obj.arraySize;
//
//	// Allocate memory for the array.
//	aptr = new T[arraySize];
//	if (aptr == 0)
//		memError();
//
//	// Copy the elements of obj's array.
//	for (int count = 0; count < arraySize; count++)
//		*(aptr + count) = *(obj.aptr + count);
//}
//
////**************************************
//// Destructor for SimpleVector class. *
////**************************************
//template < class T>
//SimpleVector<T>::~SimpleVector()
//{
//	if (arraySize > 0)
//		delete[] aptr;
//}
//
////*******************************************************
//// getElementAt function. The argument is a subscript. *
//// This function returns the value stored at the *
//// subcript in the array. *
////*******************************************************
//
//template < class T>
//T SimpleVector<T>::getElementAt(int sub)
//{
//	if (sub < 0 || sub >= arraySize)
//		subError();
//	return aptr[sub];
//}
////********************************************************
//	 // Overloaded [] operator. The argument is a subscript. *
//	 // This function returns a reference to the element *
//	 // in the array indexed by the subscript. *
//	 //********************************************************
//
//template < class T>
//T& SimpleVector<T>::operator[](const int& sub)
//{
//	if (sub < 0 || sub >= arraySize)
//		subError();
//	return aptr[sub];
//}
//
//template <class T>
//void SimpleVector<T>::sort()
//{
//	int startScan, minIndex;
//	T minValue;
//	for (startScan = 0; startScan < (this->arraySize - 1); startScan++)
//	{
//		minIndex = startScan;
//		minValue = this->aptr[startScan];
//		for (int index = startScan + 1; index < this->arraySize; index++)
//		{
//			if (this->aptr[index] < minValue)
//			{
//				minValue = this->aptr[index];
//				minIndex = index;
//			}
//		}
//		list[minIndex] = list[startScan];
//		list[startScan] = minValue;
//
//	}
//}