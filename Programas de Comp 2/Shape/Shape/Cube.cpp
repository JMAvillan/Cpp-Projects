#include "Cube.h"
#include <string>
#include <iostream>
using namespace std;

Cube::Cube(double s, double v, double sA, string name, string color) : side(s), ThreeDimensional(v, sA, name, color) {}
Cube::Cube(const Cube& aCube) 
	: side(aCube.getSide()), ThreeDimensional(aCube.getVolume(), aCube.getSurfaceArea(),
		aCube.getGeometricFigureName(), aCube.getColor()) {}
Cube::~Cube() {}

void Cube::setValues(string name, string color)
{
	this->setGeometricFigureName(name);
	this->setColor(color);
}

void Cube::setSide(double s)
{
	this->side = s;
}
double Cube::getSide() const
{
	return this->side;
}

void Cube::display() const
{
	cout << "Name: " << this->getGeometricFigureName() << endl;
	cout << "Color: " << this->getColor() << endl;
	cout << "Side length: " << this->side << endl;
	this->displayVolume(); cout << endl;
	this->displaySurfaceArea(); cout << endl;
}

void Cube::calcVolume() {
	this->setVolume(this->getSide() * this->getSide() * this->getSide());
}
void Cube::calcSurfaceArea() {
	this->setSurfaceArea(this->getSide()* this->getSide()* 6);
}