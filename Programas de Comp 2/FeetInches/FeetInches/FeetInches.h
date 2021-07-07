#ifndef FEETINCHES_H
#define FEETINCHES_H
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
	// Mutator functions
	void setFeet(int f);
	void setInches(int i);

	// Accessor functions
	int getFeet() const;
	int getInches() const;

	// Overloaded operator functions
	FeetInches operator + (const FeetInches&); // Overloaded +
	FeetInches operator - (const FeetInches&); // Overloaded −
	FeetInches operator = (const FeetInches&); // Overloaded =
	FeetInches operator * (const FeetInches&); // Overloaded *
};
#endif
