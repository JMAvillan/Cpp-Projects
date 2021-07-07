#include <iostream>
#include <string>
#include <iomanip>
#include "Employee.h"
using namespace std;
const int NUM_EMPLOYEES = 3;
const int width = 20;

Employee::Employee()
{
	setInfo("",0, "", "");
	setPayroll(0.0, 0.0);
}

Employee::Employee(string employeeName, int idNum, string depart, string pos,
					double hours, double hoursP)
{
	setInfo(employeeName, idNum, depart, pos);
	setPayroll(hours, hoursP);
}
//copy constructor
Employee::Employee(const Employee& anEmploy, int SIZE)
{
	Employee *ptrEmployee = new Employee[SIZE];
		setInfo(anEmploy.getName(),anEmploy.getIdNumber(), anEmploy.getDepartment(),
	anEmploy.getPosition());
		setPayroll(anEmploy.getHoursWorked(), anEmploy.getHourlyPay());
	}

void Employee::enterEmployeeInfo()
{
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
		cout << "Enter employee id number: ";
		cin >> id;
		this->setInfo(n, id, d, p);
}
void Employee::enterPayrollInfo()
{
	double hW, hP, tP;
	bool valid = true;
	do
	{
		cout << "Enter " <<getName() << "'s worked hours: ";
		cin >> hW;
		if (hW > 60 || hW < 0)
		{
			valid = false;
			cout << "Invalid input\n"
				<< "Invlid worked hours.\n";

		}
		else
			valid = true;
	} while (valid == false);

	do
	{
		cout << "Enter " << getName << "'s hourly pay: "; \
			cin >> hP;
		if (hP < 0)
		{
			valid = false;
			cout << "Hourly pay msut be more than 0.\n";
		}
		else
			valid = true;
	} while (valid == false);
	setPayroll(hW, hP);
	cin.ignore();
}

//Setters
void Employee::setInfo(string n, int id, string depart, string pos)
{
	setName(n);
	setIdNumber(id);
	setDepartment(depart);
	setPosition(pos);
}
void Employee::setName(string n)
{		name = n;
}
void Employee::setDepartment(string d)
{
		department = d;
}
void Employee::setPosition(string p)
{
		position = p;
}
void Employee::setIdNumber(int id)
{
		idNumber = id;
}

//Getters
string Employee::getName()const
{
	return name;
}
string Employee::getDepartment()const
{
	return department;
}
string Employee::getPosition() const
{
		return position;
}
int Employee::getIdNumber() const
{
		return idNumber;
}

void Employee::display()
{	
		cout << name  << setw(width-5) << idNumber << setw(width) << department << setw(width)
				<< position << endl;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+++++++++++++++++++++++++++++ payroll related ++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void Employee::displayPayroll()
{
	
		cout << name << setw(width - 5) << hoursWorked << setw(width) << hourlyPay << setw(width)
			<< totalPay << endl;
	}




//Setters
	void Employee::setPayroll(double hours, double hourlyP)
{
	setHoursworked(hours);
	setHourlyPay(hourlyP);
	setTotalPay();

}
void Employee::setHoursworked(double w)
{
		hoursWorked = w;	
}
void Employee::setHourlyPay(double hP)
{
				hourlyPay = hP;
}

void Employee::setTotalPay()
{
	totalPay = getHourlyPay() * getHoursWorked();
}

//Getters
double Employee::getHoursWorked() const
{
			return hoursWorked;
}
double Employee::getHourlyPay()const
{
			return hourlyPay;
}
double Employee::getTotalPay()const
{
			return totalPay;
}
