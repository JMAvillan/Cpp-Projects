#include <iostream>
#include "TestScores.h"
using namespace std;

int main()
{
	TestScores student;
	cout << "This program will take 3 test scores to calculate\n"
		<< "the average.\n";

	for (int testNum = 0; testNum < 3; testNum++)
	{
		double test;
		switch (testNum)
		{
		case 0:
			cout << "Input first score: ";
			break;
		case 1:
			cout << "Input second score: ";
			break;
		case 2:
			cout << "Input third score: ";
			break;
		}
		cin >> test;
		student.setScores(test, testNum);
	}

	cout << "Student 1: \n";
	student.display();

	cout << "Student 2: \n";
	TestScores student2(75, 80, 100);
	student2.display();

	cout << "Student 3 " << endl;
	TestScores student3(student);
	student3.display();



	system("pause");
	return 0;
}