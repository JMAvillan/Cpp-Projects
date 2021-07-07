#pragma once
#include "ThreeDimensional.h"
#include <iostream>
#include <string>
using namespace std;

class Tetrahedron: public ThreeDimensional
{
private:
	double edgeLength;
public:
	Tetrahedron(double eL=1.0, double v=0.1178, double sA=1.732, string name="Tetrahedron", string color="Orange");
	Tetrahedron(const Tetrahedron&);
	~Tetrahedron();
	void setValues(string name, string color);
	void setEdgeLength(double s);
	double getEdgeLength() const;
	void display() const;

	void calcVolume();
	void calcSurfaceArea();
};

