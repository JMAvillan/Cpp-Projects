#pragma once
#include "Shape.h"
#include <string>
class TwoDimensional : public Shape
{
private: 
	double area;
public:
	TwoDimensional(double a = 1.0,string name="", string color="");
	TwoDimensional(const TwoDimensional&);
	~TwoDimensional();
	void setArea(double a);
	double getArea() const;
	void calcArea();

	void displayArea() const;

};

