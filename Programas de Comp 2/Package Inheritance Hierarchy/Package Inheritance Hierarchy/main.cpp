#include <iostream>
#include <string>
#include "BoundCheck.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"
#include "Package.h"
using namespace std;

int main()
{
	Package regularPackage("Ben Robinson","200 King Stephen of Hungary Way","New York","NY",10028);
	bool tryAgain = true;

	string name, address, city, state;
	int zipCode;
	double weight;
	cout << "Sender's information entered:\n";
	regularPackage.displaySender();
	cout << endl;
	cout << "Enter receiver information: \n";
	cout << "Enter name: ";
	getline(cin,name);
	cout << "Enter address: (Street address [enter] city [enter] state [enter] zipcode [enter]\n";
	getline(cin, address);
	getline(cin, city);
	getline(cin, state);
	cin >> zipCode;
	regularPackage.setValues(name, address, city, state, zipCode, 1);

	while (tryAgain)
	{
		cout << "Enter package weight: (ounces) ";
		cin >> weight;
		try
		{
			regularPackage.setWeight(weight);
			tryAgain = false;
		}
		catch (BoundCheck e)
		{
			cout << "Error: Negative input is invalid.\n"
				<< "Try Again\n";

		}
	}
	cout << endl;
	regularPackage.displayInfo();
	cout << endl;

	OvernightPackage overnight;
	overnight=regularPackage;
	overnight.displayInfo();
	cout << endl;

	TwoDayPackage twoDay;
	twoDay = regularPackage;
	cout <<"Change Sender's Information:\n";
	cout << "Enter new sender's information:\n";
	cout << "Enter name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter address: (Street address [enter] city [enter] state [enter] zipcode [enter]\n";
	getline(cin, address);
	getline(cin, city);
	getline(cin, state);
	cin >> zipCode;
	twoDay.setValues(name, address, city, state, zipCode, 0);
	cout << endl;
	twoDay.displayInfo();
	cout << endl;

	system("pause");
	return 0;
}