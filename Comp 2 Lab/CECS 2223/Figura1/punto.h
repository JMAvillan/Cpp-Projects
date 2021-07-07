#pragma once
#include <cmath>
#include<iostream>

class punto
{
private:
	double x, y;
public:
	punto(double x=0.0, double y=0.0); //Constructor Sustituto
	punto(const punto&);	//Copy Construtor
	~punto();
	void pedirCoordenadas();
	void mostrarCoordenadas();
	void mostrarInfo();
	void pedirX();
	void pedirY();
	void cambiarX(double);
	void cambiarY(double);
	double obtenerX() const;
	double obtenerY() const;
	void calcCuadrante() const;
	bool estaEnCuadrante1();
	bool estaEnCuadrante2();
	bool estaEnCuadrante3();
	bool estaEnCuadrante4();
	
	punto puntoMedio(const punto &)const;
	double calcDistancia(const punto &)const;
};

