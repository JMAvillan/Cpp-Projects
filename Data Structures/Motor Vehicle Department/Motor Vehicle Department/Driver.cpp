#include<iostream>
#include<string>
#include "Driver.h"
using namespace std;

Driver::Driver(string name, double arrival, char transactionC, char paymentM): name(name),
				transactionCode(transactionC), paymentMethod(paymentM), arrivalTime(arrival),departureTime(0.0){
	if (paymentMethod == 'C')
		checkApproved = false;
	else
		checkApproved = true;
}


Driver::~Driver()
{
}

Driver::Driver(const Driver& aD):  name(aD.name),transactionCode(aD.transactionCode), 
paymentMethod(aD.paymentMethod), arrivalTime(aD.arrivalTime), checkApproved(aD.checkApproved), departureTime(aD.departureTime) {
}

void Driver::setName(string n) { this->name = n; }
void Driver::setTransactionCode(char t) { this->transactionCode = t; }
void Driver::setPaymentMethod(char p) { this->paymentMethod = p; }
void Driver::setArrivalTime(double time) { this->arrivalTime = time; }
string Driver::getName() const { return this->name; }
char Driver::getTransactionCode() const { return this->transactionCode; }
char Driver::getPayMethod() const { return this->paymentMethod; }
double Driver::getArrivalTime() const { return this->arrivalTime; }
void Driver::setDepartureTime(double dTime) { this->departureTime = dTime; }
double Driver::getDepartureTime() const { return this->departureTime; }
void Driver::setCheckApproved(bool checkA) { this->checkApproved = checkA; }
bool Driver::getCheckApproved() const { return this->checkApproved; }


void Driver::setInfo(string name, double arrival, char transactionC, char paymentM)
{	
	setName(name);
	setTransactionCode(transactionC);
	setPaymentMethod(paymentM);
	setArrivalTime(arrival);
	if (this->paymentMethod == 'C')
		checkApproved = false;
	else
		checkApproved = true;
}

string Driver::convertTime() const {
	int minutes = this->arrivalTime;
	int seconds = this->arrivalTime * 60 - minutes * 60;
	string sTime;
	if (minutes == 0)
		sTime = "00" +
		(seconds > 0 && seconds <= 9 ? (":0" + to_string(seconds)) : ":" + (seconds == 0 ? "00" : to_string(seconds)));

	else
		sTime = (minutes > 0 && minutes <= 9 ? "0": "") + to_string(minutes) +
		(seconds > 0 && seconds <= 9 ? (":0" + to_string(seconds)) : ":" + (seconds == 0 ? "00" : to_string(seconds)));

	return sTime;
}

string Driver::convertTime(double time) const {
	int minutes = time;
	int seconds = time * 60 - minutes * 60;
	string sTime;
	if (minutes == 0)
		sTime = "00" +
		(seconds > 0 && seconds <= 9 ? (":0" + to_string(seconds)) : ":" + (seconds == 0 ? "00" : to_string(seconds)));

	else
		sTime = (minutes > 0 && minutes <= 9 ? "0" : "") + to_string(minutes) +
		(seconds > 0 && seconds <= 9 ? (":0" + to_string(seconds)) : ":" + (seconds == 0 ? "00" :to_string(seconds)));

	return sTime;
}


bool Driver::operator > (const Driver& aDriver) const{
	
	if (this->transactionCode == 'R' && aDriver.transactionCode == 'L')
			return true;
	else if (this->transactionCode == 'L' && aDriver.transactionCode == 'R')
		return false;
	else if (this->transactionCode == 'R' && aDriver.transactionCode == 'R')
		return false;
	else if (this->transactionCode == 'L' && aDriver.transactionCode == 'L')
		return !(this->name > aDriver.name);
}

bool Driver::operator == (char letter ) const{
	return this->transactionCode == letter;
	}

bool Driver::operator == (const Driver& aDriver) const {
	
	return (this->transactionCode == aDriver.getTransactionCode() &&
		this->name == aDriver.getName() && this->paymentMethod == aDriver.getPayMethod() &&
		this->checkApproved == aDriver.getCheckApproved() && this->arrivalTime == aDriver.getArrivalTime());

}


ostream& operator << (ostream& out, const Driver& aDriver)
{
	out << "Driver's Name: " << aDriver.getName() << endl
		<< "   In for: " << (aDriver.getTransactionCode() == 'R' ? "Car registration" : "Licence renewal") << endl;
	out << "   Payment method: ";
	if (aDriver.getPayMethod() == 'C')
		out << "   Check (Status: " << (aDriver.getCheckApproved() ? "True)" : "False)") << endl;
	else
		out << "   Cash" << endl;
	out << "   Arrived at: " << aDriver.convertTime() << endl; 
	out << "   Next Departure: " <<aDriver.convertTime(aDriver.getDepartureTime()) << endl;

	return out;
}