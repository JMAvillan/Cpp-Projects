#include "NegativeWidth.h"
NegativeWidth::NegativeWidth(double v) :value(v) {}
void NegativeWidth::setValue(double v)
{
	this->value = v;
}
double NegativeWidth::getValue() const
{
	return this->value;
}