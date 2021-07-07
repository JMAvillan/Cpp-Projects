#include "Rectangle.h"
#include <iostream>

int main()
{
	double width;
	double length;
	bool tryAgain = true;
	Rectangle myRectangle;

	while (tryAgain)
	{cout << "Enter the rectangle's width: ";
	cin >> width;
	cout << "Enter the rectangle's length: ";
	cin >> length;
	
	// Store these values in the Rectangle object.
		try
		{
			myRectangle.setWidth(width);
			cout << "The area of the rectangle is "
				<< myRectangle.getArea() << endl;
			tryAgain = false;

		}
		catch (NegativeWidth e)
		{
			cout << "Error: " << e.getValue()
				<< " is an invalid value for the"
				<< " rectangle's width.\n";
		}
		try
		{
			myRectangle.setLength(length);
			cout << "The area of the rectangle is "
				<< myRectangle.getArea() << endl;
			tryAgain = false;
		}
		catch (NegativeLength e)
		{
			cout << "Error: " << e.getValue()
				<< " is an invalid value for the"
				<< " rectangle's length.\n";
		}
	}

	cout << "End of the program.\n";


	system("pause");
	return 0;
}