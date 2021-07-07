#include "MyString.h"
#include <iostream>
using namespace std;

MyString::MyString(const char* str)
{
	int size = len(str);
	initS(size);

	for (int x = 0; x <= size; x++)
	{
		if (x != size)
			this->s[x] = str[x];
		else
			this->s[x] = NULL;
	}
}
MyString::MyString(char ch)
{
	int size = len(ch);
	initS(size);	//initiate string
	char* temp = &ch;
	for (int x = 0; x <= size; x++)
	{
		if (x != size)
			this->s[x] = temp[x];
		else
			this->s[x] = NULL;
	}

}
MyString::MyString(const MyString& aMyString)
{
	int size = aMyString.len();
	this->initS(size);	//initiate string
	
	for (int x = 0; x <= size; x++)
	{
		if (x != size)
			this->s[x] = aMyString.s[x];
		else
			this->s[x] = NULL;
	}
}
MyString::~MyString()
{	s = nullptr;
	delete[] this->s;
	
}

int MyString::len() const
{
	int count = 0;
	bool out = false;
	int x = 0;
	while (out == false)
	{

		if (this->s[x] == NULL)
			out = true;
		else
		{
			count++;
			x++;
		}
	}
	return count;
}
int MyString::len(const char* str) const
{
	int count = 0;
	bool out = false;
	int x = 0;
	while (out == false)
	{
		if (str[x] == NULL)
			out = true;
		else
		{
			count++;
			x++;
		}

	}
	return count;
}
int MyString::len(char ch) const
{
	char* temp = &ch;
	int count = 0;
	bool out = false;
	int x = 0;
	while (out == false)
	{
		if (temp[x] == NULL)
			out = true;
		else
		{
			count++;
			x++;
		}
	}
	return count;
}

void MyString::setS(const char* str)
{
	int size = len(str);
	if (this->len() != size)
	{
		delete[] this->s;
		initS(size);

		for (int x = 0; x <= size; x++)
		{
			if (x != size)
				this->s[x] = str[x];
			else
				this->s[x] = NULL;
		}
	}
	else
		for (int x = 0; x < size; x++)
		{
			this->s[x] = str[x];
		}
}

const char* MyString::getS() const
{
	return this->s;
}

MyString& MyString::operator = (const char* str)
{

	int strSize = len(str);
	if (this->len() != strSize)
	{
		delete[] this->s;
		initS(strSize);
		for (int x = 0; x <= strSize; x++)
		{
			if (x != strSize)
				this->s[x] = str[x];
			else
				this->s[x] = NULL;
		}
	}
	else
	{
		for (int x = 0; x < strSize; x++)
		{
			this->s[x] = str[x];
		}
	}
	return *this;
}
MyString& MyString::operator = (char ch)
{
	int chSize = len(ch);

	char* temp = &ch;
	if (this->len() != chSize)
	{
		delete[] this->s;
		initS(chSize);
		for (int x = 0; x <= chSize; x++)
		{
			if (x != chSize)
				this->s[x] = temp[x];
			else
				this->s[x] = NULL;
		}
	}
	else
	{
		for (int x = 0; x < chSize; x++)
		{
			this->s[x] = temp[x];
		}
	}
	return *this;
}

MyString& MyString:: operator = (const MyString& aMyString) {

	int stringSize = aMyString.len();

	if (this->len() != stringSize)
	{
		delete[] this->s;
		initS(stringSize);
		for (int x = 0; x <= stringSize; x++)
		{
			if (x != stringSize)
				this->s[x] = aMyString.s[x];
			else
				this->s[x] = NULL;
		}
	}
	else
		for (int x = 0; x < stringSize; x++)
			this->s[x] = aMyString.s[x];
	return *this;
}

MyString MyString::operator+ (const char* str) const
{
	MyString tempS;
	int size = this->len() + len(str);
	tempS.initS(size + 1);
	int x = 0;
	while (this->s[x] != NULL)
	{
		tempS.s[x] = this->s[x];
		x++;
	}
	tempS.s[x] = ' ';
	x++;
	int y = 0;
	while (str[y] != NULL)
	{
		tempS.s[x] = str[y];
		x++;
		y++;
	}
	tempS.s[x] = NULL;

	return tempS;
}
MyString MyString::operator + (char ch) const
{
	MyString tempS;
	char* tempCh;
	tempCh = &ch;
	int size = this->len() + len(ch);
	tempS.initS(size);
	int x = 0;
	while (this->s[x] != NULL)
	{
		tempS.s[x] = this->s[x];
		x++;
	}
	tempS.s[x] = ' ';
	x++;
	int y = 0;
	while (tempCh[y] != NULL)
	{
		tempS.s[x] = tempCh[y];
		x++;
		y++;
	}
	tempS.s[x] = NULL;

	return tempS;
}
MyString MyString::operator +(const MyString& aMyString) const
{

	MyString tempS;
	int size = this->len() + aMyString.len();
	tempS.initS(size + 1);

	int x = 0;
	while (this->s[x] != NULL)
	{
		tempS.s[x] = this->s[x];
		x++;
	}
	tempS.s[x] = ' ';
	x++;
	int y = 0;
	while (aMyString.s[y] != NULL)
	{
		tempS.s[x] = aMyString.s[y];
		x++;
		y++;
	}
	tempS.s[x] = NULL;
	return tempS;
}

