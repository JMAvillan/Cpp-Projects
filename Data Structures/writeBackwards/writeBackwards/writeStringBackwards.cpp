#include <iostream>
#include <string>

using namespace std;

void writeBackwards(string name);

int main() {

	string name;

	cout << "Enter name: ";
	getline(cin, name);

	cout << "The name spelled backwards is: ";
	writeBackwards(name);
	cout << endl;

	system("pause");
	return 0;
}

void writeBackwards(string name) {

	int length = name.size(); // Length of string
	if (length > 0)
	{
		cout << name.substr(length - 1, 1);

		writeBackwards(name.substr(0, length - 1));
	}
}
