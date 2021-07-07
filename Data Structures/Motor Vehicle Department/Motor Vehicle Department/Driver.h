#pragma once
#include <iostream>
#include <string>
using namespace std;

class Driver
{
	private:
		string name;
		char transactionCode; //L for license renewal and R for car registration renewal
		char paymentMethod;
		bool checkApproved;
		double arrivalTime;
		double departureTime;

		static double time;
	public:
		Driver(string name = "John Doe", double arrival = 0.0, char transactionC = 'L', char paymentM= '$');
		Driver(const Driver & aD);
		~Driver();
		void setName(string n);
		void setTransactionCode(char t);
		void setPaymentMethod(char p);
		void setArrivalTime(double time);
		void setInfo(string name, double arrival, char transactionC, char paymentM);
		string getName() const;
		char getTransactionCode() const;
		char getPayMethod() const;
		double getArrivalTime() const;
		void setDepartureTime(double dTime);
		double getDepartureTime() const;
		void setCheckApproved(bool checkA);
		bool getCheckApproved() const;

		string convertTime() const;
		string convertTime(double time) const;

		friend ostream& operator << (ostream& out, const Driver& aDriver);

		bool operator > (const Driver& aDriver) const;
		bool operator == (char letter) const;
		bool operator == (const Driver& aDriver) const;

	};

