#include "Employee.h"

Employee::Employee() :employeeName("Jose Rivera"), employeeNumber("12345"), hireDate() {};

Employee::Employee(const MyString& tempName, const MyString& tempId, const Date& tempDate) :
		employeeName(tempName),employeeNumber(tempId),hireDate(tempDate) {};

Employee::Employee(const Employee& anEmployee) : employeeName(anEmployee.employeeName), employeeNumber(anEmployee.employeeNumber), hireDate(anEmployee.hireDate) {};
Employee::~Employee() {}

Employee& Employee::setName(const MyString& name)
{
	this->employeeName = name;
	return *this;
}
Employee& Employee::setNumber(const MyString& idNumber)
{
	this->employeeNumber = idNumber;
	return *this;
}
Employee& Employee::setDate(const Date& aDate) 
{
	this->hireDate = aDate;
	return *this;
}

MyString Employee::getName()const
{
	return this->employeeName;
}
MyString Employee::getNumber() const
{
	return this->employeeNumber;
}
Date Employee::getHireDate() const
{
	return this->hireDate;
}

Employee& Employee::askEmployeeInfo()
{
	cout << "Enter employee's name: ";
	cin >> this->employeeName;
	cout << "Enter " << this->employeeName << "'s ID: ";
	cin >> employeeNumber;
	cout << "Enter their hire date: ";
	cin >> hireDate;
	return *this;

}
