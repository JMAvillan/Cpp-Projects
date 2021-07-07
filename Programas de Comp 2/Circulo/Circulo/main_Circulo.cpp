#include <iostream>
using namespace std;
#include "circle.h"

int main() {

	circle circ1;
	double circleRa;

	//Display circle data
	cout << "Input circle radius: ";
	cin >> circleRa;

	circ1.setRadius(circleRa);
	circ1.display();

	circle circ2(3);
	circ2.display();

	circle circ3(circ2);
	circ3.display();





	system("pause");
	return 0;
}