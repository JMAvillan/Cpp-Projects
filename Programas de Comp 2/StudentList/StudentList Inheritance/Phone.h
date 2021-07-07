#pragma once
#include <iostream>
#include "MyString.h"
using namespace std;

class Phone
{
public:
	Phone();
	Phone(const MyString&, const MyString&, const MyString&);
	Phone(const Phone&);
	~Phone();

	Phone& setAreaCode(const MyString&);
	Phone& setExchange(const MyString&);
	Phone& setLine(const MyString&);
	MyString& getAreaCode();
	MyString& getExchange();
	MyString& getLine();

	friend ostream& operator<<(ostream&, const Phone&);
	friend istream& operator>>(istream&, Phone&);
	Phone& operator =(const Phone&);
private:
	MyString areaCode; // 3-digit area code
	MyString exchange; // 3-digit exchange
	MyString line; // 4-digit line

}; // end class PhoneNumber