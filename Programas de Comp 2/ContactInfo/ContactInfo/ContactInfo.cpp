#include <cstring>
#include <iostream>
#include "ContactInfo.h"
using namespace std;


void ContactInfo::initName(char* n)
{
	name= new char[strlen(n) + 1];
	strcpy_s(name,strlen(n)+1, n);
}

//Private member function initPhone

void ContactInfo::initPhone(char *p)
{
	phone = new char[strlen(p) + 1];
	strcpy_s(phone, strlen(p)+1, p);
}

ContactInfo::ContactInfo()
{
	//Initialize the name attribution
	char temp1[] = "New Contact";
	initName(temp1);
	char temp2[] = "000-000-0000";
	initPhone(temp2);
}
ContactInfo::~ContactInfo()
{
	delete[] name;
	delete[] phone;
	name = nullptr;
	phone = nullptr;
}

void ContactInfo::display()
{
	cout << "Name: " << getName() << endl;
	cout << "Phone: " << getPhoneNumber() << endl;
}

//Getters
const char* ContactInfo::getName() const
{
	return name;
}

const char* ContactInfo::getPhoneNumber() const
{
	return phone;
}