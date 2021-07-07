#include "Date.h"
#include <string>
#include "Date.h"
using namespace std;

// initialize static member; one classwide copy
const int Date::days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

 // Date constructor
 Date::Date(int month, int day, int year)
	 {
		this->setMonth(month).setDay(day), setYear(year);
	} // end Date constructor
	// set month, day and year

 Date::Date(const Date& d)
 {
	 this->setMonth(d.getMonth()).setDay(d.getDay()).setYear(d.getYear());
 }

 Date&  Date::setDay(int dd)
 {
	 // test for a leap year
	 if ((month == 2 && leapYear(year) && dd >= 1 && dd <= 29) ||
		 (dd >= 1 && dd <= days[month]))
		this->day = dd;
	 else
		 throw invalid_argument("Day is out of range for current month and year");

	 return *this;
 }
 Date&  Date::setMonth(int mm)
 {
	 if (mm >= 1 && mm <= 12)
		this-> month = mm;
	 else
		 throw invalid_argument("Month must be 1-12");

	 return *this;
 }
 Date&  Date::setYear(int yy)
 {
	 if (yy >= 1900 && yy <= 2100)
		 this->year = yy;
	 else
		 throw invalid_argument("Year must be >= 1900 and <= 2100");

	 return *this;
 }
 int  Date::getDay()const
 {
	 return this->day;

 }
 int  Date::getYear() const
 {
	 return this->year;
 }
 int  Date::getMonth() const
 {
	 return this->month;
 }


 void Date::setDate(int mm, int dd, int yy)
	 {
	 (*this).setMonth(mm).setYear(yy).setDay(dd);
 }

 Date& Date::operator++()
 {
	 helpIncrement(); // increment date
	 return *this; // reference return to create an lvalue
 }		// end function operator++
		// overloaded postfix increment operator; note that the
		// dummy integer parameter does not have a parameter name

 Date Date::operator++(int s)
 {
	 Date temp = *this; // hold current state of object
	 helpIncrement();
						 // return unincremented, saved, temporary object
	 return temp;		 // value return; not a reference return
 }						// end function operator++
						// add specified number of days to date
 const Date& Date::operator+=(int additionalDays)
 {
	 for (int i = 0; i < additionalDays; ++i)
		 helpIncrement();
	 return *this; // enables cascading
 }
 // if the year is a leap year, return true; otherwise, return false
 bool Date::leapYear(int testYear)
	{
	if (testYear % 400 == 0 ||
	 (testYear % 100 != 0 && testYear % 4 == 0))
		return true; // a leap year
	 else
		 return false; // not a leap year
} // end function leapYear
 
 // determine whether the day is the last day of the month
 bool Date::endOfMonth(int testDay) const
 {
	 if (month == 2 && leapYear(year))
		 return testDay == 29; // last day of Feb. in leap year

	else
	 return testDay == days[month];
	
 } // end function endOfMonth

 // function to help increment the date
 void Date::helpIncrement()
 {
	// day is not end of month
	if (!endOfMonth(day))
		++day; // increment day
	else
		 if (month < 12) // day is end of month and month < 12
		{
			++month; // increment month
			day = 1; // first day of new month
	} // end if
	else // last day of year
	{
		++year; // increment year
	month = 1; // first month of new year
	day = 1; // first day of new month
	} // end else
 } // end function helpIncrement

	 // overloaded output operator
 ostream& operator<<(ostream& output, const Date& d)
 {
	 static string monthName[13] = { "", "January", "February",
	 "March", "April", "May", "June", "July", "August",
	"September", "October", "November", "December" };
	 output << monthName[d.month] << ' ' << d.day << ", " << d.year;
	 return output;
 }

istream& operator>>(istream& in, Date& d)
 {
	int dd, mm, yy;
	cout << "Enter day: ";
	cin >> dd;
	cout << "Enter month: ";
	cin >> mm;
	cout << "Enter year: ";
	cin >> yy;
	
	d.setDate(mm, dd, yy);
	return in;
 }


Date& Date::operator =(const Date& d) {
	this->setMonth(d.getMonth()). setDay(d.getDay()). setYear(d.getYear());
	return *this;
}