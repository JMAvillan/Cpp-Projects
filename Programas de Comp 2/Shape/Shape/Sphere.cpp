#include "Sphere.h"
#include <iostream>
#include <string>
using namespace std;

Sphere::Sphere(double r, double v, double sA, string name, string color) : radius(r), ThreeDimensional(v, sA, name, color) {}
Sphere::Sphere(const Sphere& aSphere)
	: radius(aSphere.getRadius()), ThreeDimensional(aSphere.getVolume(), aSphere.getSurfaceArea(),
		aSphere.getGeometricFigureName(), aSphere.getColor()){}
Sphere::~Sphere() {}

void Sphere::setValues(string name, string color)
{
	this->setGeometricFigureName(name);
	this->setColor(color);
}

void Sphere::setRadius(double r)
{
	this->radius = r;
}

double Sphere::getRadius() const
{
	return this->radius;
}

double Sphere::calcVolume()
{
	double PI = 3.14159;
	this->setVolume((4 / 3) * PI * (this->getRadius()* this->getRadius()* this->getRadius()));
	return this->getVolume();
}
double Sphere::calcSurfaceArea()
{
	double PI = 3.14159;
	this->setSurfaceArea(2 * PI * this->radius * (this->radius * 2));
	return this->getSurfaceArea();
}


void Sphere::display() const
{
	cout << "Name: " << this->getGeometricFigureName() << endl;
	cout << "Color: " << this->getColor() << endl;
	cout << "Radius: " << this->getRadius() << endl;
	cout << "Diameter: " << this->getRadius() * 2 << endl;
	this->displayVolume(); cout << endl;
	this->displaySurfaceArea(); cout << endl;

}