MyString operator +(const char* str, const MyString& aMyString)
{
	MyString tempS;
	int size = aMyString.len() + aMyString.len(str);
	tempS.initS(size + 1);
	int x = 0;
	while (str[x] != NULL)
	{
		tempS.s[x] = str[x];
		x++;
	}
	tempS.s[x] = ' ';
	x++;
	int y = 0;
	while (aMyString.s[y] != NULL)
	{
		tempS.s[x] = aMyString.s[y];
		x++;
		y++;
	}
	tempS.s[x] = NULL;

	return tempS;
}
MyString operator +(char ch, const MyString& aMyString)
{
	char* tempCh = &ch;
	MyString tempS;
	int size = aMyString.len() + aMyString.len(ch);
	tempS.initS(size + 1);
	int x = 0;
	while (tempCh[x] != NULL)
	{
		tempS.s[x] = tempCh[x];
		x++;
	}
	tempS.s[x] = ' ';
	x++;
	int y = 0;
	while (aMyString.s[y] != NULL)
	{
		tempS.s[x] = aMyString.s[y];
		x++;
		y++;
	}
	tempS.s[x] = NULL;

	return tempS;
}

bool MyString::operator == (const char* str) const
{
	if (this->len() != len(str))
		return false;
	for (int x = 0; x < this->len(); x++)
		if (this->s[x] != str[x])
			return false;

	return true;
}
bool MyString::operator == (const MyString& aMyString) const
{
	if (this->len() != aMyString.len())
		return false;
	for (int x = 0; x < this->len(); x++)
		if (this->s[x] != aMyString.s[x])
			return false;

	return true;
}
bool  operator  == (const char* str, const MyString& aMyString)
{
	if (aMyString.len(str) != aMyString.len())
		return false;
	for (int x = 0; x < aMyString.len(); x++)
		if (str[x] != aMyString.s[x])
			return false;

	return true;
}
bool MyString::operator != (const char* str) const
{
	if (*this == str == false)
		return true;			//returns that the two strings aren't the same
	else
		return false;			//return that the two string are the same
}
bool MyString::operator != (const MyString& aMyString) const
{
	if (*this == aMyString == false)
		return true;			//returns that the two strings aren't the same
	else
		return false;			//return that the two string are the same
}
bool operator != (const char* str, const MyString& aMyString)
{
	if (str == aMyString == false)
		return true;			//returns that the two strings aren't the same
	else
		return false;			//return that the two string are the same
}

bool MyString::operator > (const char* str) const
{
	if (this->len() > len(str))
		return true;
	else
		return false;
}
bool MyString::operator > (const MyString& aMyString) const
{
	if (this->len() > aMyString.len())
		return true;
	else
		return false;
}
bool operator > (const char* str, const MyString& aMyString)
{
	if (aMyString.len(str) > aMyString.len())
		return true;
	else
		return false;
}

bool MyString::operator < (const char* str) const
{
	if (this->len() < len(str))
		return true;
	else
		return false;
}
bool MyString::operator < (const MyString& aMyString) const
{
	if (this->len() < aMyString.len())
		return true;
	else
		return false;
}
bool operator < (const char* str, const MyString& aMyString)
{
	if (aMyString.len(str) < aMyString.len())
		return true;
	else
		return false;
}

const  char& MyString::operator [] (int index) const // get a character
{
	return this->s[index];
}
char& MyString::operator [](int index)
{
	return this->s[index];
}

istream& operator >> (istream& in, MyString& aMyString) //verify how to make it accept whitespaces
{
	in.get(aMyString.s,81,'\n');	// istream get(char*s, streamsize n, char delim);
									//Extract character from stream and stores them in s
									//until n characters have been extracted or unitl delim is encountered
	return in; 
}
ostream& operator << (ostream& out, const MyString& aMyString)
{
	out << aMyString.s;
	return out;
}

