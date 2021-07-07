#include "Circle.h"
#include "Sphere.h"
#include "Rectangle.h"
#include "Cube.h"
#include "Triangle.h"
#include "Tetrahedron.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	Circle circ;
	Triangle tri;
	Rectangle rect;
	double tempInput, tempInput2;

	cout << "Enter the information for the following two dimensional figures.\n\n";
	cout << "Enter circles radius: ";
	cin >> tempInput;
	circ.setRadius(tempInput);
	circ.calcArea();
	cout << endl;

	cout << "Enter a rectangle's length and width: \n";
	cin >> tempInput; cin >> tempInput2;
	rect.setLength(tempInput).setWidth(tempInput2);
	rect.calcArea();
	cout << endl;

	cout << "Enter a triangle's base and height: \n";
	cin >> tempInput; cin >> tempInput2;
	tri.setBase(tempInput).setHeight(tempInput2);
	tri.calcArea();
	cout << endl;

	cout << "Here's the Two Dimensional Figures data\n\n";
	circ.display(); cout << endl;
	rect.display(); cout << endl;
	tri.display(); cout << endl;


	Sphere sph;
	Cube cb;
	Tetrahedron tetra;

	cout << "Enter the information for the following three dimensional figures.\n\n";
	cout << "Enter sphere's radius: ";
	cin >> tempInput;
	sph.setRadius(tempInput);
	sph.calcSurfaceArea();
	sph.calcVolume();
	cout << endl;

	cout << "Enter one side of the cube: ";
	cin >> tempInput;
	cb.setSide(tempInput);
	cb.calcSurfaceArea();
	cb.calcVolume();
	cout << endl;

	cout << "Enter an edge ledge of a tetrahedron: ";
	cin >> tempInput;
	tetra.setEdgeLength(tempInput);
	tetra.calcSurfaceArea();
	tetra.calcVolume();
	cout << endl;

	cout << "Here's the Three Dimensional Figures data\n\n";
	sph.display(); cout << endl;
	cb.display(); cout << endl;
	tetra.display(); cout << endl;



	system("pause");
	return 0;
}