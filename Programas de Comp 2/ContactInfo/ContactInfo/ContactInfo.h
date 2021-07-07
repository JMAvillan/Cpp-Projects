#pragma once
class ContactInfo
{
private: 
	char *name; // New contact name
	char *phone; //new phone number
public:
//Private member function initName
//this attribute initializes the name attribute

	void initName(char* n);
	void initPhone(char* p);
	ContactInfo(char* n, char* p);
	ContactInfo();
	~ContactInfo();
	const char* getName() const;
	const char* getPhoneNumber() const;
	void display();
};

