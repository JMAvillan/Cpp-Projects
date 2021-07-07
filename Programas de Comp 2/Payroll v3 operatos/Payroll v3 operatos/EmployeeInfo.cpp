#include "EmployeeInfo.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
const int width = 25;

//overloading operatos
 ostream& operator<< (ostream& out, const EmployeeInfo& obj)
{
	 out << obj.getName() <<"\t"<<  setw(width) << obj.getIdNumber() << setw(width) << obj.getDepartment() << setw(width)
		 <<obj.getPosition() << setw(width) << obj.getHoursWorked() << setw(width) << obj.getHourlyPay() << setw(width)
		 << obj.getTotalPay() << endl;
	 return out;
}

istream& operator>> (istream &in, EmployeeInfo& obj)
{
	obj.enterEmployeeInfo();
	obj.enterPayrollInfo();
	return in;
}

EmployeeInfo EmployeeInfo::operator =(const EmployeeInfo& obj)
{
	this->setInfo(obj.getName(), obj.getIdNumber(), obj.getDepartment(), obj.getPosition());
	this->setPayroll(obj.getHoursWorked(), obj.getHourlyPay());
	return *this;

}

bool EmployeeInfo::operator <(const EmployeeInfo& obj) const
{
	if (this->getHourlyPay() < obj.getHourlyPay())
		true;
	else
		return false;
}


bool EmployeeInfo::operator >(const EmployeeInfo& obj)const
{
	if (this->getHourlyPay() > obj.getHourlyPay())
		true;
	else
		return false;
}
bool EmployeeInfo::operator ==(int &right) const
{
	if (this->getIdNumber() == right)
	{
		return true;
	}
	else
		false;
}

EmployeeInfo::EmployeeInfo()
{
	initEmployee();
}

EmployeeInfo::EmployeeInfo(string EmployeeInfoName, int idNum, string depart, string pos,
	double hours, double hoursP)
{
	setInfo(EmployeeInfoName, idNum, depart, pos);
	setPayroll(hours, hoursP);
}

EmployeeInfo::EmployeeInfo(const EmployeeInfo& anE)
{
	initEmployee();
	this->setInfo(anE.getName(), anE.getIdNumber(), anE.getDepartment(), anE.getPosition());
	this->setPayroll(anE.getHoursWorked(), anE.getHourlyPay());

}

void EmployeeInfo::initEmployee()
{
	setInfo("", 0, "", "");
	setPayroll(0.0, 0.0);
}


void EmployeeInfo::enterEmployeeInfo()
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
void EmployeeInfo::enterPayrollInfo()
{
	double hW, hP;
	bool valid = true;
	do
	{
		cout << "Enter " << getName() << "'s worked hours: ";
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
		cout << "Enter " << getName() << "'s hourly pay: "; \
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
void EmployeeInfo::setInfo(string n, int id, string depart, string pos)
{
	setName(n);
	setIdNumber(id);
	setDepartment(depart);
	setPosition(pos);
}
void EmployeeInfo::setName(string n)
{
	name = n;
}
void EmployeeInfo::setDepartment(string d)
{
	department = d;
}
void EmployeeInfo::setPosition(string p)
{
	position = p;
}
void EmployeeInfo::setIdNumber(int id)
{
	idNumber = id;
}

//Getters
string EmployeeInfo::getName()const
{
	return name;
}
string EmployeeInfo::getDepartment()const
{
	return department;
}
string EmployeeInfo::getPosition() const
{
	return position;
}
int EmployeeInfo::getIdNumber() const
{
	return idNumber;
}



//Setters
void EmployeeInfo::setPayroll(double hours, double hourlyP)
{
	setHoursworked(hours);
	setHourlyPay(hourlyP);
	setTotalPay();

}
void EmployeeInfo::setHoursworked(double w)
{
	hoursWorked = w;
}
void EmployeeInfo::setHourlyPay(double hP)
{
	hourlyPay = hP;
}

void EmployeeInfo::setTotalPay()
{
	totalPay = getHourlyPay() * getHoursWorked();
}

//Getters
double EmployeeInfo::getHoursWorked() const
{
	return hoursWorked;
}
double EmployeeInfo::getHourlyPay()const
{
	return hourlyPay;
}
double EmployeeInfo::getTotalPay()const
{
	return totalPay;
}
