#include <iostream>
#include "SearchableVector.h"
#include <string>
 using namespace std;

 int main()
 {
	 const int SIZE = 3;
	 int count; 

	 SearchableVector<double> doubleTable(SIZE);
	 cout << "Enter " << SIZE << " real numbers:\n";
	 for (count = 0; count < SIZE; count++)
	 {
		 cout << count + 1 << ". "; 
		 cin >> doubleTable[count];
	 }
	 doubleTable.sort();
	 cout << "These values are in doubleTable:\n";
	 for (count = 0; count < SIZE; count++)
		 cout << count+1 <<". "<< doubleTable[count] << endl;

	double search;
	int result;
	cout << "Search for value in table: \n";
	cin >> search;
	result= doubleTable.findItem(search);
	if (result != -1)
	{
		cout << "Item found in subscript " << result << ": \n" \
			<< doubleTable.getElementAt(result) << endl;
	}
	else
		cout << "Item not found in list." << endl;

	//SearchableVector<string> stringTable(SIZE);
	//cout << "Enter " << SIZE << " strings:\n";
	//for (count = 0; count < SIZE; count++)
	//{
	//	cout << count + 1 << ". ";
	//	cin >> stringTable[count];
	//}
	//stringTable.sort();
	//cout << "These values are in stringTable:\n";
	//for (count = 0; count < SIZE; count++)
	//	cout << stringTable[count] << endl;

	//string find;
	//cout << "Search for value in table: \n";
	//getline(cin,find);
	//result =stringTable.findItem(find);
	//if (result != -1)
	//{
	//	cout << "Item found in subscript " << result << ": " \
	//		<< stringTable.getElementAt(result);
	//}
	//else
	//	cout << "Item not found in list." << endl;



	 
	system("pause");
	return 0;
 }