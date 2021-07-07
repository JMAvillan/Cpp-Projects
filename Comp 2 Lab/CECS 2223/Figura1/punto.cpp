#include "punto.h"
#include <iostream>
using namespace std;

punto::punto(double x, double y)
{
	this->x=x;
	this->y=y;
}
punto::punto(const punto & unPunto)
{
	this->x = unPunto.x;
	this->y = unPunto.y;
}
punto::~punto()
{

}
void punto::pedirCoordenadas()
{
	this->pedirX();
	this->pedirY();
}
void punto::pedirX()
{
	double xValue;
	cout << "Indicar x: ";
	cin >> xValue ;
	cambiarX(xValue);
}
void punto::pedirY()
{
	double yValue;
	cout << "Indicar y: ";
	cin >> yValue;
	cambiarY(yValue);
}
void punto::cambiarX(double x)
{
	this->x = x;
}
void punto::cambiarY(double valueY)
{
	this->y = valueY;
}
double punto::obtenerX() const
{
	return this->x;
}
double punto::obtenerY() const
{
	return this->y;
}

void punto::mostrarCoordenadas()
{
	cout << "Coordenadas x=" << this->x << " y=" << this->y << endl;
}
void punto::mostrarInfo()
{
	this->mostrarCoordenadas();

	if (estaEnCuadrante1())
		cout << "Esta en cuadrante 1.\n";
	if (estaEnCuadrante2())
		cout << "Esta en cuadrante 2.\n";
	if (estaEnCuadrante3())
		cout << "Esta en cuadrante 3.\n";
	if (estaEnCuadrante4())
		cout << "Esta en cuadrante 4.\n";
}
bool punto::estaEnCuadrante1()
{
	if (this->x > 0 && this->y > 0)
		return true;
}
bool punto::estaEnCuadrante2()
{
	if (this->x < 0 && this->y > 0)
		return true;
}
bool punto::estaEnCuadrante3()
{
	if (this->x < 0 && this->y < 0)
		return true;
}
bool punto::estaEnCuadrante4()
{
	if (this->x > 0 && this->y < 0)
		return true;
}
punto punto::puntoMedio(const punto& unPunto)const
{
	punto midPoint;
	
	midPoint.cambiarX((this->x + unPunto.x) / 2);
	midPoint.cambiarY((this->y + unPunto.y) / 2);

	return midPoint;
}
double punto::calcDistancia(const punto& unPunto)const
{
	double distancia;
	double newX = unPunto.x;
	double newY= unPunto.y;
	return sqrt(pow(this->x - newX, 2) + pow(this->y -newY, 2));
}