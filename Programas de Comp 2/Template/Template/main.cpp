#include <iostream>
#include <iomanip>
using namespace std;

// Example of Template definition for square function.					*
 /*template < class T>													*
 T square(T number)														*
 {																		*
 return number * number;												*
 }

int main()
{
	int userInt; // To hold integer input
	 double userDouble; // To hold double input
	 cout << setprecision(5);
	 cout << "Enter an integer and a floating-point value: ";
	 cin >> userInt >> userDouble;
	 cout << "Here are their squares: ";
	 cout << square(userInt) << " and "
	 << square(userDouble) << endl;
	 */

	 //Example of template class that return higher value

template <class T>
T highest(T value, T value2)
{
	if (value > value2)
		return value;
	return value2;
};
template <class L>
L lowest (L value, L value2)
{
	if (value < value2)
		return value;
	return value2;
}

int main()
{
	int num=12, num2=2;
	float realNum, realNum2;
	double bigRealNum=199.78, bigRealNum2 = 19.65;
	char character, char2;

	cout << "Data Type \"int\"" << endl;
	cout << "Show lowest: " << lowest(num, num2) << endl;
	cout << "Show highest: " << highest(num, num2) << endl;
	cout << endl;


	cout << "Data Type \"float\"" << endl;
	cout << "Input two real numbers separated by a space: ";
	cin >> realNum; cin >> realNum2;
	cout << "Show lowest: " << lowest(realNum, realNum2) << endl;
	cout << "Show highest: " << highest(realNum, realNum2) << endl;
	cout << endl;

	cout << "Data Type \"double\"" << endl;
	cout << "Show lowest: " <<  lowest(bigRealNum, bigRealNum2) << endl;
	cout << "Show highest: " << highest(bigRealNum, bigRealNum2) << endl;
	cout << endl;

	cout << "Data Type \"char\"" << endl;
	cout << "Input a letter: ";
	cin >> character;
	cout << "Input a second letter: ";
	cin >> char2;
	cout << "Show lowest: " << lowest(character, char2) << endl;
	cout << "Show highest: " << highest(character, char2) << endl;
	cout << endl;

	system("pause");
	return 0;
}