#include "MVD.h"
#include "ListQueue.h"
#include "SL_PriorityQueue.h"
#include<iostream>
#include<string>
#include <iomanip>

using namespace std;


MVD::MVD(int amountRenewal, int amountRegistration, double timeForRenewal, double timeForRegistration, double time) :
	amountRenewal(amountRenewal), amountRegistration(amountRegistration), timeForRenewal(timeForRenewal),
	timeForRegistration(timeForRegistration), time(time)
{
	registrationLine_renewalLine = new SL_PriorityQueue<Driver>();
	cashier = new ListQueue<Driver>();
	signIn = new ListQueue<Driver>();
}


MVD::~MVD()
{
}

void MVD::addSignIn(Driver aDriver){
	this->time = aDriver.getArrivalTime();
	if (!signIn->isEmpty())
		aDriver.setDepartureTime(signIn->peekFront().getDepartureTime() + (.167 * (this->signIn->getLenght() > 1 ? this->signIn->getLenght() : 1)));// .167 == 10 seconds
	else
		aDriver.setDepartureTime(this->time + .167);// .167 == 10 seconds

	signIn->enqueue(aDriver);	
}

void MVD::addRegister_Renewal(Driver aDriver) {

	int length = registrationLine_renewalLine->getLenght();
	int aDriverIndex  = registrationLine_renewalLine->getNodeIndexBefore(aDriver)+ 1;
	
		this->time = aDriver.getDepartureTime(); 
		if (aDriver.getTransactionCode() == 'R') //add departure for car registration
		{
			if (!registrationLine_renewalLine->isEmpty())
				aDriver.setDepartureTime(
					registrationLine_renewalLine->peek().getDepartureTime() 
					+ (1 * (length > 1 ? length - aDriverIndex + 1: 1))); //1 == 60 seconds
			else
				aDriver.setDepartureTime(this->time + 1); //1 == 60 seconds
		}

		else //add departure for licence renewal
		{
			if (!registrationLine_renewalLine->isEmpty())
			{
				int x = registrationLine_renewalLine->getLenght() - 1;
				double newDepart = 0;
				while (x >= aDriverIndex) {
					newDepart += ((registrationLine_renewalLine->getEntry(x).getTransactionCode() == 'R') ? 1 : 1.5);
					x--;
				}
				aDriver.setDepartureTime(
					registrationLine_renewalLine->peek().getDepartureTime() + newDepart + 1.5);
			}
			else
				aDriver.setDepartureTime(this->time + 1.5); //1.5 == 90 seconds
		}

		if (!registrationLine_renewalLine->isEmpty() && registrationLine_renewalLine->peek().getTransactionCode() == 'L')
			registrationLine_renewalLine->insertSpecial(aDriver);
		else
			registrationLine_renewalLine->add(aDriver);

		//Get the new departure times for the drivers under aDriverIndex
		if (!renewalLineIsEmpty())
		{
			for (int x = aDriverIndex-1; x > 0 ; x--, aDriverIndex--)
				if (registrationLine_renewalLine->getEntry(x).getTransactionCode() != 'R')
				{
					Driver tempDriver = registrationLine_renewalLine->getEntry(x);
					double newDepart = 0;

					int counter = registrationLine_renewalLine->getLenght()-1;
					while (counter >= aDriverIndex) {
						newDepart += ((registrationLine_renewalLine->getEntry(counter).getTransactionCode() == 'R') ? 1 : 1.5);
						counter--;
					}
					tempDriver.setDepartureTime(registrationLine_renewalLine->peek().getDepartureTime() + newDepart + 1.5);
					registrationLine_renewalLine->removeSorted(tempDriver);
					
					if (registrationLine_renewalLine->peek() == 'L')
						registrationLine_renewalLine->insertSpecial(tempDriver);
					else
					registrationLine_renewalLine->add(tempDriver);


				}
		}
}

void MVD::addCashier(Driver aDriver) {
	this->time = aDriver.getDepartureTime();
	if(!this->cashier->isEmpty())
	aDriver.setDepartureTime(this->cashier->peekFront().getDepartureTime() +
		(.5 * (this->cashier->getLenght() > 1 ? this->cashier->getLenght(): 1))); //.5 == 30 seconds
	else
	aDriver.setDepartureTime(this->time + .5);//.5 == 30 seconds

	cashier->enqueue(aDriver);
	
}

