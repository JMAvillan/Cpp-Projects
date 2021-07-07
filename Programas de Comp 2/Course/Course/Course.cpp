#include "Course.h"
#include <iostream>
#include <string>
#include "Instructor.h"
#include "TextBook.h"

Course::Course()
{ // Assign the course name.
	this->courseName = "N/A";
// Assign the instructor.
this->instructor.set("N/A", "N/A", "N/A");

// Assign the textbook.
this->textbook.set("Default Title", "N/A", "N/A"); 
}

Course::Course(string course, string instrLastName,
	string instrFirstName, string instrOffice,
	string textTitle, string author,
	string publisher)
	{ // Assign the course name.
		this->setCourseName(course);

		// Assign the instructor.
		this->instructor.set(instrLastName, instrFirstName, instrOffice);

		// Assign the textbook.
		this->textbook.set(textTitle, author, publisher);

}
Course::Course(string course, Instructor anInst, TextBook anText)
{
	this->setCourseName(course);
	this->instructor.set(anInst.getLastName(), anInst.getFirstName(),anInst.getOffice());
	this->textbook.set(anText.getTitle(), anText.getAuth(), anText.getPub());
}
Course::Course(const Course& anCourse)
{
	this->setCourseName(anCourse.getCourseName());
	this->setInstructor(anCourse.getInstructor());
	//Tambien le puedes asignar los valores de la siguiente manera:
	/*this->instructor.set(anCourse.instructor.getLastName(), anCourse.instructor.getFirstName(),
	anCourse.instructor.getOffice());*/
	this->setTextBook(anCourse.getTextBook());
	//this->setTextBook(anCourse.textbook.getTitle(), anCourse.textbook.getAuth(), anCourse.textbook.getPub());
}

void Course::setCourseName(string n)
{
	this->courseName = n;
}
void  Course::setInstructor(string lastN, string firstN, string office)
{
	this->instructor.set(lastN, firstN, office);
}
void  Course::setInstructor(const Instructor& anInst)
{
	this->instructor.setInst(anInst);
}
void  Course::setTextBook(string title, string auth, string pub)
{
	this->textbook.set(title, auth, pub);
}
void Course::setTextBook(const TextBook& anText)
{
	this->textbook.setText(anText);
}
void  Course::setInfo(string course, string instrLastName,
	string instrFirstName, string instrOffice,
	string textTitle, string author,
	string publisher)
{
	this->setCourseName(course);

	// Assign the instructor.
	this->instructor.set(instrLastName, instrFirstName, instrOffice);

	// Assign the textbook.
	this->textbook.set(textTitle, author, publisher);
}
void  Course::setInfo(string course, Instructor anInst, TextBook anText)
{
	this->setCourseName(course);
	this->instructor.set(anInst.getLastName(), anInst.getFirstName(), anInst.getOffice());
	this->textbook.set(anText.getTitle(), anText.getAuth(), anText.getPub());
}

Instructor Course::getInstructor() const
{
	return instructor.getInfo();
}
TextBook Course::getTextBook()const
{
	return textbook.getInfo();
}
string Course::getCourseName() const
{
	return courseName;
}
void Course::print() const
{
	cout << "Course name: " << getCourseName() << endl << endl;
	cout << "Instructor Information:\n";
	instructor.print();
	cout << "\nTextbook Information:\n";
	textbook.print();
	cout << endl;
}