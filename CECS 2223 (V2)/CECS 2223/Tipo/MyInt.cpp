#include "MyInt.h"

//Constructor sustituto
MyInt::MyInt(int v)
{
	this->value = v;
}

MyInt::MyInt(const MyInt& anInteger)	//Copy Constructor
{
	*this = anInteger;
}
MyInt::~MyInt()
{}

void MyInt::setValue(int v)
{
	this->value = v;
}

int MyInt::getValue() const
{
	return this->value;
}

//Operator Overloading
MyInt& MyInt::operator = (const MyInt& anInteger)
{
	this->value = anInteger.getValue();
	return *this;
}
MyInt& MyInt::operator = (int value)
{
	this->value = value;
	return *this;
}

MyInt MyInt::operator + (const MyInt& anInteger) const
{
	MyInt tempI = this->value + anInteger.value;
	return tempI;
}
MyInt MyInt::operator + (int v) const
{
	MyInt tempI = this->value + v;

	return  tempI;

}
MyInt operator + (int v, const MyInt& anInteger)
{
	MyInt temp(v);

	return temp + anInteger;

}

MyInt MyInt::operator - (const MyInt& anInteger)
{
	MyInt tempI = this->value - anInteger.value;
	return tempI;
}
MyInt MyInt::operator - (int v) const
{
	MyInt tempI = this->value - v;

	return  tempI;

}
MyInt operator- (int v, const MyInt& anInteger)
{
	MyInt temp(v);

	return temp - anInteger;

}

MyInt MyInt::operator * (const MyInt& anInteger)
{
	MyInt tempI = this->value * anInteger.value;
	return tempI;
}
MyInt MyInt::operator * (int v) const
{
	MyInt tempI = this->value * v;

	return  tempI;

}
MyInt operator* (int v, const MyInt& anInteger)
{
	MyInt temp(v);

	return temp * anInteger;

}

MyInt MyInt::operator / (const MyInt& anInteger)
{
	MyInt tempI = this->value / anInteger.value;
	return tempI;
}
MyInt MyInt::operator/ (int v) const
{
	MyInt tempI = this->value / v;

	return  tempI;

}
MyInt operator/ (int v, const MyInt& anInteger)
{
	MyInt temp(v);

	return temp / anInteger;
}

MyInt MyInt::operator% (const MyInt& anInteger)
{
	MyInt tempI = this->value % anInteger.value;
	return tempI;
}
MyInt MyInt::operator% (int v) const
{
	MyInt tempI = this->value % v;

	return  tempI;

}
MyInt operator% (int v, const MyInt& anInteger)
{
	MyInt temp(v);

	return temp % anInteger;
}