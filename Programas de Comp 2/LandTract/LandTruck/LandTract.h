#pragma once
#include "FeetInches.h"
#include <iostream>
using namespace std;
class LandTract
{private: 
	FeetInches width, lenght;

public:
	LandTract(int ft1=0, int int1=0, int ft2=0, int in2=0);
	LandTract(FeetInches, FeetInches);
	LandTract(const LandTract&);
	~LandTract();

	LandTract& setWidth(int ft, int in);
	LandTract& setWidth(const FeetInches&);
	LandTract& setLenght(int ft, int in);
	LandTract& setLenght(const FeetInches&);
	const FeetInches& getWidth() const;
	const FeetInches& getLenght() const;

	FeetInches area();

	//overloading operators
	bool operator ==(const LandTract& aLand) const;
	bool operator >(const LandTract& aLand) const;
	bool operator <(const LandTract& aLand) const;
	friend ostream& operator << (ostream& out,  LandTract& aLand);
	friend istream& operator >> (istream& in, LandTract&);
};


