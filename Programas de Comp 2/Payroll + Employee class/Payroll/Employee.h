#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;
class Employee
{
private:
	string name,
		department,
		position;
	int idNumber;
	double hoursWorked, hourlyPay, totalPay;

public:
	Employee();
	Employee(string, int, string, string,double, double);
	Employee(const Employee&,int);
	~Employee();
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
	void display();

	//payroll related
	void displayPayroll();
	void setPayroll(double, double);
	void setHoursworked(double);
	void setHourlyPay(double);
	void setTotalPay();
	double getHoursWorked() const;
	double getHourlyPay()const;
	double getTotalPay()const;

	
};
#endif
