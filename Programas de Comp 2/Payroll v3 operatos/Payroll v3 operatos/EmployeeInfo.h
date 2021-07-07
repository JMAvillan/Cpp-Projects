#ifndef EmployeeInfoINFO_H
#define EmployeeInfoINFO_H
#include <string>
#include <iostream>

using namespace std;

class EmployeeInfo
{
private:
	string name,
		department,
		position;
	int idNumber;
	double hoursWorked, hourlyPay, totalPay;

public:
	//overloading operators
	friend ostream& operator<< (ostream& out, const EmployeeInfo&);
	friend istream& operator>> (istream& in,  EmployeeInfo&);
	EmployeeInfo operator =(const EmployeeInfo&);
	bool operator <(const EmployeeInfo&) const;
	bool operator >(const EmployeeInfo&) const;
	bool operator ==(int &) const;


	EmployeeInfo();
	EmployeeInfo(string, int, string, string, double, double);
	EmployeeInfo(const EmployeeInfo&);
	void initEmployee();
	void enterEmployeeInfo();
	void enterPayrollInfo();

	void setInfo(string, int, string, string);
	void setName(string);
	void setDepartment(string);
	void setPosition(string);
	void setIdNumber(int);
	string getName()const;
	string getDepartment()const;
	string getPosition() const;
	int getIdNumber() const;

	//payroll related
	void setPayroll(double, double);
	void setHoursworked(double);
	void setHourlyPay(double);
	void setTotalPay();
	double getHoursWorked() const;
	double getHourlyPay()const;
	double getTotalPay()const;


};
#endif