Driver MVD::peekSignIn() const	{ return this->signIn->peekFront();}
Driver MVD::peekCashier() const	{ return this->cashier->peekFront();}
Driver MVD::peekRegistration_Renewal() const	{	return this->registrationLine_renewalLine->peek();}
void  MVD::dequeueSignIn() { this->signIn->dequeue();}

void  MVD::dequeueCashier()
{
	this->time = cashier->peekFront().getDepartureTime();
	
	if (!cashier->peekFront().getCheckApproved())
	{
		Driver temp = cashier->peekFront();
		cashier->dequeue();
		temp.setCheckApproved(true);

		if (!this->cashier->isEmpty())
			temp.setDepartureTime(this->cashier->peekFront().getDepartureTime() + .167  +
				(.5* (this->cashier->getLenght() > 1 ? this->cashier->getLenght() : 1))); //.167 == 10 seconds
		else
			temp.setDepartureTime(this->time + .167 + .5);//.167 == time getting the check approved

		cashier->enqueue(temp);
		
	}
	else
	{
		(cashier->peekFront() == 'R' ? 
			(amountRegistration++) && (timeForRegistration += cashier->peekFront().getDepartureTime()-cashier->peekFront().getArrivalTime())
			: (amountRenewal++) && (timeForRenewal += cashier->peekFront().getDepartureTime()- cashier->peekFront().getArrivalTime()));
		this->cashier->dequeue();
	}
}
void  MVD::removeRegistration_Renewal()	{	this->registrationLine_renewalLine->remove();}

//Verifiy is any of the drivers in registrationLine_renewalLine has a transaction code of R
bool MVD::registrationLineIsEmpty() const
{
	if (!registrationLine_renewalLine->isEmpty()) {
		for (int x = 1; x <= registrationLine_renewalLine->getLenght(); x++)
		{
			if (registrationLine_renewalLine->getEntry(x) == 'R')
				return false;
		}
	}
	else
		return true;
}



//Verifiy is any of the drivers in registrationLine_renewalLine has a transaction code of L
bool MVD::renewalLineIsEmpty() const
{
	if (!registrationLine_renewalLine->isEmpty()) {
		for (int x = 1; x <= registrationLine_renewalLine->getLenght(); x++)
		{
			if (registrationLine_renewalLine->getEntry(x) == 'L')
				return false;
		}
	}
	else
		return true;
}

//Get the time on which the next event will take place
double MVD::nextEventTime() const {
	switch (nextEvent())
	{
	case 1:
		return signIn->peekFront().getDepartureTime();
		break;
	case 2:
		return registrationLine_renewalLine->peek().getDepartureTime();
		break;
	case 3:
		return cashier->peekFront().getDepartureTime();
		break;
	default:
		return 0;
	}
}

//Compare departure times to determine which one is the next event. The lowest departure time == the next event
//We use the isEmpty function of each list to determine if we can access it and prevent an error.
int MVD::nextEvent() const {

	if (!this->isEmpty())
	{
		if (registrationLineIsEmpty() && renewalLineIsEmpty() && cashier->isEmpty() && !signIn->isEmpty())
			return 1;//signIn
		else if (!signIn->isEmpty())
		{
			if (!cashier->isEmpty())
			{
				if (signIn->peekFront().getDepartureTime() < cashier->peekFront().getDepartureTime())
				{
					if (!registrationLine_renewalLine->isEmpty())
					{
						for (int x = 1; x <= this->registrationLine_renewalLine->getLenght(); x++)
						{
							if (signIn->peekFront().getDepartureTime() > registrationLine_renewalLine->getEntry(x).getDepartureTime())
								return 2;//registrationLine_renewalLine
						}
						return 1;//signIn
					}
					else
						return 1;//signIn
				}
				else
				{
					if (!registrationLine_renewalLine->isEmpty())
					{
						for (int x = 1; x <= this->registrationLine_renewalLine->getLenght(); x++)
						{
							if (signIn->peekFront().getDepartureTime() > registrationLine_renewalLine->getEntry(x).getDepartureTime())
								return 2;//registrationLine_renewalLine
						}
						return 3;//cashier
					}
					else
						return 3;//cashier
				}
			}
			else if (!registrationLine_renewalLine->isEmpty())
			{
				for (int x = 1; x <= this->registrationLine_renewalLine->getLenght(); x++)
				{
					if (signIn->peekFront().getDepartureTime() > registrationLine_renewalLine->getEntry(x).getDepartureTime())
						return 2;//registrationLine_renewalLine
				}
				return 1;//signIn
			}
			else
				return 1;//signIn
		}

		else if (!cashier->isEmpty())
		{
			if (!registrationLine_renewalLine->isEmpty())
			{
				for (int x = 1; x <= this->registrationLine_renewalLine->getLenght(); x++)
				{
					if (cashier->peekFront().getDepartureTime() > registrationLine_renewalLine->getEntry(x).getDepartureTime())
						return 2;//registrationLine_renewalLine
				}
				return 3;//cashier
			}
			else
				return 3;
		}
		else if (!registrationLine_renewalLine->isEmpty())
		{
			return 2;
		}
		else 
			return 0;

	}
}


