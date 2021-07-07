#include "FeetInches.h"
FeetInches::FeetInches(int f, int i)
{
	feet = f;
	inches = i;
	simplify();
}
// Mutator functions
void FeetInches::setFeet(int f)
{
	feet = f;
}
void FeetInches::setInches(int i)
{
	inches = i;
	simplify();
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
	temp.simplify();
	return temp;
}
FeetInches FeetInches::operator * (const FeetInches& right)
{
	(this->feet*12+this->inches)
}