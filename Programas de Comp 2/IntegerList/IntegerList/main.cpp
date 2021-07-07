#include<iostream>
#include <fstream>
using namespace::std;
#include "IntegerList.h"

int main()
{
const int SIZE = 5;
IntegerList numbers(SIZE);
int val, x;
// Store 9s in the list and display an asterisk
// each time a 9 is successfully stored.
for (x = 0; x < SIZE; x++)
{
cout << "Entre el valor:";
cin >> val;
numbers.setElement(x, val);
}
cout << endl;
numbers.sortList();
for (x = 0; x < SIZE; x++)
{
val = numbers.getElement(x);
cout << val << " ";
}
cout << endl;
system("pause");
return 0;
}
/*Entre el valor:28
Entre el valor:36
Entre el valor:2
Entre el valor:47
Entre el valor:36
2 28 36 36 47
Press any key to continue . . .*/