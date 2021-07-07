#include "Tetrahedron.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

Tetrahedron::Tetrahedron(double eL, double v, double sA, string name, string color) 
	: edgeLength(eL), ThreeDimensional(v, sA, name, color) {}
Tetrahedron::Tetrahedron(const Tetrahedron& aTetra)
	: edgeLength(aTetra.getEdgeLength()),
	ThreeDimensional(aTetra.getVolume(), aTetra.getSurfaceArea(), aTetra.getGeometricFigureName(), aTetra.getColor()) {}
Tetrahedron::~Tetrahedron() {}

void Tetrahedron::setValues(string name, string color)
{
	this->setGeometricFigureName(name);
	this->setColor(color);
}

void Tetrahedron::setEdgeLength(double eL) 
{
	this->edgeLength = eL;
}
double Tetrahedron::getEdgeLength() const
{
	return this->edgeLength;
}
void Tetrahedron::display() const
{
	cout << "Name: " << this->getGeometricFigureName() << endl;
	cout << "Color: " << this->getColor() << endl;
	cout << "Edge length: " << this->getEdgeLength() << endl;
	this->displayVolume(); cout << endl;
	this->displaySurfaceArea(); cout << endl;
}

void Tetrahedron::calcVolume()
{
	this->setVolume(pow(this->edgeLength,3)/(6*sqrt(2)));
}
void Tetrahedron::calcSurfaceArea()
{
	this->setSurfaceArea(sqrt(3) * pow(this->edgeLength, 2));
}