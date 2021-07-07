#pragma once
#include <iostream>
#include "EqualTo0.h"
using namespace std;

class Fraction
{
private:
	int num, dem;		//numerator and denominator

public:
	Fraction();
	Fraction(int, int);
	~Fraction();
	Fraction setNum(int);
	Fraction setDem(int)throw (EqualTo0);
	int getNum()const;
	int getDem() const;
	Fraction simplify();


	//overloading operators
	Fraction operator +(const Fraction&);
	Fraction operator -(const Fraction&);
	Fraction operator *(const Fraction&);
	Fraction operator / (const Fraction&);
	Fraction operator = (const Fraction&);

	bool operator != (const Fraction&);


	friend ostream& operator << (ostream& out, const Fraction&);
	friend istream& operator >>(istream& in, Fraction&);



};

