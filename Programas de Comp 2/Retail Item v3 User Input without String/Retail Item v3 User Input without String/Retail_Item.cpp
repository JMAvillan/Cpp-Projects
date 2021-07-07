#include <iostream>
#include<cstring>
#include <iomanip>

using namespace std;
#include "Retail_Item.h"
Retail_Item::Retail_Item()
{
	char temp[] = " ";
	setDesc(temp);
	setUnits(0);
	setPrice(0);
}
Retail_Item::Retail_Item(char *desc, int units, double p)
{
	setDesc(desc);
	setUnits(units);
	setPrice(p);
}
void Retail_Item::initDescription(char *d)
{
	description = new char[strlen(d) + 1];
	strcpy_s(description, strlen(d) + 1, d);
}
Retail_Item& Retail_Item::setInfo(char* d, int units, double p)
{
	this->setDesc(d);
	this->setUnits(units);
	this->setPrice(p);
	return *this;
}
Retail_Item& Retail_Item::setDesc(char* d)
{
	this->initDescription(d);
	return *this;
}
Retail_Item& Retail_Item::setPrice(double p)
{
	this->price = p;
	return *this;
}
Retail_Item& Retail_Item::setUnits(int units)
{
	this->unitsOnHand = units;
	return *this;
}
void Retail_Item::getInfo(int count) const
{

		cout << setw(25) << "Description" << setw(10) << "On hand" << setw(10) << "Price" << endl
			<< "_____________________________________________________________________________" << endl;

	cout << "Item #" << count + 1 << setw(18) << this->getDescription()
		<< setw(10) << this->getUnitsOnHand() << setw(10)
		<< this->getPrice() << endl;
}

char* Retail_Item::getDescription() const
{
	return this->description;
}
int Retail_Item::getUnitsOnHand() const
{
	return this->unitsOnHand;
}
double Retail_Item::getPrice() const
{
	return this->price;
}
