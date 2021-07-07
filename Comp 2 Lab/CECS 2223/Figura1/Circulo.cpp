#include "Circulo.h"
#include <iostream>
using namespace std;
const double PI = 3.14;
//Overloading Operators
ostream& operator << (ostream& out, Circulo& unCirculo)
{
	unCirculo.display();
	return (out);
}

istream& operator << (istream& in, Circulo& unCirculo)
{
	unCirculo.askRadius();
	return (in);
}


Circulo::Circulo()
{
	this->setRadius(1.0);
}
Circulo::Circulo(double r)
{
	this->setRadius(r);
}
double Circulo::area() const
{
	return this->getRadius() * this->getRadius() * PI;
}
double Circulo::circumference() const {
	return 2.0 * PI * this->getRadius();
}
void  Circulo::askRadius()
{
	double r;
	cout << "Input circle radius: \n";
	cin >> r;
	this->setRadius(r);
}
void Circulo::setRadius(double r)
{cout << "Enter radius: ";
	this->radius = r;
}
double  Circulo::getRadius() const
{
	return this->radius;
}

void Circulo::display() const
{
	cout << "\tCircle info: \n";
	cout << "Radius: " << this->getRadius() << endl;
	cout << "Area: " << this->area() << endl;
	cout <<"Circumference: " << this->circumference() << endl;

}
Circulo::~Circulo() {

}