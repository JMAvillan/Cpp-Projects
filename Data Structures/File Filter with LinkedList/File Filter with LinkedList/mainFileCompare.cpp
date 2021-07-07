#include<fstream>
#include<iostream>
#include<string>
#include"ListQueue.h"
using namespace std;


int main() {
	ListQueue<char> list1;
	ifstream infile;
	infile.open("File1.txt");
	if (!infile) {
		cout << "File failed to open!" << endl;
		system("pause");
		return -1;
	}

	char x;
	while (!infile.eof())
	{
		infile >> x;
		list1.enqueue(x); //enter the names in the files to each element of the string array
	}
	infile.close(); //close the file

	list1.display();

	ListQueue<char> list2;
	ifstream infile2;
	infile2.open("File2.txt");
	if (!infile2) {
		cout << "File failed to open!" << endl;
		system("pause");
		return -1;
	}
	char y;
	while(!infile2.eof())
	{
		infile2 >> y;
		list2.enqueue(y); //enter the names in the files to each element of the string array
	}
	infile2.close();

	bool isSame = true;
	while ((!list1.isEmpty() || !list2.isEmpty()) && isSame) {
		if (list1.peekFront() == list2.peekFront()) {
			list1.dequeue();
			list2.dequeue();
		}
		else {
			isSame = false;
		}
	}

	if (isSame)
		cout << "Files are the same.";
	else
		cout << "Files are not the same.";

	system("pause");
	return 0;

}