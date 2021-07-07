#pragma once
#include "Package.h"
#include "BoundCheck.h"
class TwoDayPackage :
	public Package
{
private:
	double twoDayFee;
public:
	TwoDayPackage(double tDFee = 7.65);
	TwoDayPackage(const TwoDayPackage& twoDayP);
	void setTwoDayFee(double tDFee) throw(BoundCheck);
	double getTwoDayFee() const;
	double calculateCost() const;
	void displayInfo() const;


	TwoDayPackage& operator = (const TwoDayPackage& twoDFee);
	TwoDayPackage& operator = (const Package& twoDFee);
};

