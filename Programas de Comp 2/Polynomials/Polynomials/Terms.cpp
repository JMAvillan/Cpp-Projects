#include "Terms.h"

Terms::Terms(int c, int ex) : coefficient(c), exponent(ex) {}
Terms::Terms (const Terms& aTerm): coefficient(aTerm.getCoefficient()), exponent(aTerm.getExponent()) {}
Terms::~Terms() {}

Terms& Terms::setCoefficent(int c)
{
	this->coefficient = c;
}
Terms& Terms::setExponent( int ex)
{
	this->exponent = ex;
}
int Terms::getCoefficient() const
{
	return this->coefficient;
}
int Terms::getExponent() const
{
	return this->exponent;
}
Terms& Terms::operator =(const Terms& aTerm)
{
	this->setExponent(aTerm.getExponent());
	this->setCoefficent(aTerm.getCoefficient());
	return (*this);
}
