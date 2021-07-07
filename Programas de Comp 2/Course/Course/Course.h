#ifndef COURSE
#define COURSE
 #include <iostream>
 #include <string>
 #include "Instructor.h"
#include "TextBook.h"
using namespace std;

class Course
 {
 private:
 string courseName; // Course name
 Instructor instructor; // Instructor
TextBook textbook; // Textbook
 public:
 // Constructor
	 Course();
	 Course(string course, string instrLastName,
		 string instrFirstName, string instrOffice,
		 string textTitle, string author,
		 string publisher);
	 Course(string, Instructor, TextBook);
	 Course(const Course&);
	void setCourseName(string);
	void setInstructor(const Instructor&);
	void setInstructor(string,string, string);
	void setTextBook(string,string, string);
	void setTextBook(const TextBook&);
	void setInfo(string course, string instrLastName,
		string instrFirstName, string instrOffice,
		string textTitle, string author,
		string publisher);
	void setInfo(string, Instructor, TextBook);
	string getCourseName() const;
	Instructor getInstructor() const;
	TextBook getTextBook()const;

 // print function
	 void print() const;
 };
#endif;

