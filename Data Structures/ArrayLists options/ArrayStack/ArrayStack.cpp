////  Created by Frank M. Carrano and Tim Henry.
////  Copyright (c) 2013 __Pearson Education__. All rights reserved.
//
///** Listing 7-1
//	@file ArrayStack.cpp */
//#include <cassert>       // For assert
//#include <iostream>
//#include "ArrayStack.h"  // Header file
//using namespace std;
//
//template<class ItemType>
//ArrayStack<ItemType>::ArrayStack() : top(-1)
//{
//}  // end default constructor
//
//// Copy constructor and destructor are supplied by the compiler
//
//template<class ItemType>
//bool ArrayStack<ItemType>::isEmpty() const
//{
//	return top < 0;
//}  // end isEmpty
//
//template<class ItemType>
//bool ArrayStack<ItemType>::push(const ItemType& newEntry)
//{
//	bool result = false;
//	if (top < MAX_STACK - 1)  // Does stack have room for newEntry?
//	{
//		top++;
//		items[top] = newEntry;
//		result = true;
//	}  // end if
//
//	return result;
//}  // end push
//
//
//template<class ItemType>
//bool ArrayStack<ItemType>::pop()
//{
//	bool result = false;
//	if (!isEmpty())
//	{
//		top--;
//		result = true;
//	}  // end if
//
//	return result;
//}  // end pop
//
//
//template<class ItemType>
//ItemType ArrayStack<ItemType>::peek() const
//{
//	assert(!isEmpty());  // Enforce precondition
//
//	// Stack is not empty; return top
//	return items[top];
//}  // end peek
//
//template<class ItemType>
//void ArrayStack<ItemType>::display() const
//{
//	for (int x = 0; x <= this->top; x++)
//	{
//		cout << this->items[x];
//		if (x != this->top)
//			cout << ",";
//	}
//	cout << endl;
//}
//
//// End of implementation file.
//