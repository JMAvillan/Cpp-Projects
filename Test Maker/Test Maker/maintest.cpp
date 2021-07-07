#include <iostream>
#include "Generator.h"
#include "Exam.h"
#include "Questions.h"
#include "MyString.h"

int main()
{ 
	//Exam test;
	////cin >> test;
	//test.addNewQuestion();
	//cout << test;
	//test.deleteQuestion();

	Generator TestMaker;
	TestMaker.showMenu();
	cout << "Program closed successfully.\n";
	return 0;
}