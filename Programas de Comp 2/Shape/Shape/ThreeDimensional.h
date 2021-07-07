#pragma once
#include "Shape.h"
#include <string>

class ThreeDimensional : public Shape
{
private:
	double volume, 
		surfaceArea;

public:
	ThreeDimensional(double v=1.0, double sA=1.0, string name="", string color="");
	ThreeDimensional(const ThreeDimensional&);
	~ThreeDimensional();

	ThreeDimensional& setVolume(double v);
	ThreeDimensional& setSurfaceArea(double sA);
	double getVolume() const;
	double getSurfaceArea() const;
	void displayVolume()const;
	void displaySurfaceArea() const;

	void calcVolume();
	void calcSurfaceArea();

};