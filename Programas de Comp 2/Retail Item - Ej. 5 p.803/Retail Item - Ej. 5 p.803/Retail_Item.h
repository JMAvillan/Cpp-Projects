#ifndef RETAIL__ITEM_H
#define RETAIL_H
#include <string>
using namespace std;

class Retail_Item
{
private:
	string description;
	int unitsOnHand;
	double price;
public:
	Retail_Item();
	Retail_Item(string, int, double);
	Retail_Item(const Retail_Item&);
	void setDescription(string);
	void setUnitsOnHand(int);
	void setPrice(double);
	string getDescription() const;
	int getUnitsOnHand() const;
	double getPrice() const;
};
#endif