#pragma once
#include "Automobile.h"
class SUV :
	public Automobile
{
private:
	int passengers;

public:

	friend ostream& operator << (ostream&, const SUV&);
	friend istream& operator >>(istream&, SUV&);
	// Default constructor
	SUV();

	// Constructor #2
	SUV(string SUVMake, int SUVModel, int SUVMileage,
		double SUVPrice, int SUVPassengers);

	SUV& setPassengers(int);

	// Accessor for passengers attribute
	int getPassengers() const;
};

