#ifndef RECTANGLE_H
#define RECTANGLE_H

// This program demonstrates a simple class.
#include <iostream>
#include "NegativeLength.h"
#include "NegativeWidth.h"

using namespace std;
// Rectangle class declaration.
class Rectangle
{
private:
	double width;
	double length;
public:
	Rectangle();
	Rectangle(double, double);
	Rectangle(const Rectangle&);
	void setWidth(double) throw (NegativeWidth);
	void setLength(double) throw (NegativeLength);
	double getWidth() const;
	double getLength() const;
	double getArea() const;
	double getPerimeter() const;
	void display() const;
};
#endif