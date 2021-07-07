#pragma once
#include"MyString.h"
#include"MyDate.h"
#include"MyTime.h"
class Header
{
private:
	MyString label[4] = { "Name: ", "ID: ", "Date: ", "Time: " }; //labels
	MyDate date;
	MyTime time;

public:
	Header();
	Header(MyDate, MyTime);
	Header(const Header&);
	void setDate(MyDate);
	void setTime(MyTime);
	MyDate getDate()const;
	MyTime getTime() const;

	void askDate();
	void askTime();
	void display()const;

	Header& operator = (const Header&);
	friend ostream& operator << (ostream&, const Header&);
	friend istream& operator >> (istream&, Header&);

};

