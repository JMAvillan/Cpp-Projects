#include "TwoDimensional.h"
#include <iostream>
using namespace std;


TwoDimensional::TwoDimensional(double a, string name, string color) : area(a), Shape(name, color) {}
TwoDimensional::TwoDimensional(const TwoDimensional& twoD) : area(twoD.area), Shape(twoD.getGeometricFigureName(), twoD.getColor()){}
TwoDimensional::~TwoDimensional() {}
void TwoDimensional::setArea(double a)
{
	this->area = a;
}
double TwoDimensional::getArea() const
{
	return this->area;
}
void TwoDimensional::calcArea()
{}

void TwoDimensional::displayArea() const
{
	cout << "Area: ";
	cout << this->area << " units squared";
}
