#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
	string firstName, lastName,
		department,
		position;
	int idNumber;

public:
	Employee();
	Employee(string, string, int, string, string);
	Employee(const Employee&);
	~Employee();
	void enterEmployeeInfo();

	void setInfo(string, string, int, string, string);
	void setFirstName(string);
	void setLastName(string);
	void setDepartment(string);
	void setPosition(string);
	void setIdNumber(int);
	string getFirstName()const;
	string getLastName()const;
	string getDepartment()const;
	string getPosition() const;
	int getIdNumber() const;
	void display() const;

};
#endif