#include "TestScores.h"
#include <iostream>
using namespace std;

TestScores::TestScores() {
	for (int count = 0; count < 3; count++)
	setScores(0, count);
}
//Copy Constructor
TestScores::TestScores(const TestScores& anTestScores)
{
	for (int count=0; count< 3; count++)
		setScores(anTestScores.getScores(count), count);
}

void TestScores::setScores(double grade, int count) 
{
	switch (count)
	{
	case 0:
		grade1 = grade;
	case 1:
		grade2 = grade;
	case 2:
		grade3 = grade;
	}
	
}
double TestScores::getScores(int x) const
{
	switch(x)
	{
	case 0:
		return grade1;
	case 1:
		return grade2;
	case 2:
		return grade3;
	}
	
}

void TestScores::getAverage() 
{

	for (int x = 0; x < 3; x++)
	{
	double average += getScores(x);
	if (x == 2)
		average / 3;
	}

	cout <<"The average score of the three tests is " << average << ".\n";
}
