#include "Retail_Item.h"
#include<string>
#include <iomanip>
#include <iostream>
using namespace std;

Retail_Item::Retail_Item()
{

	description = "N/A";
	unitsOnHand = 0;
	price = 0;

}
Retail_Item::Retail_Item(string desc, int units, double p)
{
	description = desc;
	unitsOnHand = units;
	price = p;
}

void Retail_Item::setInfo()
{
	cout << "Enter item description: "; 
	cin.ignore();
	getline(cin, description);
	
	do
	{cout << "Enter item price: ";
		cin >> price;
		if (price > 0)
		{
		}
		else if( price < 0)
			cout << "Wrong input. Please Try again. \n";
		else
		{
			cout << "Wrong input. Please Try again. \n";
			price = -1;
		}

	} while (price < 0);
	cout << "Enter current on hand: ";
	cin >> unitsOnHand;
}

void Retail_Item::getInfo(int count ) const
{
	if(count ==0)
	{
		cout << setw(25) << "Description" << setw(10) << "On hand" << setw(10) << "Price" << endl
		<< "_____________________________________________________________________________" << endl;
	} 

		cout << "Item #" << count + 1 << setw(18) << getDescription()
			<< setw(10) << getUnitsOnHand() << setw(10)
			<< getPrice() << endl;
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
