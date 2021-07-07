#pragma once
#include "Package.h"
#include "BoundCheck.h"
class OvernightPackage :
	public Package
{
private:
	double extraFeePerOunce;
public:
	OvernightPackage(double extraFee = 5.44);
	OvernightPackage(const OvernightPackage&  overnight);
	void setExtraFee(double extraFee) throw (BoundCheck);
	double getExtraFee() const;
	double calculateCost()const;
	void displayInfo() const;
	OvernightPackage& operator = (const OvernightPackage& overnight);
	OvernightPackage& operator = (const Package& package);
};

