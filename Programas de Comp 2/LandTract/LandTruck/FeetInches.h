#ifndef FEETINCHES_H
#define FEETINCHES_H
#include <iostream>
using namespace std;
// The FeetInches class holds distances or measurements
	// expressed in feet and inches.
class FeetInches
{
private:
	int feet; // To hold a number of feet
	int inches; // To hold a number of inches
	void simplify(); // Defined in FeetInches.cpp
public:
	// Constructor
	FeetInches(int f = 0, int i = 0);
	FeetInches(const FeetInches&);
	~FeetInches();

	// Mutator functions
	FeetInches& setFeet(int f);
	FeetInches& setInches(int i);

	// Accessor functions
	int getFeet() const;
	int getInches() const;

	// Overloaded operator functions
	FeetInches operator + (const FeetInches&); // Overloaded +
	FeetInches operator - (const FeetInches&); // Overloaded −
	FeetInches operator = (const FeetInches&); // Overloaded =
	FeetInches operator * (const FeetInches&); // Overloaded *
	bool operator == (const FeetInches& right) const;
	bool operator > (const FeetInches& right) const;
	bool operator <(const FeetInches& right) const;

friend ostream& operator << (ostream& out, const FeetInches&); 
friend istream& operator >> (istream& in, FeetInches&);
};
#endif
