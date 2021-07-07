#include "Package.h"
#include "BoundCheck.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

Package::Package(string n, string addss, string c, string s,
	int zip, double w, double costOunce)
{
	for (int x = 0; x < this->option; x++)
	{
		this->setValues(n, addss, c, s, zip, x);
	}
	this->setWeight(w);
	this->setCostPerOunce(costOunce);
}

Package& Package::setName(string n, int index)
{
	this->name[index] = n;
	return (*this);
}
Package& Package::setAddress(string addss, int index)
{
	this->address[index] = addss;
	return (*this);
}
Package& Package::setCity(string c, int index)
{
	this->city[index]= c;
	return (*this);
}
Package& Package::setState(string s, int index)
{
	this->state[index] = s;
	return (*this);
}
Package& Package::setZipCode(int zip, int index)
{
	this->zipCode[index] = zip;
	return (*this);
}
Package& Package::setWeight(double w)
{
	if (w >= 0)
		this->weight = w;
	else
		throw BoundCheck(w);

	return (*this);
}
Package& Package::setCostPerOunce(double costOunce)
{
	if (costOunce > 0)
		this->costPerOunce = costOunce;
	else
		throw BoundCheck(costOunce);

	return (*this);
}
void Package::setValues(string n, string addss, string c, string s, int zip, int index)
{
	setName(n, index).setAddress(addss, index).setCity(c, index).setState(s, index).setZipCode(zip, index);
}

string Package::getName(int index) const
{
	return this->name[index];
}
string Package::getAddress(int index) const
{
	return this->address[index];
}
string Package::getCity(int index) const
{
	return this->city[index];
}
string Package::getState(int index)const
{
	return this->state[index];
}
int Package::getZipCode(int index)const
{
	return this->zipCode[index];
}
double Package::getWeight()const
{
	return this->weight;
}
double Package::getCostPerOunce()const
{
	return this->costPerOunce;
}


void Package::displaySender() const
{
	cout << "Sender's Information: \n"
		<< "Name: " << this->name[0] << endl
		<< "Address: " << this->address[0] << endl
		<< "City: " << this->city[0] << endl
		<< "State: " << this->state[0] << endl
		<< "Zip Code: " << this->zipCode[0] << endl;
}
void Package::displayReceiver() const
{
	cout << "Receiver's Information: \n"
		<< "Name: " << this->name[1] << endl
		<< "Address: " << this->address[1] << endl
		<< "City: " << this->city[1] << endl
		<< "State: " << this->state[1] << endl
		<< "Zip Code: " << this->zipCode[1] << endl;
}

void Package::displayInfo() const
{
	cout << "Package Shipping Information:\n";
	this->displaySender();
	this->displayReceiver();
	cout << "Package weight: " << this->weight << endl;
	cout << "Total cost: $" << setprecision(2) << this->calculateCost() << endl;

}

double Package::calculateCost()const
{
	return (this->getCostPerOunce() * this->getWeight());
}
