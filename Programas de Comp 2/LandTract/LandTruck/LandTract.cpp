#include "LandTract.h"
#include <iostream>
using namespace std;

LandTract::LandTract(int ft1, int in1, int ft2, int in2)
{
	this->setWidth(ft1, in1);
	this->setLenght(ft2, in2);
}

LandTract::LandTract(FeetInches w, FeetInches l)
{
	this->setWidth(w);
	this->setLenght(l);
}
LandTract::LandTract(const LandTract& aLand)
{
	this->setWidth(aLand.getWidth());
	this->setLenght(aLand.getLenght());
}
LandTract::~LandTract()
{}
LandTract& LandTract::setWidth(const FeetInches& feetInch)
{
	this->width.setFeet(feetInch.getFeet()).setInches(feetInch.getInches());
	return *this;
}
LandTract& LandTract::setWidth(int ft, int in)
{
	this->width.setFeet(ft).setInches(in);
	return *this;
}
LandTract& LandTract::setLenght(const FeetInches& feetInch)
{
	this->lenght.setFeet(feetInch.getFeet()).setInches(feetInch.getInches());
	return *this;
}
LandTract& LandTract::setLenght(int ft, int in)
{
	this->lenght.setFeet(ft).setInches(in);
	return *this;
}
const FeetInches& LandTract::getWidth() const
{
	return this->width;
}
const FeetInches& LandTract::getLenght() const
{
	return this->lenght;
}

FeetInches LandTract::area() 
{
	FeetInches temp(this->width * this->lenght);
	int tempInches = temp.getInches();
	temp.setFeet(tempInches / 144);
	temp.setInches( tempInches % 144);
	return temp;
}

bool LandTract::operator ==(const LandTract& aLand) const
{
	return (this->width == aLand.getWidth() && this->lenght == aLand.getLenght());
}
bool LandTract::operator >(const LandTract& aLand) const
{
	return (this->width > aLand.getWidth() || this->lenght > aLand.getLenght());
}
bool LandTract::operator <(const LandTract& aLand) const
{
	return (!(*this > aLand));
}

ostream& operator << (ostream& out, LandTract& aLand)
{
	FeetInches temp(aLand.area());
	out << "Width: " << aLand.getWidth() << endl;
	out << "Lenght: " << aLand.getLenght() << endl;
	cout << "Area: "  << temp.getFeet() << "ft^2 " << temp.getInches() << "in^2" << endl;

	return out;
}
istream& operator >> (istream& in, LandTract& aLand)
{
	FeetInches	w, l;
	cout << "Enter land width:\n";
	cin >> w;
	cout << "Enter land lenght: \n";
	cin >> l;

	aLand.setWidth(w).setLenght(l);
	return in;
}