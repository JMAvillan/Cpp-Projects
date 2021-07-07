#include "MyMenu.h"
#include <iostream>
using namespace std;

void MyMenu::display() const
{
	cout << " ________________________________" << endl
		<< "|                                |" << endl
		<< "|         Exam Maker Menu        |" << endl
		<< "|________________________________|" << endl
		<< "A. Create Exam" << endl
		<< "B. Edit Exam" << endl
		<< "C. Show your Exam" << endl
		<< "D. Need help? Show an example" << endl
		<< "E. Delete Exam" << endl
		<< "F. Exit program" << endl;
}

void MyMenu::editExamDisplay() const
{
	cout << " ________________________________" << endl
		<< "|                                |" << endl
		<< "|        Exam Editing Menu       |" << endl
		<< "|________________________________|" << endl
		<< "A. Add new question" << endl
		<< "B. Change question" << endl
		<< "C. Increment question list size" << endl
		<< "D. Delete question" << endl
		<< "E. Go back" << endl;
}
ostream& operator << (ostream& out, const MyMenu& anMenu)
{
	anMenu.display();
	return out;
}