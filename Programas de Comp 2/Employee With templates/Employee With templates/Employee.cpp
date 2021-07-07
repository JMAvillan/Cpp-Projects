#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "Employee.h"

const int NUM_EMPLOYEES = 3;
const int width = 20;

Employee::Employee()
{
	setInfo("", "", 50, "", "");
}

Employee::Employee(string employeeFirstName, string employeeLastName, int idNum, string depart, string pos)
{
	setInfo(employeeFirstName, employeeLastName, idNum, depart, pos);
}
//copy constructor
Employee::Employee(const Employee& anEmploy)
{
	setInfo(anEmploy.getFirstName(), anEmploy.getLastName(), anEmploy.getIdNumber(), anEmploy.getDepartment(),
		anEmploy.getPosition());
}
Employee::~Employee() {}

void Employee::enterEmployeeInfo()
{
	string n,lN,
		d,
		p;
	int id;

	cout << "Enter employee first name: ";
	getline(cin, n);
	cout << "Enter employee last name: ";
	getline(cin, lN);
	cout << "Enter employee department: ";
	getline(cin, d);
	cout << "Enter employee position: ";
	getline(cin, p);
	cout << "Enter employee id number: ";
	cin >> id;
	this->setInfo(n, lN, id, d, p);
}

//Setters
void Employee::setInfo(string n, string lN, int id, string depart, string pos)
{
	setFirstName(n);
	setLastName(lN);
	setIdNumber(id);
	setDepartment(depart);
	setPosition(pos);
}
void Employee::setFirstName(string n)
{
	firstName = n;
}

void Employee::setLastName(string lN)
{
	lastName = lN;
}
void Employee::setDepartment(string d)
{
	department = d;
}
void Employee::setPosition(string p)
{
	position = p;
}
void Employee::setIdNumber(int id)
{
		idNumber = id;
}

//Getters
string Employee::getFirstName()const
{
	return firstName;
}
string Employee::getLastName()const
{
	return lastName;
}

string Employee::getDepartment()const
{
	return department;
}
string Employee::getPosition() const
{
	return position;
}
int Employee::getIdNumber() const
{
	return idNumber;
}

void Employee::display() const
{
	cout << this->lastName << ", "<< this->firstName << setw(width - 5) << idNumber << setw(width) << department << setw(width)
		<< position << endl;
}
