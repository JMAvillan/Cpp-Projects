#include <iostream>
#include<string>
#include "LinkedStack.h"
using namespace std;

int main() {

	string test = "ABC$CBA";
	LinkedStack<char> stackTest;

	if (stackTest.recognizeString(test))
		cout << "Is in L language.\n";
	else
		cout << "Is not in L language.\n";



	system("pause");
	return 0;
}