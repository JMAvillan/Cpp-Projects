#include "Car.h"
#include <iostream>

using namespace std;
int main()
{
	const int SIZE = 3, SUBS = 50;

	Car cars[SIZE];
	char* tempD=nullptr;
	tempD = new char[SUBS];
	int tempY;

	for (int x = 0; x < SIZE; x++)
	{
		cout << "Car #" << x + 1 << endl;
		cout << "Enter car make: ";
		cin >> tempD;
		cout << "Enter car year: ";
		cin >> tempY;
		cars[x].setMake(tempD);
		cars[x].setYear(tempY);
	}

	cout << "\t\tAccelarting cars\n";
	for (int x = 0; x < SIZE; x++)
	{
		cout << "Car #" << x + 1 << " Model: " << cars[x].getYear() <<" "<< cars[x].getMake()
			<< " current speed: " << cars[x].getSpeed() << endl;
		for (int y=0; y < 5; y++)
		{
			cout <<"Current speed: " << cars[x].getSpeed() << endl;
			cars[x].accelerate();
		}
		cout << endl;
	}
	cout << "\t\tCars braking\n";
	for (int x = 0; x < SIZE; x++)
	{
		cout << "Car #" << x + 1 << " Model: " << cars[x].getYear()<< " " << cars[x].getMake()
			<< " current speed: " << cars[x].getSpeed() << endl;
		for (int y=0; y < 3; y++)
		{
			cout << "Current speed: " << cars[x].getSpeed() << endl;
			cars[x].brake();
		}
		cout << endl;
	}




	delete[] tempD;
	system("pause");
	return 0;
}