#include <iostream>
using namespace std;

int pow(int, int);
int main()
{
	cout << pow(7, 2) << endl;

	system("pause");
	return 0;
}

int pow(int base, int exp)
{

	if ( exp==0 )
		return 1;
	else
		return base * pow(base, exp-1);
}