#pragma once
#include "Automobile.h"
#include <string>
using namespace std;
class Truck :
	public Automobile
{
private:
	string driveType;

public:
	friend ostream& operator << (ostream&, const Truck&);
	friend istream& operator >>(istream&, Truck&);

	// Default constructor
	Truck();
	// Constructor #2
	Truck(string truckMake, int truckModel, int truckMileage,
		double truckPrice, string truckDriveType);


	Truck& setDriveType(string); // Mutator for driveType attribute
	string getDriveType() const; // Accessor for driveType attribute
};
