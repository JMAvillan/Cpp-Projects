#pragma once
#include "TwoDimensional.h"
#include <string>
class Circle :
	public TwoDimensional
{
	private:
		double radius;
	public:
		Circle(double r=1.0, double a=3.14, string name="Circle", string color="Blue");
		Circle(const Circle&);
		void setRadius(double);
		double getRadius() const;
		double calcArea();

		void display() const;

};

