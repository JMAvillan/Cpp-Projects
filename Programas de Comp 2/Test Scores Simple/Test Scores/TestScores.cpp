#include "TestScores.h"
#include <iostream>
using namespace std;

TestScores::TestScores() {
	setScores(0, 0, 0);
}
//Copy Constructor
TestScores::TestScores(const TestScores& anTestScores)
{

}

void TestScores::setScores(double g1, double g2, double g3)
{
	grade1 = g1;
	grade2 = g2;
	grade3 = g3;
	
}
double TestScores::getScores(int x)
{
	switch(x)
	{
	case'0':
		return grade1;
	case'1':
		return grade2;
	case'2':
		return grade3;
	}
	
}

void TestScores::getAverage()
{
	double average;
	for (int x = 0; x < 3; x++)
	{
	average += getScores(x);
	if (x == 2)
		average / 3;
	}

	cout <<"The average score of the three tests is " << average << ".\n";
}
