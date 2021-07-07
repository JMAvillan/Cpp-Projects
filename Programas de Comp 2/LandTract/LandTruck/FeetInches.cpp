#include "FeetInches.h"
#include <iostream>
using namespace std;

FeetInches::FeetInches(int f, int i)
{
	feet = f;
	inches = i;

}


FeetInches::FeetInches(const FeetInches& ftInch)
{
	feet = ftInch.getFeet();
	inches = ftInch.getInches();

}
FeetInches::~FeetInches()
{}

// Mutator functions
FeetInches& FeetInches::setFeet(int f)
{
	this->feet = f;
	return (*this);
}
FeetInches& FeetInches::setInches(int i)
{
	this->inches = i;
	return *this;
}
// Accessor functions
int FeetInches::getFeet() const
{
	return feet;
}
int FeetInches::getInches() const
{
	return inches;
}

void FeetInches::simplify()
{
	if (inches >= 12)
	{
		feet += (inches / 12);
		inches = inches % 12;
	}
	else if (inches < 0)
	{
		feet -= ((inches) / 12) + 1;
		inches = 12 - (inches) % 12;
	}
}
//**********************************************
// Overloaded binary + operator. *
//**********************************************
FeetInches FeetInches::operator + (const FeetInches& right)
{
	FeetInches temp;
	temp.inches = inches + right.inches;
	temp.feet = feet + right.feet;
	temp.simplify();
	return temp;
}
//**********************************************
// Overloaded binary − operator. *
//**********************************************
FeetInches FeetInches::operator - (const FeetInches& right)
{
	FeetInches temp;
	temp.inches = inches - right.inches;
	temp.feet = feet - right.feet;
	temp.simplify();
	return temp;
}
FeetInches FeetInches::operator = (const FeetInches& right)
{
	FeetInches temp;
	temp.inches = right.inches;
	temp.feet = right.feet;
	return temp;
}
FeetInches FeetInches::operator * (const FeetInches& right)
{
	FeetInches temp;
	temp.setInches((this->feet * 12 + this->inches) * (right.getFeet() * 12 + right.getInches()));

	return temp;
}
bool FeetInches::operator == (const FeetInches& right) const
{
	return (this->feet == right.getFeet() && this->inches == right.getInches());

}
bool FeetInches::operator > (const FeetInches& right) const
{
	return ((this->feet > right.getFeet() ||
		this->feet == right.getFeet() && this->inches > right.getInches()));
}
bool FeetInches::operator <(const FeetInches& right) const
{
	return (!(*this > right));
}
ostream& operator << (ostream& out, const FeetInches& right)
{
	out << right.getFeet() << "ft " << right.getInches() << "in";
	return out;
}
istream& operator >> (istream& in, FeetInches& right)
{
	int ft, inch;
	cout << "Enter feet: ";
	in >> ft;
	cout << "Enter Inches: ";
	in >> inch;
	right.setFeet(ft).setInches(inch);
	return in;
}