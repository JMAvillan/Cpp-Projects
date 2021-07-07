#ifndef RETAIL__ITEM_H
#define RETAIL_H
#include<iostream>
using namespace std;

class Retail_Item
{
private:
	char *description;
	int unitsOnHand;
	double price;
public:
	Retail_Item();
	Retail_Item(char*, int, double);
	void initDescription(char *d);
	Retail_Item &setInfo(char*, int, double);
	Retail_Item &setDesc(char*);
	Retail_Item &setPrice(double);
	Retail_Item &setUnits(int);
	void getInfo(int) const;
	char *getDescription() const;
	int getUnitsOnHand() const;
	double getPrice() const;
};
#endif