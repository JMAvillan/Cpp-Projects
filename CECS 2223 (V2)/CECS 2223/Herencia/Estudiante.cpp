#include "Estudiante.h"

Estudiante::Estudiante(const MyString& name, const MyInt& id, double grade) : Persona(name)
{

}
Estudiante::Estudiante(const Estudiante& unE);
virtual Estudiante::~Estudiante();
Estudiante& Estudiante::operator =(const Estudiante& unE);
double Estudiante::getGrade() const;
void Estudiante::setGrade(double grade);
virtual void Estudiante::print() const;
virtual void Estudiante::read();
virtual void Estudiante::tipo();
