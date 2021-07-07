#pragma once
#include "Automobile.h"
#include <string>
using namespace std;
class Car :public Automobile
{
	 private:
	 int doors;
	
	 public:
		 friend ostream& operator << (ostream&, const Car&);
		 friend istream& operator >>(istream&, Car&);

		 // Default constructor
		 Car();
		
		 // Constructor #2
		 Car(string carMake, int carModel, int carMileage,
			 double carPrice, int carDoors);

		 // Mutator for doors attribute
		 Car& setDoors(int);
		 // Accessor for doors attribute
		 int getDoors() const;

};

