#include <iostream>
#include <string>
using namespace std;
#include "Employee.h"

int main()
{
	Employee employee;

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
	
	employee.setName(n);
	employee.setDepartment(d);
	employee.setPosition(p);

	bool tryAgain = true;

	while (tryAgain)
	{
		cout << "Enter employee id number: ";
		cin >> id;
		try
		{
			employee.setIdNumber(id);
			cout << endl << endl;
			cout << "Employee information:\n";
			employee.display();
			tryAgain = false;
		}
		catch (OutOfBounds e)
		{
			cout << "Error: " << e.getValue()
				<< " is an invalid value for the"
				<< " id. Should be between 50 and 100.\n";
		}
	}

	system("pause");
	return 0;
}