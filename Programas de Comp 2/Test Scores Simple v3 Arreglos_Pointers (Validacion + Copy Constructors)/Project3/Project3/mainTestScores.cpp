#include <iostream>
#include "TestScores.h"
using namespace std;

int main()
{
	const int TEST_AMOUNT = 3;
	TestScores student;
	cout << "This program will take 3 test scores to calculate\n"
		<< "the average.\n";

	//Loop array to call function that sets the three tests scores
	for (int testNum = 0; testNum < TEST_AMOUNT; testNum++)
	{
		double test;
		switch (testNum)
		{
		case 0:
			cout << "Input first score: ";
			cin >> test;
			break;
		case 1:
			cout << "Input second score: ";
			cin >> test;
			break;
		case 2:
			cout << "Input third score: ";
			cin >> test;
			break;
		}
		student.setScores(test,testNum);
	}
	//Loop array to call function that displays the information
	cout << "Student 1: \n";
	for (int testNum = 0; testNum < 3; testNum++)
	{
		student.display(testNum);
	}

	cout << "Student 2: \n";
	TestScores student2(100,90,80);
	for (int testNum = 0; testNum < 3; testNum++)
	{
		student2.display(testNum);
	}

	cout << "Student 3 " << endl;
	TestScores student3(student);
	for (int testNum = 0; testNum < 3; testNum++)
	{
		student3.display(testNum);
	}


	system("pause");
	return 0;
}