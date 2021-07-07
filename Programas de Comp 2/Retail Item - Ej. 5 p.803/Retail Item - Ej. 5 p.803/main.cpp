#include <iostream>
#include <iomanip>
#include "Retail_Item.h"
using namespace std;

int main()
{

	const int ITEM_QUANTITY = 3;
	Retail_Item retail_Inventory[ITEM_QUANTITY] = { {"Jacket", 12,59.95},
													{"Designer Jeans",40, 34.95},
													{"Shirt",20,24.95} };



	cout << setw(25) << "Description" << setw(10) << "On hand" << setw(10) << "Price" << endl
		<< "_____________________________________________________________________________" << endl;
	for (int count = 0; count < ITEM_QUANTITY; count++)
	{
		cout << "Item #" << count + 1 << setw(18) << retail_Inventory[count].getDescription()
			<< setw(10) << retail_Inventory[count].getUnitsOnHand() << setw(10)
			<< retail_Inventory[count].getPrice() << endl;


	}
	system("pause");
	return 0;
}