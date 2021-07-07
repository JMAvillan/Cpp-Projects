#pragma once
#include "Date.h"
#include "Phone.h"
#include "MyString.h"
#include <iostream>
using namespace std;

class Student
{
	friend ostream& operator << (ostream& out, const Student&);
	friend istream& operator >> (istream& in, Student&);

private:
	MyString firstName;
	MyString lastName;
	MyString id;
	Date birthdate;
	Phone phone;

public:
	Student(const MyString&, const MyString&, const MyString&, const Date&, const Phone&);
	Student(const Student&);
	Student();
	~Student();

	void setValues(const MyString&, const MyString&,const MyString&, const Date&, const Phone&);
	Student& setFirstName(const MyString&);
	Student& setLastName(const MyString&);
	Student& setId(const MyString&);
	Student& setPhone(const Phone&);
	Student& setDate(const Date&);
	const MyString& getFirstName() const;
	const MyString& getLastName() const;
	const MyString& getId() const;
	const Date& getDate() const;
	const Phone& getPhone() const;

	Student& operator= (const Student&);
};

