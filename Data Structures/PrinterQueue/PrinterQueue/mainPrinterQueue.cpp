#include <iostream>
#include <iomanip>
#include "ListQueue.h"
#include "LinkedList.h"
#include "PrinterJob.h"
using namespace std;
bool allQueuesEmpty(ListQueue<PrinterJob>&, ListQueue<PrinterJob>&, ListQueue<PrinterJob>&);

int main() {
	const int MAX_PRINTERS = 3;
	int availablePrinters = MAX_PRINTERS;

	double time = 0.0;
	double departureTime[MAX_PRINTERS];
	bool printerBusy[MAX_PRINTERS] = { false, false, false };

	const int listLenght = 6;
	PrinterJob list[listLenght] = { 34, 22, 16, 5, 12, 3 };

	LinkedList<PrinterJob> activeJobs;
	int nextDepartureIndex;

	ListQueue<PrinterJob> lessThan10, lessThan20, lessThan50;
	for (int x = 0; x < listLenght; x++)
	{
		if (list[x] < 10)
			lessThan10.enqueue(list[x]);
		else if (list[x] < 20)
			lessThan20.enqueue(list[x]);
		else if (list[x] <=  50)
			lessThan50.enqueue(list[x]);
	}

	bool nextDepartureFound = false;
	do 
	{
		//Eliminate next departure
		if (availablePrinters != MAX_PRINTERS && nextDepartureFound)
		{
			cout << "Printer #" << nextDepartureIndex << " finished.\nPrinted "
				<< activeJobs[nextDepartureIndex].getNumberOfPages() << " pages.\n";
			cout << "Time of completion: " << time << endl << endl;
			activeJobs.removeIntact(nextDepartureIndex);
			availablePrinters++;
			printerBusy[nextDepartureIndex - 1] = false;
		}

		while (availablePrinters != 0 && !allQueuesEmpty(lessThan10, lessThan20, lessThan50))
		{
			int printerNum = MAX_PRINTERS - availablePrinters + 1;
			if (!lessThan10.isEmpty())
			{
				if (nextDepartureFound)
				{
					activeJobs.insert(nextDepartureIndex, lessThan10.peekFront());
					lessThan10.dequeue();
					availablePrinters--;
					printerBusy[nextDepartureIndex - 1] = true;
					departureTime[nextDepartureIndex-1] = time + activeJobs[nextDepartureIndex].getTimeRequiered();
				}
				else
				{
					activeJobs.insert(printerNum, lessThan10.peekFront());
					lessThan10.dequeue();
					availablePrinters--;
					printerBusy[printerNum - 1] = true;
					departureTime[printerNum-1] = time + activeJobs[printerNum].getTimeRequiered();
				}
			}
			else if (!lessThan20.isEmpty())
			{
				if (nextDepartureFound)
				{
					activeJobs.insert(nextDepartureIndex, lessThan20.peekFront());
					lessThan20.dequeue();
					availablePrinters--;
					printerBusy[nextDepartureIndex - 1] = true;
					departureTime[nextDepartureIndex-1] = time + activeJobs[nextDepartureIndex].getTimeRequiered();
				}
				else
				{
					activeJobs.insert(printerNum, lessThan20.peekFront());
					lessThan20.dequeue();
					availablePrinters--;
					printerBusy[printerNum - 1] = true;
					departureTime[printerNum-1] = time + activeJobs[printerNum].getTimeRequiered();
				}
			}
			else if (!lessThan50.isEmpty())
			{
				if (nextDepartureFound)
				{
					activeJobs.insert(nextDepartureIndex, lessThan50.peekFront());
					lessThan50.dequeue();
					availablePrinters--;
					printerBusy[nextDepartureIndex - 1] = true;
					departureTime[nextDepartureIndex-1] = time + activeJobs[nextDepartureIndex].getTimeRequiered();
				}
				else
				{
					activeJobs.insert(printerNum, lessThan50.peekFront());
					lessThan50.dequeue();
					availablePrinters--;
					printerBusy[printerNum - 1] = true;
					departureTime[printerNum-1] = time + activeJobs[printerNum].getTimeRequiered();
				}
			}
		}
	

	//display
	cout << "Time: " << setprecision(2) << setw(4) << time << "\nActive jobs: \n";
	for (int x = 1; x <= MAX_PRINTERS; x++)
	{
		if (printerBusy[x - 1])
		{
			cout << x << ". " << activeJobs.getEntry(x) << endl;
			cout << "Departure time: " << departureTime[x - 1] << endl << endl;
		}
		else
			cout << x << ". " << "Printer currently free.\n" << endl;
	}

	/*	cout << "Current queue: \n";
		lessThan10.display();
		lessThan20.display();
		lessThan50.display();*/

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
		nextDepartureIndex = smallestIndex+1;
	}
	else
		nextDepartureFound = false;

	
}while (!allQueuesEmpty(lessThan10, lessThan20, lessThan50)  || availablePrinters != MAX_PRINTERS);
	system("pause");
	return 0;
}

bool allQueuesEmpty(ListQueue<PrinterJob>& lessThan10, ListQueue<PrinterJob>& lessThan20, ListQueue<PrinterJob>& lessThan50){
	return  lessThan10.isEmpty() && lessThan20.isEmpty() && lessThan50.isEmpty();
}