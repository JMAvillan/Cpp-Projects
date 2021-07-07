#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
	head = NULL;
	curr = NULL;
	temp = NULL;
}

void LinkedList::addNode(int addData) {
	nodePtr n = new node();
	n->data = addData;
	n->next = NULL;

	if (head != NULL)
	{
		curr = head;
		while (curr->next != NULL)
		{curr = curr->next;
	}
	curr->next = n;
}
	else
	{
		head = n;
	}
}

void LinkedList::deleteNode(int delData) {
	nodePtr delPtr = NULL;
	
	//point to beginning
	temp = head;
	curr = head;

	while (curr != NULL && curr->data!=delData)
	{
		temp = curr;
		curr = curr->next;
	}

	if (curr == NULL)
	{
		cout << delData << " was not in the list\n";
		delete delPtr;
	}
	else
		delPtr = curr;
		curr= curr->next;
		temp->next = curr; //Connects the last node to the one
							 //to one curr ios pointing at now.
		delete delPtr;
		cout << "The value " << delData << " was deleted.\n";
}

void LinkedList::printList() {
	curr = head;
	while (curr != NULL)
	{
		cout << curr->data << endl;
		curr = curr->next;
	}
}

