#include<iostream>
#include<string>

#include "ArrayBag.h"
#include "SpeakerInfo.h"
using namespace std;

int main()
{
	ArrayBag<SpeakerInfo> bagSpeaker;
	
	SpeakerInfo temp[3];
	string test[3];
	test[0] = "Test 1";
	test[1] = "Test 2";
	test[2] = "Test 3";
	for (int x = 3 ; x>0; x--)
	bagSpeaker.addToIndex(test[x-1],x+x-1);
	bagSpeaker.showInfo();
	bagSpeaker.sort();
	bagSpeaker.showInfo();
	bagSpeaker.binarySearch(0, bagSpeaker.getCurrentSize(), test[2]);


	
	/*cout << "Please input the following information that\n"
		<< "correspond to the " << bagSpeaker.getMaxItems() << " speakers.\n";

	bagSpeaker.askInfo();*/

	//Menu
	bool exit = false;
	do
	{
		int numInput;
		SpeakerInfo temp;
		string name;
		char input;
		int index;
		cout << "What do you wish to do with the information entered?\n\n";

		cout << "A. Show list\n"
			<< "B. Add new information to specific index\n"
			<< "C. Add new information to top of list\n"
			<< "D. Sort list in alphabetical order\n"
			<< "E. Search by name\n"
			<< "F. Faster search (requires sorting list in \nalphabethical order)\n"
			<< "G. Erase a slot\n"
			<< "H. Erase complete list\n"
			<< "I. Exit\n";
		cin >> input;

		switch (input)
		{
			case 'A':
			case 'a':
			{	//show list
				bagSpeaker.showInfo();
				cin.ignore();
				cout << "Press enter to go back. (ENTER)";
				cin.get();
				break;
			}
			case 'B':
			case 'b':
			{	//Add new information to an index
				bagSpeaker.showInfo();
				bool remaindingItems = bagSpeaker.getCurrentSize() < bagSpeaker.getMaxItems();
				if (bagSpeaker.getCurrentSize() + 2 > bagSpeaker.getMaxItems() && remaindingItems)
					cout << "Slot ";
				else if (!(bagSpeaker.getCurrentSize() + 2 > bagSpeaker.getMaxItems()))
					cout << "Slots ";
				if (remaindingItems)
				{
					for (int x = bagSpeaker.getCurrentSize(); x < bagSpeaker.getMaxItems(); x++)
					{
						cout << x + 1;
						if (x + 2 == bagSpeaker.getMaxItems())
							cout << " and ";
						else if (!(x + 1 >= bagSpeaker.getMaxItems()))
							cout << ", ";
					}
					if (bagSpeaker.getCurrentSize() + 2 > bagSpeaker.getMaxItems())
						cout << " is also available.\n";
					else
						cout << " are also available.\n";
				}
				cout << "Which slot do you wish to change?\n";
				cin >> numInput;
				cout << "Changing the information on speaker #" << numInput << ".\n";
				cout << "Enter the following:\n";
				cin.ignore();
				cin >> temp;

				if (bagSpeaker.addToIndex(temp, numInput - 1))
					cout << "Succesfully changed item in slot #" << numInput << ".\n";
				else
					cout << "Error: Couldn't change the specified slot.\n";

				cin.ignore();
				cout << "Press enter to go back. (ENTER)\n";
				cin.get();
				break;
			}
			case 'C':
			case 'c':
			{//Add new information to beginning of list
				bagSpeaker.showInfo();
				cout << "Change the information on speaker #1.\n";
				cout << "Enter the following information:\n";
				cin.ignore();
				cin >> temp;

				if (bagSpeaker.addToIndex(temp, 0))
					cout << "Succesfully changed item in slot #" << 1 << ".\n";
				else
					cout << "Error: Couldn't change the specified slot.\n";
				
				cin.ignore();
				cout << "Press enter to go back. (ENTER)\n";
				cin.get();
				break;
			}
			case 'D':
			case 'd':
			{	bagSpeaker.sort();
				cout << "List is now sorted.\n";
				cin.ignore();
				cout << "Press enter to go back. (ENTER)\n";
				cin.get();
				break;
			}
			case 'E':
			case 'e':
			{	//Search by name (linear)
				cin.ignore();
				cout << "Who are you looking for?\n";
				getline(cin, name);

				//operator overloading to check if the name appears on list
				index = bagSpeaker == name;
				if (index != -1)
				{
					cout << name << " found in slot " << index+1 << ".\n";
					cout << bagSpeaker[index];
				}
				else
					cout << "Error: " << name << " not found on list.\n";

				cin.ignore();
				cout << "Press enter to go back.(ENTER)\n";
				cin.get();
				break;
			}
			case 'F':
			case 'f':
			{	//Search by name (binary)
				cin.ignore();
				cout << "Who are you looking for?\n";
				getline(cin, name);
				index = bagSpeaker.binarySearch(0, bagSpeaker.getCurrentSize(), name);
				if (index != -1)
				{
					cout << name << " found in slot " << index +1 << ".\n";
					cout << bagSpeaker[index];
				}
				else
					cout << "Error: " << name << " not found on list.\n";
				cin.ignore();
				cout << "Press enter to go back.(ENTER)\n";
				cin.get();
				break;
			}
			case 'G':
			case 'g':
			{	bagSpeaker.showInfo();
				cin.ignore();
				cout << "Type the name of the person you want to remove: ";
				getline(cin, name);
				if (bagSpeaker.completelyRemove(name))
				{
					cout << "Person removed from list.\n";
					bagSpeaker.showInfo();
				}
				else
					cout << "Error: Couldnt remove because the\nspecified name is not on the list.\n";
			
				cout << "Press enter to go back.(ENTER)\n;";
				cin.get();
				break;
			}
			case 'H':
			case 'h':
			{	bagSpeaker.showInfo();
				cout << "Attempting to erase entire list.\n"
				<< "Are you sure? Y/N \n";
				cin >> input;
				if (input == 'Y' || input == 'y')
				{
					int lenghtList = bagSpeaker.getCurrentSize();
					for (int count = 0; count < lenghtList; count++)
					{
						temp = bagSpeaker[lenghtList - count];
						bagSpeaker.completelyRemove(temp);
					}
					cout << "List erased.\n";
				}
				else if (input == 'n' || input == 'N')
					cout << "Canceled option.\n";
				else
					cout << "Invalid input. Canceling option...\n";

				cin.ignore();
				cout << "Press enter to go back.(ENTER)\n;";
				cin.get();
				break;
				}
			case 'I':
			case 'i':
			{
				cout << "Goodbye\n";
				exit = true;
				break;
			}

		}
	} while (!exit);


system("pause");
return 0;
}