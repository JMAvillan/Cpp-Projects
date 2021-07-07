#include "coinToss.h"
#include <string>
#include <time.h>
using namespace std;

coinToss::coinToss()
{ // Get the system time.
	unsigned seed = time(0);

	// Seed the random number generator.
	srand(seed);

	toss();

}
void coinToss::toss()
{

	const int MIN_VALUE = 1; // Minimum die value
	const int MAX_VALUE = 2;
	int value;
	// Get a random value.
	value = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	switch (value)
	{
	case 1:
		sideUp = "Heads";
		break;
	case 2:
		sideUp = "Tails";
		break;
	}
}
string coinToss::getSideUp()
{
	return sideUp;
}
