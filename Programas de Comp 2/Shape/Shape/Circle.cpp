#include "Circle.h"
#include <iostream>
#include <string>
using namespace std;

Circle::Circle(double r, double a, string name, string color)
	: radius(1.0), TwoDimensional(a, name, color) {}
Circle::Circle(const Circle& aCircle) 
	: radius(aCircle.getRadius()), TwoDimensional(aCircle.getArea(),aCircle.getGeometricFigureName(),aCircle.getColor()) {}

void Circle::setRadius(double r)
{
	this->radius = r;
}

double Circle::getRadius() const
{
	return this->radius;
}
double Circle::calcArea()
{
	const double PI = 3.14159;
	this->setArea(this->radius * this->radius * PI);
	return this -> getArea();
}

void Circle::display() const
{
	cout << "Name: " << this->getGeometricFigureName() << endl;
	cout << "Color: " << this->getColor() << endl;
	cout << "Radius: " << this->getRadius() << endl;
	cout << "Diameter: " << this->getRadius() * 2 << endl;
	this->displayArea();
	cout << endl;
}