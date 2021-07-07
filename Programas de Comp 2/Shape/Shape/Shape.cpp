#include "Shape.h"
#include <iostream>
#include <string>

using namespace std;

Shape::Shape(string geometricFigureName, string color) : geometricFigureName(geometricFigureName), color(color) {}

string Shape::getGeometricFigureName() const
{
	return this->geometricFigureName;
}
void Shape::setGeometricFigureName(string aGeometricFigureName)
{
	this->geometricFigureName = aGeometricFigureName;
}

string Shape::getColor() const
{
	return this->color;
}
void Shape::setColor(string aColor)
{
	this->color = color;
}