MyString MyString::trimLeadingSpaces() const
{
	MyString tempS;
	tempS.initS(this->len());

	int x = 0;
	while (this->s[x] == ' ')
	{
		x++;
	}
	int y = 0;
	for (x; x < tempS.len(); x++)
	{
		tempS[y] = this->s[x];
		y++;
	}
	return tempS;
}
MyString MyString::trimEndingSpaces() const
{

	MyString tempS;
	tempS.initS(this->len());

	int x = this->len() - 1;
	while (this->s[x] == ' ')
	{
		x--;
	}
	for (int y = 0; y <= x; y++)
	{
		tempS[y] = this->s[y];
	}
	tempS[x + 1] = NULL;
	return tempS;
}
MyString MyString::trimAllSpaces() const
{
	MyString temp;
	temp = this->trimLeadingSpaces();
	temp = temp.trimEndingSpaces();
	temp.initS(this->len());
	int y = 0;
	for (int x = 0; x < temp.len(); x++)
	{
		while (this->s[x] == ' ')
		{
			x++;
		}
		temp[y] = this->s[x];
		y++;
	}
	temp[y + 1] = NULL;
	return temp;
}
MyString MyString::toUppercase() const
{
	MyString tempS(*this);


	for (int x = 0; x < len(s); x++)
	{
		if (this->s[x] == ' ')
			tempS[x] = this->s[x];
		else if (this->s[x] <= 'z' && this->s[x] >= 'a')
			tempS[x] = this->s[x] - 32;
		else
			tempS[x] = this->s[x];
	}
	return tempS;
}
MyString MyString::toLowercase() const
{
	MyString tempS(*this);


	for (int x = 0; x < len(s); x++)
	{
		if (this->s[x] == ' ')
			tempS[x] = this->s[x];
		else if (this->s[x] <= 'Z' && this->s[x] >= 'A')
			tempS[x] = this->s[x] + 32;
		else
			tempS[x] = this->s[x];
	}
	return tempS;
}

MyString MyString::createSubstring(int from, int to)const
{
	MyString tempS;
	tempS.initS((to - from) + 1);
	int x = 0;
	for (from; from <= to; from++)
	{
		tempS[x] = this->s[from];
		x++;
	}
	tempS[x] = NULL;
	return tempS;

}
MyString MyString::reverse() const
{
	MyString tempS(*this);
	int y = 0;
	for (int x = this->len()-1; x >= 0; x--)
	{
		tempS[y] = this->s[x];
		y++;
	}
	return tempS;
}
int MyString::indexOf(char ch)
{
	for (int x = 0; x <= this->len(); x++)
	{
		if (this->s[x] == ch)
			return x;
	}
	return NULL;
}

int MyString::indexOfLast(char ch)
{
	for (int x = this->len(); x >= 0; x--)
	{
		if (this->s[x] == ch)
			return x;
	}
	return NULL;
}
bool MyString::include(char ch)
{
	for (int x = 0; x <= this->len(); x++)
		if (this->s[x] == ch)
			return true;

	return false;
}

bool MyString::isEmpty()const
{
	return (this->len() == 0);
}

int MyString::frequency(char ch)
{
	int count = 0;
	for (int x = 0; x <= this->len(); x++)
	{
		if (this->s[x] == ch)
			count++;
	}
	return count;
}

bool MyString::representAnUnsingInteger() const
{
	bool represent = true;
	for (int i = 0; i < this->len() && represent; i++)
		if ((this->s)[i]< '0' || this->s[i]>'9')
			represent = false;

	return (represent && this->len() > 0);
}

bool MyString::representAnInteger() const
{
	MyString r(*this);
	if ((this->s)[0] == '+' || (this->s[0] == '-'))
		r = this->createSubstring(1, this->len() - 1);
	return (r.representAnUnsingInteger());
}

bool MyString::representAReal()
{
	int point = this->indexOf('.');
	MyString prefix, sufix;
	bool valid;

	if (point != -1)
	{
		prefix = this->createSubstring(0, point - 1);
		sufix = this->createSubstring(point + 1, this->len());
		valid = prefix.representAnInteger() && sufix.representAnUnsingInteger();
	}
	else
		valid = this->representAnInteger();
	return valid;
}

MyString& MyString::operator+=(const MyString& aMyString)
{
	return ((*this) = (*this) + aMyString);
}

MyString& MyString::operator+=(const char* s)
{
	return ((*this) = (*this) + s);
}
MyString& MyString::operator+=(char ch)
{
	return ((*this) = (*this) + ch);
}

MyString& MyString ::operator ++()		//++objeto
{
	return ((*this) = this->toUppercase());
}

MyString MyString::operator ++(int)	//objeto ++
{
	MyString r(*this);
	(*this) = this->toUppercase();
	return r;
}

MyString& MyString ::operator --()		//--objeto
{
	return ((*this) = this->toLowercase());
}
MyString MyString::operator --(int)		//objeto --
{
	MyString r(*this);
	(*this) = this->toLowercase();
	return r;
}