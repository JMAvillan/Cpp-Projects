
#include <iomanip>
#include "Phone.h" 
using namespace std;

Phone::Phone()
{
	this->setAreaCode("123");
	this->setExchange("456");
	this->setLine("7890");
}
Phone::Phone(const MyString& a, const MyString& e,const MyString& l)

{
		this->setAreaCode(a);
		this->setExchange(e);
		this->setLine(l);
}
Phone::Phone(const Phone& phone)
{
	this->setAreaCode(phone.areaCode);
	this->setExchange(phone.exchange);
	this->setLine(phone.line);
}
Phone::~Phone()
{}

Phone& Phone::setAreaCode(const MyString& aP)
{
	this->areaCode=aP; 
	return *this;
}
Phone& Phone::setExchange(const MyString& aE)
{
	this->exchange=aE;
	return *this;
}
Phone& Phone::setLine(const MyString& aL)
{
	this->line = aL;
	return *this;
}
 MyString& Phone::getAreaCode()
{
	return this->areaCode;
}
 MyString& Phone::getExchange()
{
	return this->exchange;
}
 MyString& Phone::getLine()
{
	return this->line;
}

Phone& Phone::operator =(const Phone& phone)
{
	this->setAreaCode(phone.areaCode);
	this->setExchange(phone.exchange);
	this->setLine(phone.line);
	return *this;
}

ostream& operator<<(ostream& output, const Phone& number)
{
	output << "(" << number.areaCode << ") "
		<< number.exchange << "-" << number.line;
	return output; // enables cout << a << b << c;
}

istream& operator>>(istream& input, Phone& number)
{ 
	char ch;
	number.areaCode = "";
	number.exchange = "";
	number.line = "";
	input.ignore();
	 // skip (
	for (int x=0; x<3;x++)
	{input >> ch;
	number.areaCode += ch; // input area code
	}
	input.ignore(); // skip ) and space
	for (int x = 0; x < 3; x++)
	{
		input >> ch;
		number.exchange += ch;
	}// input exchange
	input.ignore(); // skip dash (-)
	for (int x = 0; x < 4; x++)
	{
		input >> ch;
		number.line += ch;
	}// input line

	return input; // enables cin >> a >> b >> c;
} // end function operator>>