#include <iostream>
#include "coinToss.h"
using namespace std;

int main()
{
	coinToss coin1;
	int numToss = 20, numOfHeads=0, numOfTails=0;

	cout << "Default toss: ";
	cout << coin1.getSideUp() << endl;

	for (int count = 0; count < numToss; count++)
	{
		cout << "Toss #" << count+1 << ": ";
		coin1.toss();
		cout << coin1.getSideUp();

		string SideUp;
		SideUp = coin1.getSideUp();
		if (SideUp == "Heads")
		{
			numOfHeads++;
		}
		if (SideUp == "Tails")
		{
			numOfTails++;
		}
		

	}
	cout << "The number of heads where " << numOfHeads << ".\n";
	cout << "The number of tails where " << numOfTails << ".\n";


	system("pause");
	return 0;
}