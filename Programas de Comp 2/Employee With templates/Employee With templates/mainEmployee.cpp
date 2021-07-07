#include <iostream>
#include "EmployeeList.h"
using namespace std;

int main()
{
	int size = 3;
	EmployeeList myList(size);
	int id;
	int index;

	
		cout << "Enter employee information:" << endl;
		cin >> myList;
		myList.sort();
		cout << myList;
		cout << "Search for an employee in list.\n"
			<< "Enter employee ID: ";
		cin >> id;
		index =myList.findItem(id);
		
		if (index != -1)
		{
			cout << "Employee found in subscript " << index << ".\n"
				<< "Employee info:\n";
			myList[index].display();
		}
		else
			cout << "Employee not found.\n";

	system("pause");
	return 0;
}