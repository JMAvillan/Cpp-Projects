#pragma once
#include "ThreeDimensional.h"
#include <string>
class Sphere : public ThreeDimensional
{
private:
	double radius;
public:
	Sphere(double r=1.0, double v=4.188, double sA=12.56, string name="Sphere", string color="Purple");
	Sphere(const Sphere& aSphere);
	~Sphere();
	void setValues(string name, string color);
	void setRadius(double);
	double getRadius() const;

	double calcVolume();
	double calcSurfaceArea();

	void display() const;


};

