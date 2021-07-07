#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "Employee.h"

#include "OutOfBounds.h"

const int NUM_EMPLOYEES = 3;
const int width = 20;

Employee::Employee()
{
	setInfo("", 50, "", "");
}

Employee::Employee(string employeeName, int idNum, string depart, string pos)
{
	setInfo(employeeName, idNum, depart, pos);
}
//copy constructor
Employee::Employee(const Employee& anEmploy)
{
	setInfo(anEmploy.getName(), anEmploy.getIdNumber(), anEmploy.getDepartment(),
		anEmploy.getPosition());
}
Employee::~Employee() {}

void Employee::enterEmployeeInfo()
{
	string n,
		d,
		p;
	int id;

	cout << "Enter employee name: ";
	getline(cin, n);
	cout << "Enter employee department: ";
	getline(cin, d);
	cout << "Enter employee position: ";
	getline(cin, p);
	cout << "Enter employee id number: ";
	cin >> id;
	this->setInfo(n, id, d, p);
}

//Setters
void Employee::setInfo(string n, int id, string depart, string pos)
{
	setName(n);
	setIdNumber(id);
	setDepartment(depart);
	setPosition(pos);
}
void Employee::setName(string n)
{
	name = n;
}
void Employee::setDepartment(string d)
{
	department = d;
}
void Employee::setPosition(string p)
{
	position = p;
}
void Employee::setIdNumber(int id) throw (OutOfBounds)
{
	if (id >= 50 && id <= 100)
		idNumber = id;
	else
		throw OutOfBounds(id);
}

//Getters
string Employee::getName()const
{
	return name;
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

void Employee::display()
{
	cout << name << setw(width - 5) << idNumber << setw(width) << department << setw(width)
		<< position << endl;
}





