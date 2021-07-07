#include "SUV.h"
#include <iostream>
#include <string>
using namespace std;


// Default constructor
SUV:: SUV() : Automobile()
{
	this->passengers = 0;
}

// Constructor #2
SUV::SUV(string SUVMake, int SUVModel, int SUVMileage,
	double SUVPrice, int SUVPassengers) :
	Automobile(SUVMake, SUVModel, SUVMileage, SUVPrice)
{
	this->passengers = SUVPassengers;
}

// Accessor for passengers attribute
SUV& SUV::setPassengers(int p)
{
	this->passengers = p;
	return *this;
}

// Accessor for passengers attribute
int SUV::getPassengers() const
{
	return this->passengers;
}

ostream& operator << (ostream& out, const SUV& aSUV)
{
	out << aSUV.getModel() << " " << aSUV.getMake()
		<< " with " << aSUV.getMileage() << " miles and "
		<< aSUV.getPassengers() << " passenger capacity.\n"
		<< "Price: $" << aSUV.getPrice() << endl;
	return out;
}

istream& operator >>(istream& in, SUV& aSUV) {
	int passengers;

	aSUV.askAutomobileInfo();
	cout << "Enter passenger capacity: ";
	cin >> passengers;
	aSUV.setPassengers(passengers);
	return in;
}