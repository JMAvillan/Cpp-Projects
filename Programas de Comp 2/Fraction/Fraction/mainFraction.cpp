#include "Fraction.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

void displayMenu(Fraction&, Fraction&);

int main()
{
	Fraction first, second;

	bool exit = false;
	char input;
	do
	{
		displayMenu(first, second);

		Fraction third(second), thirdS;

		thirdS = third;
		thirdS.simplify();
		//third using copy constructor
		cout << "Copy constructor fraction using the second fraction: " << third << endl;
		//fourth using assign 
		if (third != thirdS)
			cout << "The fraction simplifies to: " << thirdS << endl;
		else
			cout << "The assigment operator fraction stayed the same: " << thirdS << endl;


		cout << "Run program again? (Yes='Y' No='N')\n";
		cin >> input;
		if (input == 'y' || input == 'Y')
		{
		}//run again
		else if (input == 'n' || input == 'N')
		{
			cout << "Exiting now...\n";
			exit = true;
		}
		else
		{
			cout << "Invalid Input. \nClosing progam...\n";
			exit = true;
		}
	} while (exit == false);
	system("pause");
	return 0;
}
void displayMenu(Fraction& first, Fraction& second)
{

	Fraction op, test;
	cout << "What operation do you want to perform?\n"
		<< "A. Calculate sum of two rational numbers\n"
		<< "B. Calculate difference between two rational numbers\n"
		<< "C. Multiply two rational numbers\n"
		<< "D. Find the quotient of two rational numbers\n"
		<< "E. Exit program\n";

	char input;
	cin >> input;
	switch (input)
	{
	case 'A':
	case 'a':
	{
		cout << "First fraction\n";
		cin >> first;
		cout << "Second fraction:\n";
		cin >> second;
		op = first + second;
		test = op;
		cout << "The sum of those two fractions is " << op << ". \n";
		op.simplify();
		if (test != op)
			cout << "The fraction simplifies to " << op << ".\n";
		break;
	}
	case 'B':
	case 'b':
	{
		cout << "First fraction\n";
		cin >> first;
		cout << "Second fraction:\n";
		cin >> second;

		op = first - second;
		test = op;
		cout << "The difference between those two fractions is " << op << ". \n";
		op.simplify();
		if (test != op)
			cout << "The fraction simplifies to " << op << ".\n";
		break;

	}
	case 'C':
	case 'c':
	{
		cout << "First fraction\n";
		cin >> first;
		cout << "Second fraction:\n";
		cin >> second;
		op = first * second;
		test = op;
		cout << "The result of those two fractions is " << op << ". \n";
		op.simplify();
		if (test != op)
			cout << "The fraction simplifies to: " << op << ".\n";

		break;
	}
	case 'D':
	case 'd':
	{
		cout << "First fraction\n";
		cin >> first;
		cout << "Second fraction:\n";
		cin >> second;
		op = first / second;
		cout << "The quotient of the two fractions is " << op << ". \n";
		test = op;
		op.simplify();
		if (test != op)
			cout << "The fraction simplifies to: " << op << ".\n";

		break;
	}
	case 'E':
	case'e':
	{
		cout << "Exit successful. Goodbye!\n";
		exit(0);
	}
	}
}