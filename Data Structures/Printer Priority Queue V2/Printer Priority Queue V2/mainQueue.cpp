#include "PrinterJob.h"
#include "SL_PriorityQueue.h"
#include "LinkedSortedList.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	const int MAX_PRINTERS = 3;
	int availablePrinters = MAX_PRINTERS;

	double time = 0.0;
	double departureTime[MAX_PRINTERS];
	bool printerBusy[MAX_PRINTERS] = { false, false, false };
	PrinterJob activeJobs[MAX_PRINTERS];
	int nextDepartureIndex;

	const int listLenght = 6;
	PrinterJob printerJobs[listLenght] = { 34, 22, 16, 5, 12, 3 };

	SL_PriorityQueue<PrinterJob> priorityQueue;
	for (int x = 0; x < listLenght; x++) {
		priorityQueue.add(printerJobs[x]);
	}

	bool nextDepartureFound = false;
	do
	{
		//Eliminate next departure
		if (availablePrinters != MAX_PRINTERS && nextDepartureFound)
		{
			cout << "Printer #" << nextDepartureIndex << " finished.\nPrinted "
				<< activeJobs[nextDepartureIndex].getNumberOfPages() << " pages.\n";
			cout << "Time of completion: " << time << endl;
			if (!priorityQueue.isEmpty())
				cout << "Next job: \n" << priorityQueue.peek() << endl << endl;
			else
				cout << endl;
			availablePrinters++;
			printerBusy[nextDepartureIndex - 1] = false;
		}

		while (availablePrinters != 0 && !priorityQueue.isEmpty())
		{
			int printerNum = MAX_PRINTERS - availablePrinters + 1;

				if (nextDepartureFound)
				{
					activeJobs[nextDepartureIndex] = priorityQueue.peek();
					priorityQueue.remove();
					availablePrinters--;
					printerBusy[nextDepartureIndex - 1] = true;
					departureTime[nextDepartureIndex - 1] = time + activeJobs[nextDepartureIndex].getTimeRequiered();
				}
				else
				{
					activeJobs[printerNum] = priorityQueue.peek();
					priorityQueue.remove();
					availablePrinters--;
					printerBusy[printerNum - 1] = true;
					departureTime[printerNum - 1] = time + activeJobs[printerNum].getTimeRequiered();
				}
			
		}
	
		//display
		cout << "Time: " << setprecision(2) << setw(4) << time << "\nActive jobs: \n";
		for (int x = 1; x <= MAX_PRINTERS; x++)
		{
			if (printerBusy[x - 1])
			{
				cout << x << ". " << activeJobs[x] << endl;
				cout << "Departure time: " << departureTime[x - 1] << endl << endl;
			}
			else
				cout << x << ". " << "Printer currently free.\n" << endl;
		}


		bool checked = false;
		int  index = 0;
		int smallestIndex = 0;
		while (!checked)
		{
			if (index < MAX_PRINTERS - 1)
			{
				if (printerBusy[index] && printerBusy[index + 1])
					smallestIndex = (departureTime[smallestIndex] < departureTime[index + 1] ? smallestIndex : index + 1);
				else if (!(printerBusy[index]))
				{
					if (printerBusy[index + 1])
						smallestIndex = index + 1;
				}
				else if ((printerBusy[0] && printerBusy[1] && printerBusy[2]))
					smallestIndex = -1;

				index++;
			}
			else
				checked = true;
		}
		if (smallestIndex != -1)
		{
			nextDepartureFound = true;
			time = departureTime[smallestIndex];
			nextDepartureIndex = smallestIndex + 1;
		}
		else
			nextDepartureFound = false;


	} while (!priorityQueue.isEmpty() || availablePrinters != MAX_PRINTERS);
	system("pause");
	return 0;
}
