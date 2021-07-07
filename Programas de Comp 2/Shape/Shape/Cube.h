#pragma once
#include "ThreeDimensional.h"
#include <string>

class Cube : public ThreeDimensional
{
private:
	double side;
public:
	Cube(double s=1.0, double v=1.0, double sA=6.0, string name="Cube", string color="Pink");
	Cube(const Cube&);
	~Cube();
	void setValues(string name, string color);
	void setSide(double s);
	double getSide() const;
	void display() const;

	void calcVolume();
	void calcSurfaceArea();

};

