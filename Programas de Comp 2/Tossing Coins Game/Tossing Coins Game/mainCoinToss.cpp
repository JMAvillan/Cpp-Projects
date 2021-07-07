#include <iostream>
#include <iomanip>
#include "coinToss.h"
using namespace std;

int main()
{
	coinToss quarter, dime, nickel;

	double balance = 0.0;

	cout << "This game simulates three simultaneous coin throws.\n";
	cout << "It would throw a dime, a nickel and a quarter. Your \n"
		<< "goal is to get to one dollar. If it lands head that\n"
		<< "value adds to your score.\n";
	cout << "Press enter to begin...";
	cin.get();
	
	while (balance < 1)
	{
		int counter=0;
		quarter.toss();
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		if (quarter.getSideUp() == "Heads")
		{
			balance += .25;
			cout << "+\t Quarter landed on heads.\t\t\t+\n";
			counter++;
		}
		dime.toss();
		if (dime.getSideUp() == "Heads")
		{
			balance += .05;
			cout << "+\t Dime landed on heads. \t\t\t\t+\n";
			counter++;
		}
		nickel.toss();
		if (nickel.getSideUp() == "Heads")
		{
			balance += .10;
			cout << "+\t Nickel landed on heads.\t\t\t+\n";
			counter++;
		}
		
		if (balance < 1)
		{
		if (counter == 0)
				cout << "+\t No coins landed on heads!\t\t\t+\n";

		if (counter == 3)
			cout << "+\t Congratulations all three landed on heads!\t+\n";

		 cout << "+\t Your current balance is $" << setprecision(2) << balance << "\t\t\t+\n";
		 cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << "\nPress enter to throw again \n";
			cin.get();
		
		}
	}
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	if (balance == 1)
		cout << "\nCongratulations you won the game!\n";
	else
		cout << "\nYou lost\n";

cout << "Your balance is " << balance << endl;

	system("pause");
	return 0;
}