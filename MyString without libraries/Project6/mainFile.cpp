#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
	//MyString test("HOLA HAHAH ho ho"), test2(test), test3,test4;
	/*cin >> test4;
	cout << test4;
	test3 = test.reverse();
	cout << "test->" << test << endl;
	cout << "test3->" << test3 << endl;
	cout << test.frequency('H') << endl;*/
	
	MyString strExample[] = { "What do overloading operators do?",
							"Show an example of an operator in use.",
							"When is it acceptable to use composition in a class?",
							"Create a class whose objects represent and integer.\n"
							"Class should work as a type int." };
	MyString* str;
	str = new MyString[4];
	str = strExample;
	for (int x = 0; x < 4; x++)
		str[x] = strExample[x];
	
	//str = strExample;
	//str = new MyString[4];
	//
	//for (int x = 0; x < 4; x++)
	//	str[x] = strExample[x];

	/*delete[] str;*/
	system("pause");
	return 0;
}