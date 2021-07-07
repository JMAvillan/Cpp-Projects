#include "Generator.h"
#include "Exam.h"
#include <iostream>
using namespace std;

void Generator::setExam(Exam e)
{
	this->exam = e;
}
Exam Generator::getExam()
{
	return this->exam;
}

void Generator::showMenu()
{

	for (int x = 0; x < 3; x++)
		cout << endl;
	cout << "Welcome to the Exam Maker " << endl << endl;
	cout << "Press Enter to begin...";
	cin.get();
	bool exit = false;
	char input;
	MyMenu unMenu;
	
	while (!exit)
	{
		MyString decision;
		bool goBack = false;
		system("cls");

		cout << unMenu;
		cout << "Your input: ";
		cin >> input;
		switch (input)
		{
		case 'A':
		case 'a':
			system("cls");
			cin >> this->exam;
			cin.ignore();
			cout << "Press Enter to go back";
			cin.get();
			break;
		case 'B':
		case 'b':
			while (!goBack)
			{
				system("cls");
				unMenu.editExamDisplay();
				cin >> input;
				switch (input)
				{
				case 'A':
				case 'a':
					system("cls");
					this->exam.addNewQuestion();
					cout << "Press Enter to go back";
					cin.get();
					break;
				case 'B':
				case 'b':
					system("cls");
					this->exam.changeQuestion();
					cout << "Press Enter to go back";
					cin.get();
					
					break;
				case'C':
				case 'c':
					system("cls");
					this->exam.incrementQuestionList();
					cin.ignore();
					cout << "Press Enter to go back";
					cin.get();
					break;
				case 'D':
				case'd':
					system("cls");
					this->exam.deleteQuestion();
					cin.ignore();
					cout << "Press Enter to go back";
					cin.get();
					break;
				case 'E':
				case 'e':
					goBack = true;
					break;
				}
					
			}
			break;
		case 'C':
		case 'c':
			system("cls");
			cout << this->exam;
			cin.ignore();
			cout << "Press Enter to go back";
			cin.get();
				break;
		case 'D':
		case 'd':
			system("cls");
			this->exam.showExample();
			cin.ignore();
			cout << "Press Enter to go back";
			cin.get();
			break;
		case 'E':
		case 'e':
			system("cls");
			cin.ignore();
			cout << "Are you sure you want to delete exam?\n"
				<< "(Type \"Yes\" to continue/ Type \"No\" to go back)" << endl;
			cin >> decision;
			if (decision == "yes" || decision == "Yes" || decision == "YES")
				this->exam.deleteExam();
			else if (decision == "no" || decision == "No" || decision == "NO")
			{}
			else
				cout << "Invalid input. Going back.\n";

			cout << "Press Enter to go back";
			cin.get();
			break;
		case 'F':
		case 'f':
			exit = true;
			break;
		}
	}
}