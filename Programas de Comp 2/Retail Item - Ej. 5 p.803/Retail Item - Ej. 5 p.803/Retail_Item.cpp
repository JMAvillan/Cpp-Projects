#include "Retail_Item.h"
#include<string>
#include <iomanip>
using namespace std;

Retail_Item::Retail_Item()
{
setDescription("N/A");
setUnitsOnHand(0);
setPrice(0);

}
Retail_Item::Retail_Item (string desc, int units, double p)
{
	setDescription(desc);
	setUnitsOnHand(units);
	setPrice(p);
}
Retail_Item::Retail_Item(const Retail_Item& anItem)
{
	setDescription(anItem.getDescription());
	setUnitsOnHand(anItem.getUnitsOnHand());
	setPrice(anItem.getPrice());
}
void Retail_Item::setDescription(string desc)
{
	description = desc;
}
void Retail_Item::setUnitsOnHand(int units)
{
	unitsOnHand = units;
}
void Retail_Item::setPrice(double  p)
{
	price = p;
}
string Retail_Item::getDescription() const
{
	return description;
}
int Retail_Item::getUnitsOnHand() const
{
	return unitsOnHand;
}
double Retail_Item::getPrice() const
{
	return price;
}
