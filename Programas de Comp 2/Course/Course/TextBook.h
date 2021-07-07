#ifndef TEXTBOOK
#define TEXTBOOK
#include <iostream>
#include <string>
using namespace std;

// TextBook class
class TextBook
{
private:
	string title; // Book title
	string author; // Author name
	string publisher; // Publisher name
public:
	// The default constructor stores empty strings
	// in the string objects.
	TextBook();

	TextBook(string textTitle, string auth, string pub);
	TextBook(const TextBook&);
	// set function
	void set(string textTitle, string auth, string pub);
	void setText(const TextBook&);
	string getTitle()const;
	string getAuth()const;
	string getPub()const;
	TextBook getInfo() const;
	// print function
	void print() const;

};
#endif