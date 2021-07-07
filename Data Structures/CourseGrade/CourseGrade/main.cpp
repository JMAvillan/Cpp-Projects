#include <iostream>
#include <string>
#include "StudentInfo.h"
#include "LinkedBag.h"
using namespace std;

int main()
{
	LinkedBag<StudentInfo> test;
	int quantityTests, quantityStd;
	cout << "How many students do you wish to enter?\n";
	cin >> quantityStd;
	cout << "How many tests were given?\n";
	cin >> quantityTests;


	StudentInfo* newStds = new StudentInfo[quantityStd];
	for (int x = 0; x < quantityStd; x++)
	{
		newStds[x].setTestScoreSize(quantityTests);

		cout << "Student " << x + 1 << ":\n";
		newStds[x].askInfo();
		test.addToEnd(newStds[x]);
	}
	delete[] newStds;

	cout << "Student List: \n";
	test.print();

	string getStudent;
	bool found = false;
	do {
		cout << "Search for a student by name: ";
		cin.ignore();
		getline(cin, getStudent);
		if (test.contains(getStudent))
		{
			cout << "Student found: " << test.grabInLink(getStudent) << endl;
			found = true;
		}
		else
			cout << "Student is not on the list.\n";
	} while (!found);
	
	system("pause");
	return 0;
}