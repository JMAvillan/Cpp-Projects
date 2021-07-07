#include "Date.h"
#include "Phone.h"
#include "MyString.h"
#include "Student.h"
#include <iostream>
#include <iomanip>
using namespace std;

Student::Student() :firstName("Juan"), lastName("Del pueblo"),
id("12345"), birthdate(), phone() {
}//end Student

Student::Student(const MyString& name, const MyString& lName, const MyString& tempId, const Date& bDay, const Phone& p) : firstName(name),
lastName(lName), id(tempId), birthdate(bDay), phone(p)
{
}//end Student
Student::Student(const Student& tempStudent) : firstName(tempStudent.firstName),
lastName(tempStudent.lastName), id(tempStudent.id), birthdate(tempStudent.birthdate),
phone(tempStudent.phone)
{
}//end Student

Student::~Student()
{
}
void Student::setValues(const MyString& name, const MyString& lName,const MyString& tempId, const Date& bDay, const Phone& p)
{

	this->setFirstName(name).setLastName(lName).setId(tempId).setDate(bDay).setPhone(p);
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

Student& Student::setId(const MyString& tempId)
{
	id = tempId;

	return *this;
}//set setId

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

const MyString& Student::getId() const
{
	return this->id;
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
	cout << std.getFirstName() << " " << std.getLastName() << setw(20) << std.getPhone() << setw(20) << std.getDate();
	cout << endl << endl;
	return out;
}
istream& operator >> (istream& in, Student& std)
{
	MyString fN;
	MyString lN;
	MyString tempId;
	Date b;
	Phone p;
	
	cout << "Enter first name: ";
	cin >> fN;
	cout << "Enter last name: ";
	cin >> lN;
	cout << "Enter ID: ";
	cin >> tempId;
	cout << "Enter birthday:\n";
	cin >> b;

	cout << "Phone number: (###) ###-####: ";
	cin.ignore();
	cin >> p;
	cout << endl;

	std.setValues(fN, lN, tempId, b, p);
	return in;
}

Student& Student::operator=(const Student& tempStudent) {
	this->firstName = tempStudent.getFirstName();
	this->lastName = tempStudent.getLastName();
	this->id = tempStudent.getId();
	this->birthdate = tempStudent.getDate();
	this->phone = tempStudent.getPhone();
	return *this;
}