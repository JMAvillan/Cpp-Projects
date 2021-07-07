#include "Triangle.h"
#include <iostream>
#include <string>
using namespace std;

Triangle::Triangle(double b, double h, double a, string name, string color)
	: base(b), height(h), TwoDimensional(a, name, color) {
	this->calcArea();
}
Triangle::Triangle(const Triangle& aTriangle)
	: base(aTriangle.getBase()), height(aTriangle.getHeight()), 
	TwoDimensional(aTriangle.getArea(), aTriangle.getGeometricFigureName(), aTriangle.getColor()){}
Triangle::~Triangle() {}

Triangle& Triangle::setBase(double b)
{
	this->base = b;
	return *this;
}
Triangle& Triangle::setHeight(double h)
{
	this->height = h;
	return *this;
}

double Triangle::getBase() const
{
	return this->base;
}
double Triangle::getHeight() const
{
	return this->height;
}

double Triangle::calcArea()
{
	this->setArea(.5 * this->base * this->height);
	return this-> getArea();
}

void Triangle::display() const
{
	cout << "Name: " << this->getGeometricFigureName() << endl;
	cout << "Color: " << this->getColor() << endl;
	cout << "Height: " << this->getHeight() << endl;
	cout << "Base: " << this->getBase() << endl; 
	this->displayArea();
	cout << endl;
}

