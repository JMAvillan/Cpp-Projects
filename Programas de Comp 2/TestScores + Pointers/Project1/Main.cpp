#include "TestScores.h"
#include <iostream>

using namespace std;

int main()
{
	TestScores student;
	cout << "This program will take 3 test scores to calculate\n"
		<< "the average.\n";
	student.setScores();
	student.getAverage();

	system("pause");
	return 0;
}