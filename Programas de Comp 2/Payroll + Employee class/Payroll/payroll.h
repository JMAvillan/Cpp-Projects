#pragma once
class payroll
{
private:
	const int NUM_EMPLOYEES = 3;
	double hoursWorked, hourlyPay, totalPay;
public:
	payroll();
	payroll(double, double);
	payroll(const payroll &);
	void setHoursworked(double);
	void setHourlyPay(double);
	void setTotalPay();
	void setInfo(double, double);
	double getHoursWorked() const;
	double getHourlyPay()const;
	double getTotalPay()const;
	
};

