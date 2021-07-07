#include <iostream>
using namespace std;

void writeArrayBackward(const char anArray[], int first, int last);

int main() {

	char arr[] = "Hello";
	writeArrayBackward(arr, 0, 4);

	system("pause");
	return 0;
}

void writeArrayBackward(const char anArray[], int first, int last)
{
	if (first <= last)
	{
		// Write the last character
		cout << anArray[last];
		// Write the rest of the array backward
		writeArrayBackward(anArray, first, last - 1);
	} // end if
	// first > last is the base case - do nothing
} // end writeArrayBackward