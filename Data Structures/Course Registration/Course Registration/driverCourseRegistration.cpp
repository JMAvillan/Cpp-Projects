/*
5. Write a program to manage a list of students waiting to register for a course as
described in Section 4.5. Operations should include adding a new student at the end of
the list, adding a new student at the beginning of the list, removing the student from
the beginning of the list, and removing a student by name.
*/
#include <iostream>
#include "CourseReg.h"
#include "Student.h"
#include <string>
using namespace std;
int main() {
	Student student[3];
	for (int i = 0; i < 3; i++)
		student[i].askInfo();
	for (int i = 0; i < 3; i++)
		student[i].display();

	cout << endl;
	CourseReg course;

	course.addStrt(student[0]);
	for (int i = 1; i < 3; i++)
		course.addEnd(student[i]);

	course.removeStrt();
	course.removeName("hiram");
	course.display();
	cout << endl;

	system("pause");
	return 0;
}