#pragma once
class Car
{
private:
	int yearModel;	//An int that holds the car’s year model.
		char* make;	//A string that holds the make of the car.
		double speed;	//An int that holds the car’s current speed.

public: 
	Car();
	Car(int, char*);
	~Car();
	void setYear(int);
	void setMake(char*);
	void setSpeed(double);
	double getSpeed() const;
	int getYear() const;
	char* getMake();
	void brake();
	void accelerate();




};

