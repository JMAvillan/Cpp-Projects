#include "ThreeDimensional.h"
#include <iostream>
using namespace std;

ThreeDimensional::ThreeDimensional(double v, double sA, string name, string color)
									: volume(v), surfaceArea(sA),	Shape(name, color) {}
ThreeDimensional::ThreeDimensional(const ThreeDimensional& threeD)
									: volume(threeD.getVolume()), surfaceArea(threeD.getSurfaceArea()),
									Shape(threeD.getGeometricFigureName(),threeD.getColor()) {}
ThreeDimensional::~ThreeDimensional() {}

ThreeDimensional& ThreeDimensional::setVolume(double v)
{
	this->volume = v;
	return *this;
}
ThreeDimensional& ThreeDimensional::setSurfaceArea(double sA)
{
	this->surfaceArea = sA;
	return (*this);
}
double ThreeDimensional::getVolume() const
{
	return this->volume;
}
double ThreeDimensional::getSurfaceArea() const
{
	return this->surfaceArea;
}


void ThreeDimensional::displayVolume()const
{
	cout << "Volume: ";
	cout << this->getVolume() << " cubic units";
}
void ThreeDimensional::displaySurfaceArea() const
{
	cout << "Surface Area: ";
	cout << this->getSurfaceArea() << " units squared";
}

void ThreeDimensional::calcVolume() {}
void ThreeDimensional::calcSurfaceArea() {}
