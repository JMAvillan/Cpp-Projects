#include "Date.h"
#include "Phone.h"
#include "MyString.h"
#include "Student.h"
#include <iostream>
#include <iomanip>
using namespace std;

Student::Student()
{
	Date bday(1, 1, 1900);
	Phone p("123", "456", "6789");
	this->setFirstName("");
	this->setLastName("");
	this->setDate(bday);
	this->setPhone(p);
}
Student::Student(const MyString& name, const MyString& lName, const Date& bDay, const Phone& p) 
{
	this->setFirstName(name);
	this->setLastName(lName);
	this->setDate(bDay);
	this->setPhone(p);
}
Student::Student(const Student& aStd)
{
	this->setFirstName(aStd.getFirstName());
	this->setLastName(aStd.getLastName());
	this->setDate(aStd.getDate());
	this->setPhone(aStd.getPhone());
}
Student::~Student()
{
}
void Student::setValues(const MyString& name, const MyString& lName, const Date& bDay, const Phone& p)
{

	this->setFirstName(name).setLastName(lName).setDate(bDay).setPhone(p);
}

Student& Student::setFirstName(const MyString& name)
{
	this->firstName = name;
	return *this;
}
Student& Student::setLastName(const MyString& lName)
{
	this->lastName = lName;	
	return *this;
}
Student& Student::setPhone(const Phone& p)
{
	this->phone = p;
	return *this;
}
Student& Student::setDate(const Date& bDay)
{
	this->birthdate = bDay;
	return *this;
}

const MyString& Student::getFirstName() const {
return this->firstName;
}
const MyString& Student::getLastName() const
{
	return this->lastName;
}
const Date& Student::getDate() const
{
	return this->birthdate;
}
const Phone& Student::getPhone() const
{
	return this->phone;
}

ostream& operator << (ostream& out, const Student& std)
{
	cout << "Student information:" << endl;
	cout << "Name" << setw(40) << "Phone Number:" << setw(22) << "Birthday:\n";
	cout << std.getFirstName() << " " << std.getLastName() << setw(20) << std.getPhone() <<setw(20) << std.getDate();
	cout << endl << endl;
	return out;
}
istream& operator >> (istream& in, Student& std)
{
	MyString fN;
	MyString lN;
	Date b;
	Phone p;
	cout << "Enter first name: ";
	cin >> fN;
	cout << "Enter last name: ";
	cin >> lN;
	cout << "Enter birthday:\n";
	cin >> b;
	
	cout << "Phone number: (###) ###-####: ";
	cin.ignore();
	cin >> p;
	cout << endl;

	std.setValues(fN, lN, b, p);
	return in;
}