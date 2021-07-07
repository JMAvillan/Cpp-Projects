#ifndef SHAPE_H
#define SHAPE_H
#include<string>
using namespace::std;
class Shape
{
protected:
	string geometricFigureName;
	string color;
public:
	Shape(string geometricFigureName = "", string color = "");
	string getGeometricFigureName() const;
	void setGeometricFigureName(string aGeometricFigureName);
	string getColor() const;
	void setColor(string aColor);
};
#endif