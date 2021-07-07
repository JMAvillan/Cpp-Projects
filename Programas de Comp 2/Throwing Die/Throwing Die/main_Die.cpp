#include "Die.h"
#include <iostream>
using namespace std;

void getProb(int);
void displayProb(int);

int main()
{
	const int DIE1_SIDES = 6;	//number of sides for die #1
	const int DIE2_SIDES = 12;	//number of sides for die #2
	const int MAX_ROLLS = 5;	//number of times to roll

	//create two instances of the die class
	Die die1(DIE1_SIDES);
	Die die2(DIE1_SIDES);

	//display the initial value of the dice
	cout << "This roll is simulates the rolling of a " << die1.getSides()
		<< " sided die and a " << die2.getSides() << "sided die.\n";

	cout << "The initial value of the dice: \n";
	cout << die1.getValue() << " "
		<< die2.getValue() << endl;

	//roll the dice 5 times
	cout << "Rolling the dice " << MAX_ROLLS << " times.\n";
	for (int count = 0; count < MAX_ROLLS; count++)
	{
		int sum;
		//roll the dice
		die1.roll();
		die2.roll();
		sum = die1.getValue() + die2.getValue();

		//dof this roll isplay the value of the dice
		cout << die1.getValue() << " "
			<< die2.getValue() << endl;
		getProb(sum);

	}
	system("pause");
	return 0;
}
void getProb(int sum)
{
	int counter;
	const int ROW = 6;
	int sumofDie[ROW] = { 1,2,3,4,5,6};
	for (int x = 0; x < ROW; x++)
	{
		for (int y = 0; y < ROW; y++)
		{
			if (sum == sumofDie[x] + sumofDie[y])
				counter++;
			if (x == 5 && y == 5)
				displayProb(counter);
		}
	}
	
}
void displayProb(int counter)
{
	switch (counter)
	{
	case 1:
		cout << "The probability of this roll is 1/36\n";
		break;
	case 2:
		cout << "The probability of this roll is 2/36\n";
		break;
	case 3:
		cout << "The probability of this roll is 3/36\n";
		break;
	case 4:
		cout << "The probability of this roll is 4/36\n";
		break;
	case 5:
		cout << "The probability of this roll is 5/36\n";
		break;
	case 6:
		cout << "The probability of this roll is 6/36\n";
		break;
	case 7:
		cout << "The probability of this roll is 5/36\n";
		break;
	case 8:
		cout << "The probability of this roll is 4/36\n";
		break;
	case 9:
		cout << "The probability of this roll is 3/36\n";
		break;
	case 10:
		cout << "The probability of this roll is 2/36\n";
		break;
	case 12:
		cout << "The probability of this roll is 1/36\n";
		break;
	}
}