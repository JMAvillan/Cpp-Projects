#include <iostream>
using namespace std;

void displayBinary(int);
void displayOctal(int);

int main()
{
	displayBinary(100);
	cout << endl;
	//displayOctal(100);
	cout << endl;


	system("pause");
	return 0;
}


void displayBinary(int n)
{
	if (n > 0)
	{
		if (n / 2 > 0)
			displayBinary(n / 2);
		cout << n % 2;
	} // end if
} // end displayOctal

void displayOctal(int n)
{
	if (n > 0)
	{
		if (n / 8 > 0)
			displayOctal(n / 8);
		cout << n % 8;
	} // end if
} // end displayOctal