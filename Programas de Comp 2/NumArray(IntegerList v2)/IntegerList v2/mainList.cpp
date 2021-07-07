#include<iostream>
#include <fstream>
using namespace::std;
#include "NumArray.h"

int main()
{

	int size;

	cout << "How many numbers you wish to enter?\n";
	cin >> size;
	NumArray numbers(size);


	cin >> numbers;
	cout << endl;
	cout << "What information do you want to see?\n A. Full List\n B.Specify positon\n";
	char input;
	cin >> input;
	if (input == 'A' || input == 'a')
	{
		cout << numbers;
		cout << endl;
	}
	else
		if (input == 'B' || input == 'b')
		{
			int num;
			cout << "What item do you wish to see? \n";
			cin >> num;
			cout << "Showing number in position " << num << endl;
			cout << numbers[num - 1] << endl;
		}


	cout << "Copy constructor: \n";
	NumArray numbers2(numbers);
	cout << numbers2;

	cout << "Copy using = operator\n";
	NumArray numbers3;
	numbers3 = numbers2;
	cout << numbers3;

	cout << "Make new list. How many items do you wish to enter in new list?\n";
	cin >> size;
	NumArray numbers4(size);
	cin >> numbers4;

	cout << "Comparing lists:\n\n";
	if (numbers == numbers2)
	{
		cout << "List 1 and list 2 are the same.\n";
		cout << "List 1:\n";
		cout << numbers;
		cout << "List 2:\n";
		cout << numbers2;
	}
	else if (numbers != numbers2)
	{
		cout << "List 1 and list 2 are different.\n";
		cout << "List 1:\n";
		cout << numbers;
		cout << "List 2:\n";
		cout << numbers2;
	}
	if (numbers3 == numbers2)
	{
		cout << "List 2 and list 3 are the same.\n";
		cout << "List 2:\n";
		cout << numbers2;
		cout << "List 3:\n";
		cout << numbers3;
	}
	else if (numbers3 != numbers2)
	{
		cout << "List 2 and list 3 are different.\n";
		cout << "List 2:\n";
		cout << numbers2;
		cout << "List 3:\n";
		cout << numbers3;
	}
	if (numbers3 == numbers4)
		{
			cout << "List 3 and list 4 are the same.\n";
			cout << "List 3:\n";
			cout << numbers3;
			cout << "List 4:\n";
			cout << numbers4;
		}
		else if (numbers3 != numbers4)
		{
			cout << "List 3 and list 4 are different.\n";
			cout << "List 3:\n";
			cout << numbers3;
			cout << "List 4:\n";
			cout << numbers4;
		}
		int subs;
		cout << "Lets look for a subscript in each list:\n"
			<< "Specify subscript: ";
		cin >> subs;
		cout << "List 1: \tList 2: \tList 3: \tList 4:\n";
		cout << numbers[subs - 1] << "\t\t" << numbers2[subs - 1] << "\t\t" << numbers3[subs - 1] << "\t\t" << numbers4[subs - 1] << endl;

		system("pause");
		return 0;
}