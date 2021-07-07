#pragma once
class LinkedList
{
private:
	typedef struct node {
		int data;
		node* next;
	}* nodePtr;
	nodePtr head;
	nodePtr curr;
	nodePtr temp;

public:
	LinkedList();
	void addNode(int addData);
	void deleteNode(int delData);
	void printList();

};

