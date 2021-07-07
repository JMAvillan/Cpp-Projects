#include "ColeccionDePuntos.h"
#include "Punto.h"
ColeccionDePuntos::ColeccionDePuntos() {
	this->cantidad = 0;
	this->punto = NULL;
}
ColeccionDePuntos::ColeccionDePuntos(const ColeccionDePuntos& unaColeccion)
{
	this->punto=NULL;
	(*this) = unaColeccion;
}

ColeccionDePuntos::~ColeccionDePuntos()
{
	delete[] this->punto;
	
}

const Punto& ColeccionDePuntos::operator [](int indice) const
{
	return ((this->punto)[indice]);
}

Punto& ColeccionDePuntos::operator [](int indice) 
{
	return ((this->punto)[indice]);
}



ColeccionDePuntos& ColeccionDePuntos::operator=(const ColeccionDePuntos& unaColeccion)
{
	delete[] this->punto;
	if (unaColeccion.cantidad > 0)
	{
		this->punto = new Punto[unaColeccion.cantidad];
		for (int i = 0; i < unaColeccion.cantidad; i++)
			(*this)[i] = unaColeccion[i];
	}
	else
		this->punto = NULL;
	this->cantidad = unaColeccion.cantidad;
	return (*this);
}

int ColeccionDePuntos::cantidadDePuntos() const
{
	return (this->cantidad);
}

void ColeccionDePuntos::vaciar()
{
	delete[](this->punto);
	this->cantidad = 0;
	this->punto = NULL;
}

bool ColeccionDePuntos::estaVacia()
{
	return (this->cantidad == 0);
}
ColeccionDePuntos& ColeccionDePuntos::operator +(const Punto& unPunto)
{
	Punto* punto = new Punto[this->cantidad + 1];
	for (int i = 0; i < this->cantidad; i++)
		punto[i] = (*this)[i];

	punto[this->cantidad] = unPunto;
	delete[](this->punto);

	this->punto = punto;
	++(this->cantidad);
	return (*this);
}

