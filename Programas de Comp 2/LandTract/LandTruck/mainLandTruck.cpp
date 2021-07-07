#include "LandTract.h"
#include "FeetInches.h"
#include <iostream>

using namespace std;

int main()
{
	FeetInches test1(5, 3), test2(12, 2);
	LandTract land1(test1, test2), land2;

	cout << "The first land width and lenght is " << land1.getWidth() << " and " << land1.getLenght()<< "." << endl;
	cout << "Enter the second land's information:\n";
	cin >> land2;

	if (land1 == land2)
	{
		cout << "The land are equal in size.\n";
		cout << "Land 1:" << endl
			<< land1 << endl;
		cout << "Land 2:" << endl
			<< land2 << endl;
	}
	else if (land1 > land2)
	{
		cout << "The first land is bigger.\n";
		cout << "Land 1:" << endl
			<< land1 << endl;
		cout << "Land 2:" << endl
			<< land2 << endl;
	}
	else if (land1 < land2)
	{
		cout << "The second land is bigger.\n";
		cout << "Land 1:" << endl
			<< land1 << endl;
		cout << "Land 2:" << endl
			<< land2 << endl;
	}
		

	system("pause");
	return 0;
}