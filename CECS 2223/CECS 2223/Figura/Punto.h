#pragma once
#include <cmath>
#include<iostream>

class Punto
{
private:
	double x, y;
	char simbolo;
public:
	

	Punto(double x = 0.0, double y = 0.0, char s= '*'); //Constructor Sustituto
	Punto(const Punto& unPunto);	//Copy Construtor
	~Punto();
	void pedirCoordenadas();
	void pedirX();
	void pedirY();
	void cambiarX(double);
	void cambiarY(double);
	double obtenerX() const;
	double obtenerY() const;

	double calcDistancia(const Punto& unPunto)const;
	
	bool estaEnElOrigen() const;
	bool estaEnElEjeDeX() const;
	bool estaEnElEjeDeY() const;
	bool estaEnElCuadranteI() const;
	bool estaEnElCuadranteII() const;
	bool estaEnElCuadranteIII() const;
	bool estaEnElCuadranteIV() const;

	void mostrarCoordenadas() const;
	void mostrarInfo() const;
	void pedirCoordenadas();
	Punto puntoMedio(const Punto&)const;
	double calcDistancia(const Punto& unPunto)const;

	void cambiarSimbolo(char simbolo);
	char obtenerSimbolo() const;
	void mostrarSimbolo() const;
	bool incluyeCoordenedas(double cx, double cy) const;

	Punto& operator=(const Punto& unPunto);

};

