#pragma once
#include "TwoDimensional.h"
#include <string>
class Triangle : public TwoDimensional
{
private:
	double base, height;
public:
	Triangle(double b=1.0, double h=1.0, double a=0.5, string name="Triangle", string color="Yellow");
	Triangle(const Triangle&);
	~Triangle();

	Triangle& setBase(double);
	Triangle& setHeight(double);

	double getBase() const;
	double getHeight() const;
	void display() const;

	double calcArea();

};

