#include "EmployeeList.h"
#include <iostream>
#include <iomanip>
using namespace std;
const int width = 20;

EmployeeList::EmployeeList(int size) : size(size) {
	this->initList();
	Employee tempE;
	for (int x = 0; x < this->size; x++)
		this->list[x] = tempE;
}
EmployeeList::EmployeeList(const EmployeeList& aList) : size(aList.getSize()) {
		delete[]this->list;
		this->initList();

	for (int x = 0; x < this->size; x++)
	{
		this->list[x] = aList.getEmployee(x);
	}
}

EmployeeList::~EmployeeList()
{
	delete[] this->list;
}

void EmployeeList::setEmployee(string n, string lN, int id, string depart, string pos,int index)
{
	this->list[index].setInfo(n, lN, id, depart, pos);
}


Employee EmployeeList::getEmployee(int index) const
{
	return this->list[index];
}
int EmployeeList::getSize() const
{
	return this->size;
}

void EmployeeList::sort()
{
	int startScan, minIndex;
	Employee minValue;
	for (startScan = 0; startScan < (this->size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = this->list[startScan];
		for (int index = startScan + 1; index < this->size; index++)
		{
			if (this->list[index].getIdNumber() < minValue.getIdNumber())
			{
				minValue = this->list[index];
				minIndex = index;
			}
		}
		list[minIndex] = list[startScan];
		list[startScan] = minValue;

	}
}

int EmployeeList::findItem(int value) const
{
	for (int count = 0; count < this->size; count++)
	{
		if (this->list[count].getIdNumber() == value)
			return count;

	}
	return -1;
}
void EmployeeList::display(int index) const
{
	cout << (*this)[index].getLastName() << ", " << (*this)[index].getFirstName() <<setw(width) << "\t"
		<< (*this)[index].getIdNumber() << setw(width) << (*this)[index].getDepartment() << setw(width)
		<< (*this)[index].getPosition() << endl;
}

const Employee& EmployeeList::operator [] (int index)const
{
	return this->list[index];
}
Employee& EmployeeList::operator [] (int index)
{
	return this->list[index];
}
ostream& operator << (ostream& out, const EmployeeList& aList) {

	cout << "Employee Information:\n";
	for (int x = 0; x < aList.getSize(); x++)
	{
		cout << x + 1 << ". ";
		aList.display(x);
	}
	return out;
}

istream& operator >> (istream& in, EmployeeList& aList)
{
	for (int x = 0; x < aList.getSize(); x++)
	{
		cout << "Enter employee #" << x + 1 << " information:" << endl;
		string n, lN,
			d="",
			p="";
		int id=0;

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
		cin.get();
		aList.setEmployee(n, lN, id, d, p, x);
	}
	return in;
}