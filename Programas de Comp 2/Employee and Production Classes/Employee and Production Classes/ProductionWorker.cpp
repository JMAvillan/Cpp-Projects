#include "ProductionWorker.h"
#include "Employee.h"
#include <iostream>
#include <iomanip>
using namespace std;

const int width = 25;
ProductionWorker::ProductionWorker(): shift(1), payRate(7.25), Employee() {};

ProductionWorker::ProductionWorker(int s, double payR, const MyString& tempName, const MyString& tempId, const Date& tempDate)
	:shift(s), payRate(payR), Employee(tempName, tempId, tempDate) {};
ProductionWorker::ProductionWorker(const ProductionWorker& aWorker) : shift(aWorker.shift), payRate(aWorker.payRate), Employee(aWorker) {};
ProductionWorker::~ProductionWorker() {}

ProductionWorker& ProductionWorker::setShift(int s)
{
	while (!(s >= 1 && s <= 2))
	{
		cout << "Error: Shifts avaliable are Day (1) and Night (2)\n";
		cout << "Enter shift: ";
		cin >> s;
	}
	this->shift = s;
	return *this;
}
ProductionWorker& ProductionWorker::setPayRate(double pR)
{
	this->payRate = pR;
	return *this;
}

int ProductionWorker::getShift() const
{
	return this->shift;
}
double ProductionWorker::getPayRate() const
{
	return this->payRate;
}

ostream& operator << (ostream& out,const ProductionWorker& aWorker)
{
	
	out << "Name" << setw(width*2)<< "Employee ID" << setw(width) << "Hire Date" << setw(width)
		<< "Employee Shift" << setw(width) << "Hourly pay\n";
	out << aWorker.getName() << setw(width+10) << aWorker.getNumber() << setw(width) << aWorker.getHireDate() << setw(width);
		if (aWorker.shift == 1)
			out << "Day" << setw(width) << aWorker.payRate << endl;
		else
			out << "Night" << setw(width) << aWorker.payRate << endl;
	return out;

}

istream& operator >> (istream& in, ProductionWorker& aWorker)
{
	aWorker.askEmployeeInfo();
	cout << "Enter employee's designated shift: (Day=1, Night=2)\n";
	in >> aWorker.shift;
	cout << "Enter employee's pay rate: ";
	in >> aWorker.payRate;

	return in;
}
