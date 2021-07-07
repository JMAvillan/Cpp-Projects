#include "payroll.h"
#include <iostream>
using namespace std;

payroll::payroll()
{
	setHoursworked(0);
	setHourlyPay(0);
	setTotalPay();
}
payroll::payroll(double worked, double pay)
{
	setHoursworked(worked);
	setHourlyPay(pay);
	setTotalPay();
}

payroll::payroll(const payroll& anPayroll)
{
	setHoursworked(anPayroll.getHoursWorked());
	setHourlyPay(anPayroll.getHourlyPay());
	

	setTotalPay();
}
void payroll::setHoursworked(double w)
{
	if (w > 60)
	{
		cout << "Invalid input\n"
			<< "Worked hours cannot exceed 60 hours.\n";
	}
	else
	hoursWorked = w;
}
void payroll::setHourlyPay(double hP)
{
	hourlyPay = hP;
}
void payroll::setTotalPay()
{
	totalPay = getHourlyPay() * getHoursWorked();

}
void payroll::setInfo(double hours ,double hourlyP)
{
	setHoursworked(hours);
	setHourlyPay(hourlyP);
}
double payroll::getHoursWorked() const
{
	return hoursWorked;
}
double payroll::getHourlyPay()const
{
	return hourlyPay;
}
double payroll::getTotalPay()const
{
	return totalPay;
}
