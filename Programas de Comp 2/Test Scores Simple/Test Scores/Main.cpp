#include <iostream>
#include "TestScores.h"
using namespace std;

int main ()
{
	double test1, test2, test3;
	TestScores student;
	cout << "This program will take 3 test scores to calculate\n"
		<< "the average.\n";
	cout << "Input first score: ";
	cin >> test1;
	cout << "Input second score: ";
	cin >> test2; 
	cout << "Input third score: ";
	cin >> test3;
student.setScores(test1, test2, test3);
student.getAverage();

TestScores student2(student);
student2.getAverage;



	system("pause");
	return 0;
}