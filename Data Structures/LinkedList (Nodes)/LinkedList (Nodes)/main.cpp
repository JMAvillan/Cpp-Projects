#include <iostream>
#include <cstdlib>
#include "LinkedList.h"
using namespace std;

int main() {

	LinkedList testNode;
	testNode.addNode(3);
	testNode.addNode(6);
	testNode.addNode(9);
	testNode.addNode(12);
	testNode.printList();
	testNode.deleteNode(9);
	testNode.printList();
	system("pause");
	return 0;
}