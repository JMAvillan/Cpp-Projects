#include "TwoDayPackage.h"
#include <iostream>
#include <iomanip>
using namespace std;

TwoDayPackage::TwoDayPackage(double tDFee) : twoDayFee(tDFee) {}
TwoDayPackage::TwoDayPackage(const TwoDayPackage& twoDFee)
{
	*this = twoDFee;
}
void TwoDayPackage::setTwoDayFee(double tDFee) 
{
	if (tDFee > 0)
		this->twoDayFee = tDFee;
	else
	throw BoundCheck(tDFee);
}
double TwoDayPackage::getTwoDayFee() const
{
	return this->twoDayFee;
}

double TwoDayPackage::calculateCost() const
{
	return (this->getCostPerOunce() * this->getWeight()+this->getTwoDayFee());
}

void TwoDayPackage::displayInfo() const
{
	cout << "Two Day Package Shipping Information:\n";
	this->displaySender();
	this->displayReceiver();
	cout << "Package weight: " << this->getWeight() << endl;
	cout << "Total cost: $" <<setprecision(2) <<this->calculateCost() << endl;
}


TwoDayPackage& TwoDayPackage::operator = (const TwoDayPackage& twoDFee)
{
	this->setValues(twoDFee.getName(0), twoDFee.getAddress(0), twoDFee.getCity(0), twoDFee.getState(0),
		twoDFee.getZipCode(0), 0);
	this->setValues(twoDFee.getName(1), twoDFee.getAddress(1), twoDFee.getCity(1), twoDFee.getState(1),
		twoDFee.getZipCode(1), 1);
	this->setWeight(twoDFee.getWeight());
	this->setCostPerOunce(twoDFee.getCostPerOunce());
	this->setTwoDayFee(twoDFee.getTwoDayFee());
	return *this;
}
TwoDayPackage& TwoDayPackage::operator = (const Package& package)
{
	this->setValues(package.getName(0), package.getAddress(0), package.getCity(0), package.getState(0),
		package.getZipCode(0), 0);
	this->setValues(package.getName(1), package.getAddress(1), package.getCity(1), package.getState(1),
		package.getZipCode(1), 1);
	this->setWeight(package.getWeight());
	this->setCostPerOunce(package.getCostPerOunce());
	return *this;
}