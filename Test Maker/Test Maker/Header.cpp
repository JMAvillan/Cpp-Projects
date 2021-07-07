#include "Header.h"
#include <iomanip>

Header::Header()
{
	MyDate tempDate(8, 1, 2019);
	MyTime tempTime(8, 0, 0);
	this->date = tempDate;
	this->time = tempTime;
}
Header::Header(MyDate aDate, MyTime aTime)
{
	this->date = aDate;
	this->time = aTime;
}
Header::Header(const Header& aHeader)
{
	this->date = aHeader.date;
	this->time = aHeader.time;
}

void Header::setDate(MyDate aDate)
{
	this->date = aDate;
}
void Header::setTime(MyTime aTime)
{
	this->time = aTime;
}

MyDate Header::getDate()const
{
	return this->date;
}
MyTime Header::getTime() const
{
return 	this->time;
}

void Header::askDate()
{
	cout << "Enter date:\n";
	cin >> date;
}
void Header::askTime()
{
	cout << "Enter Time:\n";
	cin >> time;
}
void Header::display()const
{
	int width = 20;
	cout << label[0] << "_____________________  " << label[1] << "_________________" << endl;
	cout << label[2] << date << setw(20) << label[3] << time << endl;
}

Header& Header::operator = (const Header& aHeader) {

	this->date = aHeader.date;
	this->time = aHeader.time;
	return *this;
}

ostream& operator << (ostream& out, const Header& aHeader)
{
	aHeader.display();
		return out;
}
 istream& operator >> (istream& in, Header& aHeader)
{
	 aHeader.askDate();
	 aHeader.askTime();
	 return in;
}