#include "Polynomial.h"

Polynomial::Polynomial(int size) : size(size) {
	initPoly();
	for (int x = 0; x < this->size; x++)
	{
		this->polyT[x].setCoefficent(1);
		this->polyT[x].setExponent(1);

	}
}
Polynomial::Polynomial(const Polynomial& aPoly) : size(aPoly.getSize()) {
	initPoly();
	for (int x = 0; x < this->size; x++)
	{
		this->polyT[x].setCoefficent(aPoly.polyT[x].getCoefficient());
		this->polyT[x].setExponent(aPoly.polyT[x].getExponent());
	}
}
Polynomial::~Polynomial()
{
	delete[] this->polyT;

}

Polynomial& Polynomial::setTerm(int c, int ex, int index)
{
	polyT[index].setCoefficent(c);
	polyT[index].setExponent(ex);
}
Polynomial& Polynomial::setTerm(const Terms& aTerm, int index)
{
	this->polyT[index] = aTerm;
	return *this;
}

Polynomial& Polynomial::setTerm(const Terms* aTerm)
{
	for (int x=0; x< this->size; x++)
	this->polyT[x] = aTerm[x];
	return *this;
}
Terms Polynomial::getTerms(int index)const
{
	return this->polyT[index];
}
int Polynomial::getCoefficient(int index) const
{
	return this->polyT[index].getCoefficient();
}
void Polynomial::sort()
{

}
void Polynomial::display(int index) const
{
	cout << this->polyT[index].getCoefficient() << "x^" << this->polyT[index].getExponent();
}

ostream& operator << (ostream& out, const Polynomial& aPoly)
{
	for (int x = 0; x < aPoly.getSize(); x++)
	{
		aPoly.display(x);
		if (aPoly.getCoefficient(x) > 0)
			cout << "+";
	}
	return out;
}
istream& operator >> (istream& out, Polynomial& aPoly)
{

}

Polynomial Polynomial::operator +(const Polynomial& aPoly)const
{
	int size = 5;
	Polynomial temp(size);
	int tempExpo, checkRepeatedExpo=0;
	bool out =false;
	int sumC=0;

	for (int x = 0; x < aPoly.getSize(); x++)
	{
		while (!(out))
		{
			if (x >= 1 && tempExpo == this->polyT[x].getExponent())
				x++;
			else
				out = true;
		}

		tempExpo = this->polyT[x].getExponent();
		for(int y=x+1; x< this->size; x++)
		{
			sumC += this->polyT[x].getCoefficient();

			if (tempExpo == this->polyT[y].getExponent())
			{
				sumC += this->polyT[y].getCoefficient();
			}

			temp.polyT->setTerm(sumC, tempExpo,x);
		
	}
}
Polynomial& Polynomial::operator =(const Polynomial&)
{

}
Polynomial& Polynomial::operator +=(const Polynomial&)
{

}
