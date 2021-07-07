#pragma once
#include "Student.h"
#include "LinkedList.h"

class CourseReg
{
private:
	LinkedList<Student>* courseReg;
	int itemCount;
public:
	CourseReg();
	CourseReg(const CourseReg& aC);
	~CourseReg();
	int getItemCount()const;
	bool isEmpty();
	bool addStrt(const Student& aStd);
	bool addEnd(const Student& aStd);
	bool removeStrt();
	bool removeName(string name);
	void display() const;
};

