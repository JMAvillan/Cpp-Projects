#include <iostream>
#include "Rectangle.h"
int main()
{
	Rectangle box; // Define an instance of the Rectangle class
	double rectWidth; // Local variable for width
	double rectLength; // Local variable for length
	// Get the rectangle's width and length from the user.
	cout << "This program will calculate the area of a\n";
	cout << "rectangle. What is the width? ";
	cin >> rectWidth;
	cout << "What is the length? ";
	cin >> rectLength;
	// Store the width and length of the rectangle
	// in the box object.
	box.setWidth(rectWidth);
	box.setLength(rectLength);
	// Display the rectangle's data.
	box.display();

	Rectangle box2(3, 5);
	box2.display();

	Rectangle box3(box2);
	box3.display();

	system("pause");
	return 0;
}