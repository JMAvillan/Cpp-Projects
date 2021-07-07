// Fig. 11.6: Date.h
// Date class definition with overloaded increment operators.
#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream&, const Date&);
	friend istream& operator>>(istream&, Date&);
public:
	Date(int m = 1, int d = 1, int y = 1900); // default constructor
	Date(const Date&);
	void setDate(int, int, int); // set month, day, year
	Date& setDay(int);
	Date& setMonth(int);
	Date& setYear(int);
	int getDay()const;
	int getYear() const;
	int getMonth() const;

	Date& operator =(const Date&);
	const Date& operator+=(int); // add days, modify object
	static bool leapYear(int); // is date in a leap year?
	bool endOfMonth(int) const; // is date at the end of month?
	Date& operator++();
	Date operator++(int);

private:
	int month;
	int day;
	int year;
	static const int days[]; // array of days per month
	void helpIncrement(); // utility function for incrementing date



}; // end class Date

#endif

