#include<iostream>
using namespace std;
#include"Node.h"
#include"LinkedList.h"

int main()
{//Josephus position test
	int const n = 20, m = 12;
	LinkedList<int>* circle = new LinkedList<int>();
	for (int r = 1 ; r <= n; r++) {
		circle->insert(r, r);
	}
	int lastIndex = 1;
	int orderIndex = 0;
	int orderOfElimination[n - 1];
	while (!(circle->getLength() == 1))
	{	
		lastIndex = circle->roulette(lastIndex,m);
		circle->remove(lastIndex);
		orderOfElimination[orderIndex] = lastIndex;
		orderIndex++;
	}

 	cout << "Last person left standing at (Josephus Position) is " << circle->getPosition(circle->getLength()) << "."<<  endl;
	cout << "Order of elimination: \n";
	for (int x = 1; x <= n - 1; x++)
		cout << orderOfElimination[x-1] << (x  == n - 1 ? ".\n" : (x%5==0? "\n" : ", "));
	system("pause");
	return 0;
} 