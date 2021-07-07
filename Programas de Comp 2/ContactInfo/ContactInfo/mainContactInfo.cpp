#include<iostream>
#include "ContactInfo.h"
using namespace std;

int main()
{
	const int size = 20;
	char* name = nullptr;
	char* phone = nullptr;
	name = new char[size];
	phone = new char[size];

	int sizeContacts;
	cout << "How many contacts would you like to enter?\n";
	cin >> sizeContacts;
	cin.ignore();

	//Create array size specied by user
	ContactInfo* contacts = nullptr;
	contacts = new ContactInfo[sizeContacts];

	for (int count = 0; count < sizeContacts; count++)
	{
		cout << "Enter Name: ";
		cin.getline(name, size);
		cout << "Enter Phone: ";
		cin.getline(phone, size);

		contacts[count].initName(name);
		contacts[count].initPhone(phone);
	}
		for (int count = 0; count < sizeContacts; count++)
		{
			if (count == 0)
			cout << "\tContacts\n";
			contacts[count].display();
		}
		delete[]name;
		name = nullptr;
		delete[] phone;
		phone = nullptr;
	system("pause");
	return 0;
}