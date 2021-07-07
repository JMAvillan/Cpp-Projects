#include "TestScores.h"
#include "TestScores.h"
#include <iostream>
using namespace std;

TestScores::TestScores()
{
	double* ptrGrades = nullptr;
	ptrGrades = &grades;

	for (int count = 0; count < 3; count++)
		ptrGrades[count] = 0;
}

void TestScores::setScores()
{
	double* ptrGrades = nullptr;
	ptrGrades = &grades;

	for (int count = 0; count < 3; count++)
	{
		cout << "Input grade: ";
		cin >> ptrGrades[count];
	}

}
double TestScores::getScores(int c)
{
	double* ptrGrades = nullptr;
	ptrGrades = &grades;

	return ptrGrades[c];

}

void TestScores::getAverage()
{
	double average=0;
	for (int count = 0; count < 3; count++)
	{
		average += getScores(count);
		if (count == 2)
			average /= 3;
	}
	 cout << "The average score of the three tests is " << average<< ".\n";
}

