#pragma once
#include "Employee.h"
#include <iostream>
using namespace std;
class ProductionWorker : public Employee
{private:
	int shift;
	double payRate;
public:
	ProductionWorker();
	ProductionWorker(int s, double payR, const MyString& tempName, const MyString& tempId, const Date& tempDate);
	ProductionWorker(const ProductionWorker&);
	~ProductionWorker();

	ProductionWorker& setShift(int);
	ProductionWorker& setPayRate(double);

	int getShift() const;
	double getPayRate() const;

	friend ostream& operator << (ostream& out, const ProductionWorker&);
	friend istream& operator >> (istream& in, ProductionWorker&);

};

