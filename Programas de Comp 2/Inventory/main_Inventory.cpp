#include <iostream>
#include "Inventory.h"
using namespace std;

int main()
{
	Inventory item1;
	int itemNum, itemQuantity;
	double itemCost;

	cout << "Please input the following item information: \n";
	cout << "Input item number: ";
	cin >> itemNum;
	cout << "Input item cost: $";
	cin >> itemCost;
	cout << "Input quantity of item: ";
	cin >> itemQuantity;

	item1.setItemNumber(itemNum);
	item1.setQuantity(itemQuantity);
	item1.setCost(itemCost);
	item1.setTotalCost();
	item1.display();

	cout << "Item 2: \n";
	Inventory item2(89, 59.99, 10);
	item2.display();

	cout << "Copy of first item: \n";
	Inventory item3(item1);
	item3.display();

	system("pause");
	return 0;
}