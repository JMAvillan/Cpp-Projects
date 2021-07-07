#include "Inventory.h"
#include <iostream>
using namespace std;

Inventory::Inventory() {
	setItemNumber(0);
	setQuantity(0);
	setCost(0);
	setTotalCost();
}
Inventory::Inventory(int itemNum, double itemCost, int quantity)
{
	setItemNumber(itemNum);
	setQuantity(quantity);
	setCost(itemCost);
	setTotalCost();

}
//Copy constructor
Inventory::Inventory (const Inventory &anItem)
{
	setItemNumber(anItem.getItemNumber());
	setQuantity(anItem.getQuantity());
	setCost(anItem.getCost());
	setTotalCost();

}
void Inventory::setItemNumber(int itemNum) 
{
		itemNumber = itemNum;
}
void Inventory::setQuantity(int quant) 
{
	if (quant < 0)
	{
		cout << "Invalid input" << endl;
		exit(02);
	}
		else
			quantity = quant;
	}
void Inventory::setCost(double c)
{
	if (c < 0)
	{
		cout << "Invalid input" << endl;
		exit(03);
	}
	else
	cost = c;
		
}
void Inventory::setTotalCost()
{
	totalCost = getQuantity() * getCost();
}

int Inventory::getItemNumber() const
{
	return itemNumber;
}
int Inventory:: getQuantity() const
{
	return quantity;
}
double Inventory::getCost() const
{
	return cost;
}
double Inventory::getTotalCost() const
{
	return totalCost;
}
void Inventory::display()
{
	cout << "Item Summary: \n\n"
		<< "Item Number: " << getItemNumber() << endl
		<< "Item Cost: " << getCost() << endl
		<< "Item quantity: " << getQuantity() << endl
		<< "Total Cost: $" << getTotalCost() << endl << endl;
}