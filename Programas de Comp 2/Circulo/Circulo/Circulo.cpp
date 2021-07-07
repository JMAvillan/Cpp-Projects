#include "circle.h"
#include <iostream>
using namespace std;

//Constructor
circle::circle()
{
	radius = 1.0;
}
circle::circle(double r)
{
	setRadius(r);
}

circle::circle(const circle & anCircle)
{
	setRadius(anCircle.getRadius());
}

void circle::setRadius(double r)
{
	radius = r;
}

double circle::getRadius() const
{
	return radius;
}
double circle::getArea() const
{
	const double PI = 3.14159;
	return radius * radius * PI;
}
double circle::getCircumference() const
{
	const double PI = 3.14159;
	return radius * 2 * PI;
}

void circle::display() const
{
//Display circle data
	cout << "Here is the circle's data:\n";
	cout << "Radius: " << getRadius() << endl;
	cout << "Diameter: " << getRadius() * 2 << endl;
	cout << "Area: " << getArea() << endl;
	cout << "Circumference: " << getCircumference() << endl;
}