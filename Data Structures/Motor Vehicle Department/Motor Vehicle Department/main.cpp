#include <iostream>
#include "Driver.h"
#include "MVD.h"

using namespace std;

int main() {

	const int LIST_SIZE = 8;
	Driver driverList[LIST_SIZE];
	driverList[0].setInfo("Jose Rivera", 0.10, 'L', '$');
	driverList[1].setInfo("Hiram", 0.5, 'R', 'C');
	driverList[2].setInfo("Marcos", 0.52, 'R', '$');
	driverList[3].setInfo("Natalia", 0.68, 'L', 'C');
	driverList[4].setInfo("Luz", 0.99, 'L', 'C');
	driverList[5].setInfo("Angel", 1.01, 'L', '$');
	driverList[6].setInfo("Miguel", 1.03, 'L', 'C');
	driverList[7].setInfo("Luis", 1.23, 'R', '$');

	MVD localMVD;

	int x = 0;
	do {

		if (!localMVD.isEmpty())
		{
			while (LIST_SIZE >x && (localMVD.nextEventTime() > driverList[x].getArrivalTime() || localMVD.nextEventTime() == 0))
			{
				localMVD.addSignIn(driverList[x]);
				x++;
				localMVD.display();
			}
			switch (localMVD.nextEvent())
			{
			case 1://next departure came from signIn
				localMVD.addRegister_Renewal(localMVD.peekSignIn());
				localMVD.dequeueSignIn();
				break;
			case 2://next departure came from registration and renewal
				localMVD.addCashier(localMVD.peekRegistration_Renewal());
				localMVD.removeRegistration_Renewal();
				break;
			case 3: //nextDeparture came from cashier
				localMVD.dequeueCashier();
				break;
			default:
				cout << "There are no more people waiting.\n";
			}

			localMVD.display();
		}
		else
		{
			localMVD.addSignIn(driverList[x]);
			x++;
			localMVD.display();
		}




	} while (!localMVD.isEmpty());

	system("pause");
	return 0;
}