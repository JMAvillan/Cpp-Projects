#include "Student.h"
#include<iostream>
#include<string>
using namespace std;


Student::Student()
{
	this->name = " ";
	this->id = "000000";
}


Student::~Student() {}
Student::Student(string n, string id) {
	this->name = n;
	this->id = id;
}
void Student::setName(string n) { this->name = n; }
void Student::setId(string id) { this->id = id; }
string Student::getName() const { return this->name; }
string Student::getID() const { return this->id; }
void Student::askInfo() {
	cout << "Enter student name: ";
	cin >> this->name;
	cout << "Enter student id: ";
	cin >> this->id;
}
void Student::display() const
{
	cout << "Student Name: " << this->name << endl;
	cout << "Student id: " << this->id << endl;
}