#pragma once
#include "Persona.h"
class Estudiante :
	public Persona
{
private:
	
public:
	Estudiante(const MyString& name, const MyInt& id, double grade);
	Estudiante(const Estudiante& unE);
	virtual ~Estudiante();
	Estudiante& operator =(const Estudiante& unE);
	double getGrade() const;
	void setGrade(double grade);
	virtual void print() const;
	virtual void read();
	virtual string tipo() const;

};

