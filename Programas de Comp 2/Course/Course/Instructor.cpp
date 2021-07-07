#include "Instructor.h"
Instructor::Instructor()
{
	this->set("", "", "");
}

// Constructor
Instructor::Instructor(string lname, string fname, string office)
{
	this->set(lname, fname, office);
}
Instructor::Instructor (const Instructor& anInst)
{
	this->set(anInst.getLastName(), anInst.getFirstName(), anInst.getOffice());
}
// set function
void Instructor::setInst(const Instructor& anInst)
{
	this->set(anInst.getLastName(), anInst.getFirstName(), anInst.getOffice());
}
void Instructor::set(string lname, string fname, string office)
{
	this->lastName = lname;
	this->firstName = fname;
	this->officeNumber = office;
}

string Instructor::getLastName()const
{
	return this->lastName;
}
string Instructor::getFirstName() const
{
	return this->firstName;
}
string Instructor::getOffice() const
{
	return this->officeNumber;
}
Instructor Instructor::getInfo() const
{
	this->getLastName();
	this->getFirstName();
	this->getOffice();
	return *this;
}

// print function
void Instructor::print() const
{
	cout << "Last name: " << lastName << endl;
	cout << "First name: " << firstName << endl;
	cout << "Office number: " << officeNumber << endl;
}