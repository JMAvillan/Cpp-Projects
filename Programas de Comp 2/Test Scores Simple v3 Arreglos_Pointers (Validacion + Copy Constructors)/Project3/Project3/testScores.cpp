#include "TestScores.h"
#include <iostream>
using namespace std;

TestScores::TestScores() {
	createTestScoresArray(DEFAULT_AMOUNT);
	
}


TestScores::TestScores(double g1, double g2, double g3)
{
	createTestScoresArray(DEFAULT_AMOUNT);
	for (int x=0; x < 3; x++)
	{
		switch (x)
		{
		case 0:
			setScores(g1, x);
			break;
		case 1:
			setScores(g2, x);
			break;
		case 2:
			setScores(g3, x);
			break;
		}
	}

}

//Copy Constructor
TestScores::TestScores(const TestScores& anTestScores)
{
	createTestScoresArray(DEFAULT_AMOUNT);
	for (int count = 0; count < 3; count++)
		setScores(anTestScores.getScores(count),count);
}

void TestScores::setScores(double test,int count)
{
		
	if (test < 0 || test > 100)
	{
		cout << "Invalid input";
		exit(EXIT_FAILURE);
	}
	else
		score[count] = test;
		
}
double TestScores::getScores(int x) const
{
		return score[x];
	
}

double TestScores::getAverage()
{
	double average = 0;
	for (int x = 0; x < 3; x++)
	{
		average += getScores(x);
		if (x == 2)
			return	average /= 3;
	}
}

void TestScores::display(int x)
{
	if (x==0)
	cout << "Summary of the test scores entered:\n";

		switch (x)
		{
		case 0:
			cout << "First Test: " << getScores(x) << endl;
			break;
		case 1:
			cout << "Second Test: " << getScores(x) << endl;
			break;
		case 2:
			cout << "Third Test: " << getScores(x) << endl;
			break;
		}
	if (x==2)
	cout << "The average score of the three tests is " << getAverage() << ".\n\n";
}