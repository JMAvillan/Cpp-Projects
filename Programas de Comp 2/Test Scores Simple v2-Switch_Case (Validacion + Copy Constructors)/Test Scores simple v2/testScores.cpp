#include "TestScores.h"
#include <iostream>
using namespace std;

TestScores::TestScores() {
	grade1 = 0;
	grade2 = 0;
	grade3 = 0;
}

TestScores::TestScores(double grade1, double grade2, double grade3)
{
	setScores(grade1, 0);
	setScores(grade2, 1);
	setScores(grade3, 2);

}

//Copy Constructor
TestScores::TestScores(const TestScores& anTestScores)
{
	for (int count = 0; count < 3; count++)
		setScores(anTestScores.getScores(count), count);
}

void TestScores::setScores(double grade, int count)
{
	switch (count)
	{
	case 0:
		if (grade < 0 || grade > 100)
		{
			cout << "Invalid input";
			exit(EXIT_FAILURE);
		}
		else
		grade1 = grade;
		break;
	case 1:
	if	(grade < 0 || grade > 100)
	{
		cout << "Invalid input";
		exit(EXIT_FAILURE);
	}
	else
		grade2 = grade;
		break;
	case 2:
		if (grade < 0 || grade > 100)
		{
			cout << "Invalid input";
			exit(EXIT_FAILURE);
		}
		else
		grade3 = grade;
		break;
	}

}
double TestScores::getScores(int x) const
{
	switch (x)
	{
	case 0:
		return grade1;
		break;
	case 1:
		return grade2;
		break;
	case 2:
		return grade3;
		break;
	}
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

void TestScores::display()
{
	cout << "Summary of the test scores entered:\n";

	for (int x = 0; x < 3; x++)
	{
		switch (x)
		{
		case 0:
			cout << "First Test: " << getScores(x) << endl;
			break;
		case 1:
			cout << "Second Test: " << getScores(x)<< endl;
			break;
		case 2:
			cout << "Third Test: " << getScores(x)<< endl;
			break;
		}
		}
	cout << "The average score of the three tests is " << getAverage() << ".\n\n";
}