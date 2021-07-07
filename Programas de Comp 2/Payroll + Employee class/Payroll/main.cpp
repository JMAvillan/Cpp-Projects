#include <iostream>
#include <iomanip>
#include "Employee.h"
using namespace std;

	void enterEmployeeInfo(Employee&);
	void enterPayrollInfo(Employee&);

	int main()
	{
		string name, department, position;
		int idNumber;
		double hoursWorked, hourlyPay;
		const int SIZE = 3, width = 20;
		Employee employees[SIZE];

		for (int x = 0; x < SIZE; x++)
		{
			cout << "Enter employee information #" << x + 1 << ": \n";
			employees[x].enterEmployeeInfo();
			employees[x].enterPayrollInfo();
		}
		cout << "\t\t\tEmployee Information:\n";
		cout << "Name" << setw(width) << "ID Number" << setw(width) << "Department" << setw(width) << "Position\n";
		for (int x = 0; x < SIZE; x++)
		{
			employees[x].display();
		}
		cout << "\t\t\tEmployee Payroll Information:\n";
		cout << "Name" << setw(width) << "Hours Worked:" << setw(width) << "Hourly Pay:" << setw(width) << "Total pay:\n";
		for (int x = 0; x < SIZE; x++)
		{
			employees[x].displayPayroll;
		}


		//cout << "\n\t\t Add person to management position.\n";
		//management.display(NULL);
		//cout << "Please choose which slot to fill: (1, 2 or 3)\n";
		//int slot;
		//cin >> slot;
		//cin.ignore();
		//enterEmployeeInfo(management);
		//management.setInfo(name, idNumber, position, department, slot-1);
		//enterPayrollInfo(management, slot - 1);
		//management.setPayroll(hoursWorked, hourlyPay, slot - 1);
		//
		//cout << "\t\t\t Management Employees files\n";
		//management.display(NULL);
		//management.displayPayroll(NULL);

		//copy contructor
		cout << "\t\t EMPLOYEE BACKUP (Copy constructor)\n";
		Employee* employeeBackup(employees);

	cout << "\t\t\tEmployee Information:\n";
	cout << "Name" << setw(width) << "ID Number" << setw(width) << "Department" << setw(width) << "Position\n";
	for (int x = 0; x < SIZE; x++)
	{
		employeeBackup[x].display();
	}
	cout << "\t\t\tEmployee Payroll Information:\n";
	cout << "Name" << setw(width) << "Hours Worked:" << setw(width) << "Hourly Pay:" << setw(width) << "Total pay:\n";
	for (int x = 0; x < SIZE; x++)
	{
		employeeBackup[x].displayPayroll();
	}

	system("pause");
	return 0;
}