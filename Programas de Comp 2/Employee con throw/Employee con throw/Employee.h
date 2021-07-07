#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
using namespace std;
#include "OutOfBounds.h"
	class Employee
	{
	private:
		string name,
			department,
			position;
		int idNumber;

	public:
		Employee();
		Employee(string, int, string, string);
		Employee(const Employee&);
		~Employee();
		void enterEmployeeInfo();

		void setInfo(string, int, string, string);
		void setName(string);
		void setDepartment(string);
		void setPosition(string);
		void setIdNumber(int) throw (OutOfBounds);
		string getName()const;
		string getDepartment()const;
		string getPosition() const;
		int getIdNumber() const;
		void display();


	};
#endif


