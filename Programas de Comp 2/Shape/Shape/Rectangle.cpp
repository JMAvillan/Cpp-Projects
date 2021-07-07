#include "Rectangle.h"
#include "TwoDimensional.h"
#include <iostream>
#include <string>
using namespace std;

Rectangle::Rectangle(double w, double l, double a, string name, string color) 
	: width(w), length(l), TwoDimensional(a, name, color) {}

Rectangle::Rectangle(const Rectangle& aRectangle) : 
	width(aRectangle.getWidth()), length(aRectangle.getLength()), 
	TwoDimensional(aRectangle.getArea(),aRectangle.getGeometricFigureName(), aRectangle.getColor()) {}


Rectangle& Rectangle::setWidth(double w)
{
	if (w >= 0)
		this->width = w;
	else {
		cout << "Invalid width\n";
		exit(EXIT_FAILURE);
	}
	return *this;
}

	Rectangle& Rectangle::setLength(double len)
	{
		if (len >= 0)
			this->length = len;
		else {
			cout << "Invalid length\n";
			exit(EXIT_FAILURE);
		}
		return *this;
	}

	double Rectangle::getWidth() const
		{
			return this->width;
		}

	double Rectangle::getLength() const
		{
			return this->length;
		}
		
	double Rectangle::calcArea()  
		{
			this->setArea(this->getWidth() * this->getLength());
			return this->getArea();
		}

	void Rectangle::display() const
	{
		cout << "Name: " << this->getGeometricFigureName() << endl;
		cout << "Color: " << this->getColor() << endl;
		cout << "Width: " << this->getWidth() << endl;
		cout << "Length: " << this->getLength() << endl;
		this->displayArea();
		cout << endl;
	}