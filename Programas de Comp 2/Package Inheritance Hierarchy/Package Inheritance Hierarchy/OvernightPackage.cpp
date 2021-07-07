#include "OvernightPackage.h"
#include <iostream>
#include <iomanip>
using namespace std;

OvernightPackage::OvernightPackage(double extraFee):extraFeePerOunce(extraFee){}
OvernightPackage::OvernightPackage(const OvernightPackage& overnight)
{
	*this = overnight;
}

void OvernightPackage::setExtraFee(double extraFee)
{
	if (extraFee > 0)
		this->extraFeePerOunce = extraFee;
	else
		throw BoundCheck(extraFee);
}
double OvernightPackage::getExtraFee() const {
	return this->extraFeePerOunce;
}

double OvernightPackage::calculateCost() const
{
	return (this->getCostPerOunce() * this->getWeight() + this->getExtraFee()*this->getWeight());
}

void OvernightPackage::displayInfo() const
{
	cout << "Overnight Package Shipping Information:\n";
	this->displaySender();
	this->displayReceiver();
	cout << "Package weight: " << this->getWeight() << endl;
	cout << "Total cost: $" << setprecision(2) << this->calculateCost() << endl;

}

OvernightPackage& OvernightPackage::operator = (const OvernightPackage& overnight)
{
	this->setValues(overnight.getName(0), overnight.getAddress(0), overnight.getCity(0), overnight.getState(0),
		overnight.getZipCode(0),0);
	this->setValues(overnight.getName(1), overnight.getAddress(1), overnight.getCity(1), overnight.getState(1),
		overnight.getZipCode(1), 1);
	this->setWeight(overnight.getWeight());
	this->setCostPerOunce(overnight.getCostPerOunce());
	this->setExtraFee(overnight.getExtraFee());
	return *this;
}
OvernightPackage& OvernightPackage::operator = (const Package& package)
{
	this->setValues(package.getName(0), package.getAddress(0), package.getCity(0), package.getState(0),
		package.getZipCode(0), 0);
	this->setValues(package.getName(1), package.getAddress(1), package.getCity(1), package.getState(1),
		package.getZipCode(1), 1);
	this->setWeight(package.getWeight());
	this->setCostPerOunce(package.getCostPerOunce());
	return *this;
}