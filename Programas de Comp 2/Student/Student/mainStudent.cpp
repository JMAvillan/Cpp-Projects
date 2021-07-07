#include "Date.h"
#include "Phone.h"
#include "MyString.h"
#include "Student.h"
#include <iostream>

using namespace std;

int main()
{

	Phone phone("787", "222", "3535");
	cout << "Constructor: ";
	cout << phone << endl << endl;
	cout << "Enter phone number: (###) ###-####: ";
	cin >> phone;
	cout << phone << endl;

	cout << endl;
	cout << "Default constructor: ";
	Date birth;
	cout << birth << endl << endl;
	cout << "Birthdate (dd/mm/yyyy): \n";
	cin >> birth;
	cout << birth << endl << endl;


	MyString firstName("Ruben"), lastName;
	lastName = "Rosario";
	cout << "Secondary and Default constructor: ";
	cout << firstName << " " << lastName << endl << endl;
	
	cout << "Enter name: \n";
	cout << "First Name: \n";
	cin.ignore();
	cin >> firstName;
	cout << "Last Name: ";
	cin >> lastName;
	cout << firstName << " " << lastName << endl;

	Student std;
	cout << "First student: \n";
	std.setValues(firstName, lastName, birth, phone);
	cout << std << endl;

	Student std2;
	std2 = std;
	cout << "Second Student (Using assinment opertor '=')\n";
	cout << std2;
	
	Student std3;
	cout << "Enter student information: \n";
	cin >> std3;
	cout << std3;

	system("pause");
	return 0;
}