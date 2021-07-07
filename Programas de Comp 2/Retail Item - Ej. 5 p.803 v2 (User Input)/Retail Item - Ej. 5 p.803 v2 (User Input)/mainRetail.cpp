#include <iostream>
#include <iomanip>
#include "Retail_Item.h"
using namespace std;

int main()
{

	const int ITEM_QUANTITY = 3;
	Retail_Item retail_Inventory[ITEM_QUANTITY]; /*{ {"Jacket", 12,59.95},
													{"Designer Jeans",40, 34.95},
													{"Shirt",20,24.95} };*/
	cout << "The following program will allow you to enter 3 retail items.\n";
	for (int count = 0; count < ITEM_QUANTITY; count++)
	{
		retail_Inventory[count].setInfo();
	}

	for (int count = 0; count < ITEM_QUANTITY; count++)
	{
		retail_Inventory[count].getInfo(count);
	}
	system("pause");
	return 0;
}