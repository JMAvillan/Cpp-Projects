#include <iostream>
#include <iomanip>
#include "Retail_Item.h"
using namespace std;

int main()
{
	int size = 50;
	char* d = nullptr;
	d = new char[size];

	double price;
	int units;

	const int ITEM_QUANTITY = 2;
	Retail_Item retail_Inventory[ITEM_QUANTITY]; /*{ {"Jacket", 12,59.95},
													{"Designer Jeans",40, 34.95},
													{"Shirt",20,24.95} };*/
	cout << "The following program will allow you to enter 3 retail items.\n";
	for (int count = 0; count < ITEM_QUANTITY; count++)
	{

		cout << "Enter item description: ";
		cin >>d;

		do
		{
			cout << "Enter item price: ";
			cin >> price;
			if (price > 0)
			{
			}
			else if (price < 0)
				cout << "Wrong input. Please Try again. \n";
			else
			{
				cout << "Wrong input. Please Try again. \n";
				price = -1;
			}

		} while (price < 0);
		cout << "Enter current on hand: ";
		cin >> units;
		retail_Inventory[count].setInfo(d, units, price).getInfo(count);
		cin.ignore();
	}


	system("pause");
	return 0;
}