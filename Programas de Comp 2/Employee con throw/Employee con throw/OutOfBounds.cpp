#include "OutOfBounds.h"

OutOfBounds::OutOfBounds(int val)
{
	this->value = val;
}
int OutOfBounds::getValue() const
{
	return this->value;
}