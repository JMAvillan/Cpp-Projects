#include <iostream>
#include "TestScores.h"
using namespace std;

int main ()
{
	double test;
	TestScores student;
	cout << "This program will take 3 test scores to calculate\n"
		<< "the average.\n";

	for (int testNum = 0; testNum < 3; testNum++)
	{
		switch (testNum)
		{
		case '0':
			cout << "Input first score: ";
		case '1':
			cout << "Input second score: ";
		case'2':
			cout << "Input third score: ";
		}
		cin >> test;
		student.setScores(test,testNum);
	}

student.getAverage();

TestScores student2(student);
student2.getAverage;



	system("pause");
	return 0;
}