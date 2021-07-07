#include "TextBook.h"
TextBook::TextBook()
{
	set("", "", "");
}

// Constructor
TextBook::TextBook (string textTitle, string auth, string pub)
{
	set(textTitle, auth, pub);
}
TextBook::TextBook(const TextBook& anTextBook)
{
	this->set(anTextBook.getTitle(), anTextBook.getAuth(), anTextBook.getPub());
}
// set function
void TextBook::set(string textTitle, string auth, string pub)
{
	this->title = textTitle;
	this->author = auth;
	this->publisher = pub;
}
void TextBook::setText(const TextBook& anTextBook)
{
	this->set(anTextBook.getTitle(), anTextBook.getAuth(), anTextBook.getPub());
}

string TextBook::getTitle() const
{
	return this->title;
}
string TextBook::getAuth() const
{
	return this->author;

}
string TextBook::getPub() const
{
	return this->publisher;
}
TextBook TextBook::getInfo() const
{
	this->getTitle();
	this->getAuth();
	this->getPub();
	return *this;
}
// print function
void TextBook::print() const
{
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "Publisher: " << publisher << endl;
}