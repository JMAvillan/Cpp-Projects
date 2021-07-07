#ifndef DIE_H
#define DIE_H
class Die
{
private:
	int sides; // number of sides
	int value;//number of values
public:
	Die(int = 6);	//Constructor
	void roll();	//Rolls the die
	int getSides();	//retunr the number is sides
	int getValue();	//returns the die's value
}
#endif