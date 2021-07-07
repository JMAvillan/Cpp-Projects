#include "Truck.h"
#include <iostream>
#include <string>
using namespace std;
// Default constructor
Truck::Truck() : Automobile()
{
	driveType = "";
}

// Constructor #2
Truck::Truck(string truckMake, int truckModel, int truckMileage,
	double truckPrice, string truckDriveType) :
	Automobile(truckMake, truckModel, truckMileage, truckPrice)
{
	driveType = truckDriveType;
}

// Mutator for driveType attribute
Truck& Truck::setDriveType(string dT)
{
	this->driveType = dT;
	return (*this);
}
string Truck::getDriveType() const // Accessor for driveType attribute
{
	return this->driveType;
}

ostream& operator << (ostream& out, const Truck& aTruck)
{
	out << aTruck.getModel() << " " << aTruck.getMake()
		<< " with " << aTruck.getDriveType()
		<< " drive type and " << aTruck.getMileage()
		<< " miles.\nPrice: $" << aTruck.getPrice()
		<< endl << endl;
	return out;
}
istream& operator >>(istream& in, Truck& aTruck)
{
	string driveType;
	
	aTruck.askAutomobileInfo();
	cout << "Enter car drive type: ";
	cin.ignore();
	getline(cin,driveType);

	aTruck.setDriveType(driveType);

	return in;

}