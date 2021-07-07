#pragma once
#include "Employee.h"
class EmployeeList :
	public Employee
{
private:
	Employee *list;
	int size;
	void initList(){
		for (int x = 0; x < this->size; x++)
		{
			this->list = new Employee[this->size];
		}
	}
public:
	EmployeeList(int size=1);
	EmployeeList(const EmployeeList&);
	~EmployeeList();

	void setEmployee(string n, string lN, int id, string depart, string pos, int index);
	Employee getEmployee(int index) const;
	int getSize() const;
	void display(int index) const;
	void sort();
	int findItem(int)const;

	const Employee& operator [] (int)const;
	Employee& operator [] (int);
	friend ostream& operator << (ostream& out, const EmployeeList&);
	friend istream& operator >> (istream& in, EmployeeList&);
};

