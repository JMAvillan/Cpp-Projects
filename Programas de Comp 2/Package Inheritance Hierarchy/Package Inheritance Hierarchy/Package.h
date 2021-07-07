#pragma once
#include "BoundCheck.h"
#include <string>
using namespace std;

class Package
{
private :
	static const int option = 2;

	//[0]->sender [1]->receiver *Falta por Configurar
	string name[option],
		address[option],
		city[option],
		state[option];
	int zipCode[option];
	double weight,
		costPerOunce;
public:
	Package(string n ="", string addss = "", string c = "", string s = "", int zip = 12345, double w = 0.0, double costOunce = 2.66);
	
	Package& setName(string n, int index);
	Package& setAddress(string addss, int index);
	Package& setCity(string c, int index);
	Package& setState(string s, int index);
	Package& setZipCode(int zip, int index);
	Package& setWeight(double w) throw (BoundCheck);
	Package& setCostPerOunce(double costOunce) throw (BoundCheck);
	void setValues(string n, string addss, string c, string s, int zip, int index);

	string getName(int index) const;
	string getAddress(int index) const;
	string getCity(int index) const;
	string getState(int index)const;
	int getZipCode(int index)const;
	double getWeight()const;
	double getCostPerOunce()const;
	void displaySender() const;
	void displayReceiver() const;
	void displayInfo() const;

	double calculateCost()const; 

};

