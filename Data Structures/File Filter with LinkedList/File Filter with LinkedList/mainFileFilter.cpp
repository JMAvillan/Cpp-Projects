//#include<fstream>
//#include<iostream>
//#include<string>
//#include"ListQueue.h"
//using namespace std;
//
//int main() {
//	ListQueue<char> letters;
//	char x;
//	ifstream infile;
//	infile.open("File1.txt");
//	if (!infile) {
//		cout << "File failed to open!" << endl;
//		system("pause");
//		return -1;
//	}
//
//	//Place File characters in the listQueue
//	while (!infile.eof())
//	{
//		infile >> x;
//		letters.enqueue(x);
//	}
//		
//	infile.close(); //close the file
//
//	letters.display();
//
//	fstream file2;
//	file2.open("File2.txt", ios::in | ios::out); //read+
//	if (file2.fail())
//	{
//		file2.clear();
//		file2.open("File2.txt", ios::in | ios::out | ios::trunc);
//		if (file2.fail())
//		{
//			cout << "ERROR: Failed to open file." << endl << endl;
//		}
//	}
//	while (!letters.isEmpty()) {
//		x = letters.peekFront();
//		x = toupper(x);
//		file2 << x;
//		letters.dequeue();
//	}
//
//	if (letters.isEmpty())
//			cout << "letters is empty" << endl;
//		else
//			cout << "letters are not empty" << endl;
//
//	file2.seekg(0, ios::beg);	// mover cursor al comienzo para 
//	file2 >> x;			// poder leer archivo
//	while (!file2.eof())
//	{
//		cout << x << endl;
//		file2 >> x;
//	}
//	file2.close();
//
//	system("pause");
//	return 0;
//
//}
