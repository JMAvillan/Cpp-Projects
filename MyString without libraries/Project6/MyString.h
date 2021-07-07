#pragma once
#include <iostream>
using namespace std;
const  int MAX_LEN = 80;

class MyString
{
private:
	char* s;
	void initS(int value)
	{
		this->s = new char[value + 1];
	}
public:
	MyString(const char* s = " ");
	MyString(char ch);
	MyString(const MyString& aMyString);
	~MyString();


	MyString& operator = (const char*);
	MyString& operator = (char);
	MyString& operator = (const MyString&);


	MyString operator +(const char*) const;
	MyString operator +(char) const;
	MyString operator +(const MyString&) const;

	friend MyString operator +(const char* s, const MyString& MyString);
	friend MyString operator +(char, const MyString&);

	bool operator == (const char*) const;
	bool operator == (const MyString&) const;
	friend bool operator  == (const char* s, const MyString&);

	bool operator != (const char*) const;
	bool operator != (const MyString&) const;
	friend bool operator != (const char* s, const MyString&);

	bool operator > (const char*) const;
	bool operator > (const MyString&)const;
	friend bool operator > (const char* s, const MyString&);

	bool operator < (const char*) const;
	bool operator < (const MyString&) const;
	friend bool operator < (const char*, const MyString&);

	const  char& operator [] (int index) const; // get a character
	char& operator [](int index);				// set character

	friend istream& operator >> (istream& in, MyString& aMyString);		//verify how to make it accept whitespaces
	friend ostream& operator << (ostream& out, const MyString& aMyString);

	MyString trimLeadingSpaces() const;
	MyString trimEndingSpaces() const;
	MyString trimAllSpaces() const;
	MyString toUppercase() const;
	MyString toLowercase() const;
	MyString createSubstring(int from, int to)const;

	MyString reverse() const;
	int indexOf(char ch);
	int indexOfLast(char ch);
	bool include(char ch);
	int frequency(char ch);

	bool isEmpty() const;

	bool representAnUnsingInteger() const;
	bool representAnInteger() const;
	bool representAReal();

	MyString& operator +=(const MyString& aMyString);
	MyString& operator +=(const char* s);
	MyString& operator +=(char ch);

	MyString& operator ++();//++objeto to uppercase
	MyString operator ++ (int);//objeto++ to uppercase 
	MyString& operator --(); // --objeto to lowercase
	MyString operator --(int);// objeto-- to lowercase
	const char* getS() const;
	void setS(const char*);


	int len() const;
	int len(char) const;
	int len(const char*) const;
};

