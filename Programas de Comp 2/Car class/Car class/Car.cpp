#include "Car.h"
#include <iostream>


Car::Car()
{
	setYear(1980);
	char temp[]= " ";
	setMake(temp);
	setSpeed(0);
}
Car::Car(int y, char* m)
{
	setYear(y);
	setMake(m);
	setSpeed(0);
}
Car::~Car()
{
	delete[] make;
}
void Car::setYear(int y)
{
	yearModel = y;
}
void Car::setMake(char * m)
{ 
	make = new char[strlen(m) + 1];
	strcpy_s(make, strlen(m) + 1, m);
}
void Car::setSpeed(double s)
{
	speed = s;
}

int Car::getYear() const
{
return yearModel;
}

char* Car::getMake() 
{
	return make;
}

double Car::getSpeed() const
{
	return speed;
}

void Car::brake()
{
	speed -= 5;
}
void Car::accelerate()
{
	speed += 5;
}
