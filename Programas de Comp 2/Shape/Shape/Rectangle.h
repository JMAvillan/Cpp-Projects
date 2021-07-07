#pragma once
#include "TwoDimensional.h"
#include <iostream>
#include <string>
using namespace std;

class Rectangle :public TwoDimensional
{	private:
		double width;
		double length;
	public:
		Rectangle(double w=1.0, double l=1.0, double a=1.0, string name="Rectangle", string color="Red");
		Rectangle(const Rectangle&);
		Rectangle& setWidth(double);
		Rectangle& setLength(double);
		double getWidth() const;
		double getLength() const;

		double calcArea();

		void display() const;
};

