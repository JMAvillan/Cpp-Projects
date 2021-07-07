#include "Automobile.h"
#include <string>
#include <iostream>
using namespace std;

// Default constructor
Automobile::Automobile()
{
	make = "";
	model = 0;
	mileage = 0;
	price = 0.0;
}

// Constructor
Automobile::Automobile(string autoMake, int autoModel,
	int autoMileage, double autoPrice)
{
	make = autoMake;
	model = autoModel;
	mileage = autoMileage;
	price = autoPrice;
}
//Mutators
Automobile& Automobile::setMake(string m)
{
	this->make = m;
	return *this;
}
Automobile& Automobile::setModel(int mdl)
{
	this->model = mdl;
	return *this;
}
Automobile& Automobile::setMileage(int mlg)
{
	this->mileage = mlg;
	return *this;
}
Automobile& Automobile::setPrice(double p) 
{
	this->price = p;
	return *this;
}

Automobile& Automobile::askAutomobileInfo()
{
	string make;
	int model;
	int mileage;
	double price;

	cout << "Enter vehicle model: ";
	cin >> model;
	cout << "Enter vehicle make: ";
	cin.ignore();
	getline(cin, make);
	cout << "Enter vehicle mileage: ";
	cin >> mileage;
	cout << "Enter vehicle price: ";
	cin >> price;

	this->setMake(make).setMileage(mileage).setModel(model).setPrice(price);
	return *this;
}


// Accessors
string Automobile::getMake() const
{
	return make;
}
int Automobile::getModel() const
{
	return model;
}
int Automobile::getMileage() const
{
	return mileage;
}

double Automobile::getPrice() const
{
	return price;
}

ostream& operator << (ostream& out, const Automobile& anAutomobile)
{
	out << anAutomobile.getModel() << " " << anAutomobile.getMake()
		<< " with " << anAutomobile.getMileage() << " miles.\nPrice: $"
		<< anAutomobile.getPrice() << endl << endl;
	return out;
}

istream& operator >>(istream& in, Automobile& anAutomobile)
{
	anAutomobile.askAutomobileInfo();
	return in;
}