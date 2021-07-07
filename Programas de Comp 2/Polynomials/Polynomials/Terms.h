#pragma once
class Terms
{
private:
	int coefficient, exponent;

public:
	Terms(int c = 1, int ex = 1);
	Terms(const Terms&);
	~Terms();

	Terms& setCoefficent(int c);
	Terms& setExponent(int ex);
	int getCoefficient() const;
	int getExponent() const;
	Terms& operator =(const Terms&);
};

