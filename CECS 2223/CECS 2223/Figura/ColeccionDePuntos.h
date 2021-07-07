#pragma once
#include "Punto.h"
class ColeccionDePuntos
{
private:
	Punto* punto;
	int cantidad;

public:
	ColeccionDePuntos();
	ColeccionDePuntos(const ColeccionDePuntos& unaColeccion);
	~ColeccionDePuntos();

	ColeccionDePuntos& operator=(const ColeccionDePuntos& unaColeccion);
	const Punto& operator [](int indice) const;
	Punto& operator [](int indice);
	ColeccionDePuntos& operator+(const ColeccionDePuntos& unaColeccion);

	int cantidadDePuntos() const;
	void vaciar();
	bool estaVacia();
	ColeccionDePuntos& operator +(const Punto& unPunto);
};