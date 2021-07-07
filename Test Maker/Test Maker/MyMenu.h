#pragma once
#include <iostream>
using namespace std;

class MyMenu
{
private:


public:
	void display() const;
	void editExamDisplay() const;

	friend ostream& operator << (ostream&, const MyMenu&);
};

