#pragma once
#include "Terms.h"
#include <iostream>
using namespace std;
class Polynomial
{
private:
	int size;
	Terms *polyT;
	void initPoly()
	{
		this->polyT = new Terms[this->size];
	}
public:
	Polynomial(int size = 1);
	Polynomial(const Polynomial& aPoly);
	~Polynomial();

	Polynomial& setTerm(int c, int ex, int index);
	Polynomial& setTerm(const Terms& aTerm, int index);
	Polynomial& setTerm(const Terms* aTerm);
	Terms getTerms(int index)const;
	Polynomial& setSize(int);
	int getSize() const;
	int getCoefficient(int index) const;
	void sort();
	void display(int index) const;

	friend ostream& operator << (ostream& out, const Polynomial& aPoly);
	friend istream& operator >> (istream& out, Polynomial& aPoly);
	Polynomial operator +(const Polynomial& aPoly)const;
	Polynomial& operator =(const Polynomial&);
	Polynomial& operator +=(const Polynomial&);

};

