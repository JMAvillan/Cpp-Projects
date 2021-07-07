#include "NegativeLength.h"
NegativeLength::NegativeLength(double v):value(v){}
void NegativeLength::setValue(double v)
{
	this->value = v;
}
double NegativeLength::getValue() const
{
	return this->value;
}