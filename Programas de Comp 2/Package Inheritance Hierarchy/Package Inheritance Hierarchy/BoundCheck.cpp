#include "BoundCheck.h"
BoundCheck::BoundCheck(double v)
{
	this->value = 0;
}
void BoundCheck::setValue(int v)
{
	this->value = v;
}
int BoundCheck::getValue() const
{
	return this->value;
}