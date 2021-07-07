#include <iostream>
using namespace std;
#include "ArrayQueue.h"
int main()
{
	ArrayQueue<int> queue1, queue2;
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

	cout << "queueFront: " << queueFront << endl;


	system("pause");
	return 0;
}