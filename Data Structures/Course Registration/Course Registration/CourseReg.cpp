#include "CourseReg.h"
#include "Student.h"
#include <iostream>
using namespace std;

CourseReg::CourseReg()
{
	courseReg = new LinkedList<Student>();
}

CourseReg::CourseReg(const CourseReg& aC) :courseReg(aC.courseReg) {}
CourseReg::~CourseReg()
{
	delete courseReg;
	courseReg = nullptr;
}

bool CourseReg::isEmpty() { return courseReg->isEmpty(); }
bool CourseReg::addStrt(const Student& aStd) { 
	return courseReg->insert(1, aStd);
}
bool CourseReg::addEnd(const Student& aStd) { 
	return courseReg->insert(courseReg->getLength()+1, aStd); 
}
bool CourseReg::removeStrt() { return courseReg->remove(1); }
bool CourseReg::removeName(string name) {
	Student temp;

	for (int i = 1; i < courseReg->getLength(); i++) {
		temp = courseReg->getEntry(i);
		if (temp.getName() == name) {
			courseReg->remove(i);
			return true;
		}
	}
	return false;
}
void CourseReg::display() const {
	for (int i = 1; i <= courseReg->getLength(); i++) {
		Student temp = courseReg->getEntry(i);
		temp.display();
	}
}