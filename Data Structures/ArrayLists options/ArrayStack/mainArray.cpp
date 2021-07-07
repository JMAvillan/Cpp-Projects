#include <iostream>
#include <string>
#include "ArrayStack.h"
#include "ArrayQueue.h"
using namespace std;
//
//bool isPalindrome(string someString) {
//	ArrayQueue<char> aQueue;
//	ArrayStack<char> aStack;
//
//	int length = someString.length();
//
//	for (int x = 0; x < length; x++)
//	{
//		char nextChar = someString[x];
//		aQueue.enqueue(nextChar);
//		aStack.push(nextChar);
//	}
//
//	bool charactersAreEqual = true;
//	while (!(aQueue.isEmpty()) && charactersAreEqual)
//	{
//		char queueFront = aQueue.peekFront();
//		char stackTop = aStack.peek();
//		if (queueFront == stackTop)
//		{
//			aQueue.dequeue();
//			aStack.pop();
//		}
//		else
//			charactersAreEqual = false;
//	}
//	return charactersAreEqual;
//} 
//
int main()
{
//	ArrayStack<int> stack1, stack2;
//	stack1.push(1);
//	stack1.push(2);
//	stack2.push(3);
//	stack2.push(4);
//	stack1.pop();
//	int stackTop = stack2.peek();
//	stack1.push(stackTop);
//	stack1.push(5);
//	stack2.pop();
//	stack2.push(6);
//
//	cout << "Stack 1: ";
//	stack1.display();
//	cout << "Stack 2: ";
//	stack2.display();

	ArrayStack<char> arr;
	double operand1, operand2;
	char input[] = { '-', '*',2,'/',8,4,3};
	int size=0, x = 0;
	
	for (int x = 0; x < 9; x++)
	{
		if (input[x] == '+')
		{
			operand2 = arr.peek();
			arr.pop();
			operand1 = arr.peek();
			arr.pop();
			arr.push(operand1 + operand2);
		}
		else if (input[x] == '-')
		{
				operand2 = arr.peek();
				arr.pop();
				operand1 = arr.peek();
				arr.pop();
				arr.push(operand1 - operand2);
		}
		else if (input[x] == '*')
		{
				operand2 = arr.peek();
				arr.pop();
				operand1 = arr.peek();
				arr.pop();
				arr.push(operand1 * operand2);
		}
		else
			arr.push(input[x]);
	}

	arr.display();

	/*ArrayQueue<int> queue1, queue2;

	queue1.enqueue(1);
	queue1.enqueue(2);
	queue2.enqueue(3);
	queue2.enqueue(4);
	queue1.dequeue();
	int queueFront = queue2.peekFront();
	queue1.enqueue(queueFront);
	queue1.enqueue(5);
	queue2.dequeue();
	queue2.enqueue(6);

	cout << "Queue 1: ";
	queue1.display();
	cout << "Queue 2: ";
	queue2.display();
	cout << queueFront << endl; 
	string firstStr = "radar";

	if (isPalindrome(firstStr))
		cout << "String \"" << firstStr << "\" is palindrome.\n";*/

	system("pause");
	return 0;
}