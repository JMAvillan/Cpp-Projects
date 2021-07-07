#include "Punto.h"
#include <iostream>
using namespace std;

void Punto::cambiarSimbolo(char simbolo)
{
	this->simbolo = simbolo;
}

char Punto::obtenerSimbolo() const
{
	return (this->simbolo);
}

void Punto::mostrarSimbolo() const
{
	cout << this->simbolo;
}

bool Punto::incluyeCoordenedas(double cx, double cy) const
{
	return (this->x == cx && this->y == cy);
}

Punto::Punto(double x, double y, char s)
{
	this->x = x;
	this->y = y;
	this->simbolo = s;
}
Punto::Punto(const Punto& unPunto)
{
	this->x = unPunto.x;
	this->y = unPunto.y;
	this->simbolo = unPunto.simbolo;
}
Punto::~Punto()
{

}
void Punto::pedirCoordenadas()
{
	this->pedirX();
	this->pedirY();
}
void Punto::pedirX()
{
	double xValue;
	cout << "Indicar x: ";
	cin >> xValue;
	cambiarX(xValue);
}
void Punto::pedirY()
{
	double yValue;
	cout << "Indicar y: ";
	cin >> yValue;
	cambiarY(yValue);
}
void Punto::cambiarX(double x)
{
	this->x = x;
}
void Punto::cambiarY(double valueY)
{
	this->y = valueY;
}
double Punto::obtenerX() const
{
	return this->x;
}
double Punto::obtenerY() const
{
	return this->y;
}

void Punto::mostrarCoordenadas() const
{
	cout << "Coordenadas x=" << this->x << " y=" << this->y << endl;
}
bool Punto::estaEnElOrigen() const
{
	return (this->x == 0 && this->y == 0);
}

bool Punto::estaEnElEjeDeX() const
{
	return (this->x != 0.0 && this->y == 0.0);
}

bool Punto::estaEnElEjeDeY() const
{
	return (this->x == 0.0 && this->y != 0.0);
}

bool Punto::estaEnElCuadranteI() const
{
	return (this->x > 0.0 && this->y > 0.0);
}
bool Punto::estaEnElCuadranteII() const
{
		return (this->x < 0.0 && this->y > 0.0);
}
bool Punto::estaEnElCuadranteIII() const
{
	return (this->x < 0.0 && this->y < 0.0);
}
bool Punto::estaEnElCuadranteIV() const
{
	return (this->x > 0.0 && this->y < 0.0);
}
Punto Punto::puntoMedio(const Punto& unPunto)const
{
	Punto midPoint;

	midPoint.cambiarX((this->x + unPunto.x) / 2);
	midPoint.cambiarY((this->y + unPunto.y) / 2);

	return midPoint;
}
double Punto::calcDistancia(const Punto& unPunto)const
{
	return (sqrt(pow(this->x - unPunto.x, 2.0))) + (pow(this->y - unPunto.y, 2.0));
}
Punto& Punto::operator=(const Punto& unPunto)
{
	this->x = unPunto.x;
	this->y = unPunto.y;
	this->simbolo = unPunto.simbolo;
}
void Punto::mostrarInfo() const
{
	this->mostrarCoordenadas();
	cout << endl << endl;
	if (estaEnElCuadranteI())
		cout << "Esta en cuadrante 1.\n";
	if (estaEnElCuadranteII())
		cout << "Esta en cuadrante 2.\n";
	if (estaEnElCuadranteIII())
		cout << "Esta en cuadrante 3.\n";
	if (estaEnElCuadranteIV())
		cout << "Esta en cuadrante 4.\n";
}