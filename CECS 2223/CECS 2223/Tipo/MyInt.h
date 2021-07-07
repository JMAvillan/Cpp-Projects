#pragma once
#include <iostream>
using namespace std;

class MyInt
{
private:
	int value;
public:

	void setValue(int);
	int getValue() const;
	MyInt(int v = 0);		//Constructor sustituto
	MyInt(const MyInt& anInteger);
	~MyInt();
		
	//Operator overloading
	MyInt& operator = (const MyInt&);		
	MyInt& operator = (int value);					//Para poder trabajar nuestra clase que imita int con  el int regular

	MyInt operator + (const MyInt&) const;
	MyInt operator + (int) const;
	friend MyInt operator + (int, const MyInt&);	

	MyInt operator - (const MyInt&);
	MyInt operator - (int) const;
	friend MyInt operator - (int, const MyInt&);

	MyInt operator * (const MyInt&);
	MyInt operator * (int) const;
	friend MyInt operator * (int, const MyInt&);

	MyInt operator / (const MyInt&);
	MyInt operator / (int) const;
	friend MyInt operator / (int, const MyInt&);

	MyInt operator % (const MyInt&);
	MyInt operator % (int) const;
	friend MyInt operator % (int, const MyInt&);

	bool operator == (const MyInt&)const;
	bool operator == (const int)const;
	friend bool operator == (int,const MyInt&);

	bool operator != (const MyInt&)const;
	bool operator != (const int) const;
	friend bool operator != (int,const MyInt&);

	bool operator < (const MyInt&)const;
	bool operator < (const int) const;
	friend bool operator < (int, const MyInt&);

	bool operator > (const MyInt&)const;
	bool operator > (const int)const;
	friend bool operator > (int,const MyInt&);

	bool operator <= (const MyInt&)const;
	bool operator <= (const int)const;
	friend bool operator <= (int, const MyInt&);

	bool operator >= (const MyInt&)const;
	bool operator >= (const int)const;
	friend bool operator >= (int, const MyInt&);

	MyInt& operator ++ ();
	MyInt& operator ++ (int);
	MyInt& operator -- ();
	MyInt& operator -- (int);

	MyInt& operator +=(const MyInt&);
	MyInt& operator +=(const int);
	MyInt& operator -=(const MyInt&);
	MyInt& operator -=(const int);

	MyInt& operator *=(const MyInt&);
	MyInt& operator *=(const int);
	MyInt& operator /=(const MyInt&);
	MyInt& operator /=(const int);

	MyInt& operator %=(const MyInt&);
	MyInt& operator %=(const int);

	friend ostream& operator << (ostream& out, const MyInt&);
	friend istream& operator >> (istream& in, const MyInt&);


};

