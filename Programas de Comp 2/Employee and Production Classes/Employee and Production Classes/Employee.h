#pragma once
#include "MyString.h"
#include "Date.h"
class Employee
{private:
	MyString employeeName;
	MyString employeeNumber;
	Date hireDate;

public:
	Employee();
	Employee(const MyString&, const MyString&, const Date&);
	Employee(const Employee&);
	~Employee();

	Employee& setName(const MyString&);
	Employee& setNumber(const MyString&);
	Employee& setDate(const Date&);

	MyString getName()const;
	MyString getNumber() const;
	Date getHireDate() const;

	Employee& askEmployeeInfo();

};

