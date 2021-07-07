#include <iostream>
#include "Fraction.h"
#include "EqualTo0.h"
using namespace std;

Fraction::Fraction()
{
	this->setNum(1);
	this->setDem(1);
}
Fraction::Fraction(int n, int d)
{
	this->setNum(n);
	this->setDem(d);
}
Fraction::~Fraction()
{

}
Fraction Fraction::setNum(int n)
{
	this->num = n;
	return *this;
}
Fraction Fraction::setDem(int d) throw (EqualTo0)
{
	if (d != 0)
	{
		this->dem = d;
		return *this;
	}
	else
		throw EqualTo0(d);
}
int Fraction::getNum()const
{
	return this->num;
}
int Fraction::getDem() const
{
	return this->dem;
}

Fraction Fraction::simplify()
{
	int x = this->num, y = this->dem, r;
	while (y != 0)
	{
		r = x % y;
		x = y;
		y = r;

	}
	this->num /= x;
	this->dem /= x;
	return *this;
}

//overloading operators

//sum of a fraction
Fraction Fraction::operator +(const Fraction& anFraction)
{
	Fraction tempF;

	tempF.setNum(this->num * anFraction.getDem() + this->dem * anFraction.getNum());
	tempF.setDem((this->dem * anFraction.getDem()));
	return tempF;
}

Fraction Fraction::operator -(const Fraction& anFraction)
{
	Fraction tempF;

	tempF.setNum(this->num * anFraction.getDem() - this->dem * anFraction.getNum());
	tempF.setDem((this->dem * anFraction.getDem()));
	return tempF;
}
Fraction Fraction::operator *(const Fraction& anFraction)
{
	Fraction tempF;

	tempF.setNum(this->num * anFraction.getNum());
	tempF.setDem((this->dem * anFraction.getDem()));
	return tempF;
}
Fraction Fraction::operator / (const Fraction& anFraction)
{
	Fraction tempF;

	tempF.setNum(this->num * anFraction.getDem());
	tempF.setDem((this->dem * anFraction.getNum()));
	return tempF;
}
Fraction Fraction::operator = (const Fraction& anFraction)
{
	this->setNum(anFraction.getNum());
	this->setDem(anFraction.getDem());
	return *this;
}

bool Fraction::operator != (const Fraction& anFraction)
{
	if (this->num != anFraction.getNum() && this->dem != anFraction.getDem())
		return true;
	else
		return false;
}

ostream& operator <<(ostream& out, const Fraction& anFraction)
{
	if (anFraction.getDem() == 1)
		out << anFraction.getNum();
	else
		out << anFraction.getNum() << "/" << anFraction.getDem();
	return out;
}
istream& operator >>(istream& in, Fraction& anFraction)
{
	int tempN, tempD;
	cout << "Enter numerator: ";
	cin >> tempN;
	anFraction.setNum(tempN);
	bool tryAgain = true;
	cout << "Enter denominator: ";
	cin >> tempD;
	anFraction.setDem(tempD);
	return in;
}

