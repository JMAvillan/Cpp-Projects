#pragma once
class Rectangulo
{
private:
	double base;
	double altura;

public:
	Rectangulo();
	~Rectangulo();
	void askInfo();
	double area() const;
	double perimeter() const;
	void display() const;

};

