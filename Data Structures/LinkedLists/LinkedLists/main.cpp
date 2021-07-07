#include <iostream>
#include "LinkedBag.h"
using namespace std;

int main()
{
	LinkedBag<int> list1;

	list1.add(2);
	list1.add(4);
	list1.add(6);
	list1.add(7);
	list1.add(4);
	cout << "List 1 items: \n";
	list1.print();
	LinkedBag<int> list2(list1);
	list1.remove(6);
	list2.removeIntact(6);

	cout << "List that used remove funciton: \n";
	list1.print();

	cout << "List that used removeIntact funciton: \n";
	list2.print();

	cout << "AddToEnd Function for list1: \n";
	list1.addToEnd(1);
	list1.print();

	//LinkedBag<int> list2(list1);
	//list2.print();
	//cout << "La lista 1 contiene " << list1.getCurrentSize() << " elementos.\n";

	//if (list1.remove(6))
	//{
	//	cout << "La lista elimino el elemento 6.\n";
	//	list1.print();
	//}
	//else
	//{
	//	cout << "El elemento 6 no esta dentro de la lista.\n";
	//	list1.print();
	//}
	//if (list1.contains(4))
	//	cout << "La lista contiene el elemento 4.\n";
	//else
	//	cout << "La lista no contiene el elemento 4.\n";
	//
	//cout << "Cantidad que el 4: " << list1.getFrequencyOf(4) << " veces.\n";




	system("pause");
	return 0;
}