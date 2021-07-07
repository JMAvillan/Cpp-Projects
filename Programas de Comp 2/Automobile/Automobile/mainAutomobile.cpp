// This program demonstrates the Car, Truck, and SUV 
// classes that are derived from the Automobile class.
#include <iostream>
#include <iomanip>
#include "Car.h"
#include "Truck.h"
#include "SUV.h"
using namespace std;
int main()
{	
	Car car;
	Truck truck;
	SUV suv;

	cout << "Enter vehicles to inventory: \n";
	
	cout << "Enter car information: \n";
	cin >> car;

	cout << "Enter truck information: \n";
	cin >> truck;

	cout << "Enter SUV information: \n";
	cin >> suv;

	// Create a Truck object for a used 2006 Toyota
	// pickup with 40,000 miles, priced at $12,000,
	// with 4-wheel drive.


	// Create an SUV object for a used 2005 Volvo
	// with 30,000 miles, priced at $18,000, with
	// 5 passenger capacity.
	
	// Display the automobiles we have in inventory.
	cout << fixed << showpoint << setprecision(2);
	cout << "We have the following car in inventory:\n";
	cout << car;

	cout << "We have the following truck in inventory:\n";
	cout << truck;

	cout << "We have the following SUV in inventory:\n";
	cout << suv;

	system("pause");
	return 0;
}
