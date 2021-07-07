#pragma once
#include<iostream>
using namespace std;
#include"SL_PriorityQueue.h"
#include "ListQueue.h"
#include"Driver.h"
class MVD
{
private:
	SL_PriorityQueue<Driver>* registrationLine_renewalLine; // renew licence 90 seconds, register 60 seconds
	ListQueue<Driver>* cashier; //30 seconds, if paying by check and its not approved add 10 seconds for it being approved and throw at back of line
	ListQueue<Driver>* signIn; //10 seconds


	int amountRenewal=0;
	int amountRegistration=0;
	double timeForRenewal=0.0;
	double timeForRegistration=0.0;

	double time;

public:
	MVD(int amountRenewal= 0, int amountRegistration=0, double timeForRenewal=0.0, double timeForRegistration=0.0, double time=0.0);
	MVD(const MVD& aMVD);
	~MVD();

	void addSignIn(Driver aDriver);
	void addRegister_Renewal(Driver aDriver);
	void addCashier(Driver aDriver);
	Driver peekSignIn() const;
	Driver peekCashier() const;
	Driver peekRegistration_Renewal() const;
	void dequeueSignIn();
	void dequeueCashier();
	void removeRegistration_Renewal();
	bool isEmpty() const;
	int nextEvent() const;
	bool registrationLineIsEmpty() const;
	bool renewalLineIsEmpty() const;
	double nextEventTime()const;
	string convertTime(double aTime) const;



	void display();
};