bool MVD::isEmpty() const {
	return signIn->isEmpty() && cashier->isEmpty() && registrationLine_renewalLine->isEmpty();
}

//Converts time to a string format
string MVD::convertTime(double aTime) const {
	int minutes = aTime;
	int seconds = aTime * 60 - minutes * 60;
	string sTime;
	if (minutes == 0)
		sTime = "00" +
		(seconds > 0 && seconds <= 9 ? (":0" + to_string(seconds)) : ":" + (seconds == 0 ? "00" : to_string(seconds)));

	else
		sTime = (minutes > 0 && minutes <= 9 ? "0" : "") + to_string(minutes) +
		(seconds > 0 && seconds <= 9 ? (":0" + to_string(seconds)) : ":" + (seconds == 0 ? "00" : to_string(seconds)));

	return sTime;
}

void MVD::display()
{
	cout << "***************\n";
	cout << "* Time: " << setw(5) << setfill('0') << convertTime(this->time) << setfill('0') << " *" << endl;
	cout << "***************\n";

	if (!signIn->isEmpty())
	{
		cout << "Sign in Line:\n-------------\n";
		signIn->display();
	}
	else
		cout << "Sign in Line:\n-------------\nEmpty\n\n";

	if (!registrationLine_renewalLine->isEmpty())
	{
		if (!registrationLineIsEmpty())
		{
			int length = registrationLine_renewalLine->getLenght();
			int x = length;
			int y = length;

			if (registrationLine_renewalLine->peek().getTransactionCode() != 'R')
				cout << "Car Registration Wait Line:\n-----------------\n";
			else
				cout << "Car Registration Line:\n-----------------\n";
			while (x > 0)
			{
				if (registrationLine_renewalLine->getEntry(x) == 'R')
				{
					cout << length - y + 1 << ". " << registrationLine_renewalLine->getEntry(x);
					y--;
				}
				x--;
			}
		}
		else
			cout << "Car Registration line:\n-----------------\n"
			<< "No one is in line for car registration.\n\n";

		cout << endl;

		if (!renewalLineIsEmpty())
		{
			int length = registrationLine_renewalLine->getLenght();
			int x = length;
			int y = length;
			if (registrationLine_renewalLine->peek().getTransactionCode() == 'L')
			{
				cout << "License Renewal Line:\n-----------------\n";
				cout << 1 << ". " << registrationLine_renewalLine->peek() << endl;
				x--;
			}
				while (x > 0)
				{
					if (!(registrationLine_renewalLine->getEntry(x).getTransactionCode() == 'R'))
					{
						if (y == length)
						{
							if ((registrationLineIsEmpty() && !(registrationLine_renewalLine->peek().getTransactionCode() == 'L')))
								cout << "License Renewal Line:\n-----------------\n";
							else
								cout << "License Renewal wait Line:\n-----------------\n";
						}
						cout << length - y + 1 << ". " << registrationLine_renewalLine->getEntry(x);
						y--;
					}
					x--;
				}
		}
		else
			cout << "License Renewal line:\n-----------------\n" << "No one is in line for licence renewal.\n";

			cout << endl;
	}
	else
		cout << "Car Registration and Licence Renewal Line:\n"
			<<  "------------------------------------------\nLine is empty.\n\n";

	
	if (!cashier->isEmpty())
	{
		cout << "Cashier Line:\n-------------\n";
		cashier->display();
	}
	else
		cout << "Cashier Line:\n-------------\nEmpty\n";

	cout << endl;
	
	if (this->isEmpty())
	{
		cout << "A total of " << amountRegistration << " people came in for a car registration, \n"
			<< "for an average time of " << this->convertTime(timeForRegistration / amountRegistration) << ".\n";
		cout << "A total of " << amountRenewal << " people came in for a license renewal, \n"
			<< "for an average time of " << this->convertTime(timeForRenewal / amountRenewal) << ".\n";
	}
}

