#pragma once
#include <string>
using namespace std;
class Automobile
{
 // The Automobile class holds general data
 // about an automobile in inventory.

private:
	string make; // The auto's make
	int model; // The auto's year model
	int mileage; // The auto's mileage
	double price; // The auto's price
public:
	friend ostream& operator << (ostream&, const Automobile& anAutomobile);
	friend istream& operator >>(istream&, Automobile& anAutomobile);

	 // Default constructor
	Automobile();
	 // Constructor
	Automobile(string autoMake, int autoModel, int autoMileage, double autoPrice);
	//Mutators
	Automobile& setMake(string);
	Automobile& setModel(int);
	Automobile& setMileage(int);
	Automobile& setPrice(double);
	Automobile& askAutomobileInfo();


	// Accessors
	string getMake() const;
	int getModel() const;
	int getMileage() const;
	double getPrice() const;
}; 

