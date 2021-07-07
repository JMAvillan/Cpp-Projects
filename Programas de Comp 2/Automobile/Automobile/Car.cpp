#include "Car.h"
#include <string>
#include <iostream>
using namespace std;
Car::Car() : Automobile()
{
	this->doors = 0;
}

// Constructor #2
Car::Car(string carMake, int carModel, int carMileage, 
	double carPrice, int carDoors) :
	Automobile(carMake, carModel, carMileage, carPrice)
{
	this->doors = carDoors;
}
//Mutator for doors attribute
Car& Car::setDoors(int d)
{
	this->doors = d;
	return *this;
}

// Accessor for doors attribute
int Car::getDoors() const
{
	return this->doors;
}

ostream& operator << (ostream& out, const Car& aCar)
{
	out << aCar.getModel() << " " << aCar.getMake()
		<< " with " << aCar.getDoors() << " doors and "
		<< aCar.getMileage() << " miles.\nPrice: $"
		<< aCar.getPrice() << endl << endl;
	return out;
}
istream& operator >>(istream& in, Car& aCar)
{
	int door;

	aCar.askAutomobileInfo();
	cout << "Enter car doors: ";
	cin >> door;
	
	aCar.setDoors(door);
	return in;

}