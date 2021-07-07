#include <iostream>
#include <iomanip>
using namespace std;
 template <class A>
 A valorAbsoluto(A value)
 {
	 if (value < 0)
		 return -1 * value;
		 return value;
 }

int main()
{
	int num=12, num2=-2;
	float realNum= 0.99, realNum2= -1.15;
	double bigRealNum= -89, bigRealNumber=78.99;

	cout << "List of  numbers in their absolute value: \n";
	cout << "Integers: \n";
	cout <<"1. "<< valorAbsoluto(num) << endl;
	cout <<"2. " << valorAbsoluto(num2) << endl;

	cout << "Floats: \n";
	cout << "1. " << valorAbsoluto(realNum) << endl;
	cout << "2. " << valorAbsoluto(realNum2) << endl;

	cout << "Doubles: \n";
	cout << "1. " << valorAbsoluto(bigRealNum) << endl;
	cout << "2. " << valorAbsoluto(bigRealNumber) << endl;

	system("pause");
	return 0;
}