#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle() {
	width = 1.0;
	length = 1.0;
}

Rectangle::Rectangle(double aWidth, double aLenght) {
	setWidth(aWidth);
	setLength(aLenght);
}

Rectangle::Rectangle(const Rectangle&anRectangle) 
{
		setWidth(anRectangle.getWidth());
		setLength(anRectangle.getLength());
}

void Rectangle::setWidth(double w) throw (NegativeWidth)
{
		if (w >= 0)
			width = w;
		else 
			NegativeWidth(w);
	
	}
//***************************************************
// setLength assigns a value to the length member. *
//***************************************************
void Rectangle::setLength(double len) throw (NegativeLength)
{
	if (len >= 0)
		length = len;
	else {
		NegativeLength(len);
	}
}
//***************************************************
// getWidth returns the value in the width member. *
//***************************************************
double Rectangle::getWidth() const
{
	return width;
}
//****************************************************
// getLength returns the value in the length member. *
//****************************************************
double Rectangle::getLength() const
{
	return length;
}
//******************************************************
// getArea returns the product of width times length. *
//******************************************************
double Rectangle::getArea() const
{
	return getWidth() * getLength();
}
//*****************************************************
// Function main *
//*****************************************************
double Rectangle::getPerimeter() const {
	return 2 * getWidth() + 2 * getLength();
}
void Rectangle::display() const
{
	cout << "Here is the rectangle's data:\n";
	cout << "Width: " << getWidth() << endl;
	cout << "Length: " << getLength() << endl;
	cout << "Area: " << getArea() << endl;
	cout << "Perimeter:" << getPerimeter() << endl;
}