#pragma once
#include<string>
using namespace std;
class Student
{
private:
	string name;
	string id;
public:
	Student();
	~Student();
	Student(string n, string id);
	void setName(string n);
	void setId(string id);
	string getName() const;
	string getID() const;
	void askInfo();
	void display() const;
};

