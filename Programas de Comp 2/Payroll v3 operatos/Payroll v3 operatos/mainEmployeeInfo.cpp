#include "EmployeeInfo.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int width = 25;
	EmployeeInfo * employee= nullptr;
	int size;
	cout << "How many employees do you wish to enter?\n";
	cin >> size;
	cin.ignore();
	
	employee =new EmployeeInfo[size];
	for (int x = 0; x < size; x++)
	{
		employee[x].initEmployee();
	}


	for (int x = 0; x < size; x++)
	{
		cout << "Enter EmployeeInfo information #" << x + 1 << ": \n";
		cin >> employee[x];
	}
	cout << "\t\t\tEmployeeInfo Information:\n";
	cout << "Name" << setw(width) << "ID Number" << setw(width) << "Department" << setw(width) << "Position"
		<< setw(width) << "Hours Worked:" << setw(width) << "Hourly Pay:" << setw(width) << "Total pay:\n";
	for (int x = 0; x < size; x++)
	{
		cout << employee[x];
	}

	cout << endl;

	//Overloading Operator =
	cout << "\n\n\t\t EmployeeInfo BACKUP (Using '=' operator)\n";
	EmployeeInfo *employeeBackup;
	employeeBackup = new EmployeeInfo[size];
	for (int x = 0; x < size; x++)
	{
		employeeBackup[x]=employee[x];
	}

	cout << "\t\t\tEmployeeInfo Information:\n";
	cout << "Name" << setw(width) << "ID Number" << setw(width) << "Department" << setw(width) << "Position"
		<< setw(width) << "Hours Worked:" << setw(width) << "Hourly Pay:" << setw(width) << "Total pay:\n";
	for (int x = 0; x < size; x++)
	{
		cout << employeeBackup[x];
	}
	cout << endl;

	//Copy constructor
	cout << "\n\n\t\t EmployeeInfo BACKUP (Using copy constructor)\n";
	EmployeeInfo* employeeBackup2(employee);

	cout << "\t\t\tEmployeeInfo Information:\n";
	cout << "Name" << setw(width) << "ID Number" << setw(width) << "Department" << setw(width) << "Position"
		<< setw(width) << "Hours Worked:" << setw(width) << "Hourly Pay:" << setw(width) << "Total pay:\n";
	for (int x=0; x<size;x++)
	cout << employeeBackup2[x];



	EmployeeInfo highestP;
	cout << "Highest Payed Employee: \n";
		for (int x = 0; x < size; x++)
		{
			if (employee[x] > employee[x + 1])
				highestP = employee[x];
		}
		cout << highestP.getName() << endl;

		EmployeeInfo lowestP;
		cout << "Lowest Payed Employee: \n";
		for (int x = 0; x < size; x++)
		{
			if (employee[x] < employee[x + 1])
				lowestP = employee[x];
		}
		cout << lowestP.getName() << endl;

		int idInput;
		cout << "Search for ID number: ";
		cin >> idInput;
	bool exists = false;
		for (int x = 0; x < size; x++)
		{	
			if(employee[x]==idInput==true)
			{
				cout << "\t\t\tEmployeeInfo Information:\n";
				cout << "Name" << setw(width) << "ID Number" << setw(width) << "Department" << setw(width) << "Position"
					<< setw(width) << "Hours Worked:" << setw(width) << "Hourly Pay:" << setw(width) << "Total pay:\n";
				cout << employee[x];
				exists = true;
				x = size;
			}
				
		}
				if (exists==false)
					cout << "ID does not exist.\n";

		delete[] employee;
		delete[]employeeBackup;
	system("pause");
	return 0;
}