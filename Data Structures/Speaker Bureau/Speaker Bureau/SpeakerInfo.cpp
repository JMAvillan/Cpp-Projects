#include "SpeakerInfo.h"
#include <iostream>
#include <string>
using namespace std;

SpeakerInfo::SpeakerInfo(string name, string telephoneNum, string speakingTopic, double fee) :
	name(name), telephoneNum(telephoneNum), speakingTopic(speakingTopic), fee(fee)
{}
SpeakerInfo::SpeakerInfo(const SpeakerInfo& aSpeaker):
	name(aSpeaker.getName()), telephoneNum(aSpeaker.getTelephone()),
	speakingTopic(aSpeaker.getSpeakingTopic()), fee(aSpeaker.getFee())
{}
SpeakerInfo::~SpeakerInfo() {}

void SpeakerInfo::setName(string name)
{
	this->name = name;
}
void SpeakerInfo::setTelephoneNum(string telephone)
{
	this->telephoneNum = telephone;
}
void SpeakerInfo::setSpeakingTopic(string speakingTopic)
{
	this->speakingTopic = speakingTopic;
}
void SpeakerInfo::setFee(double fee)
{
	this->fee = fee;
}

string SpeakerInfo::getName()const
{
	return this->name;
}
string SpeakerInfo::getTelephone() const
{
	return this->telephoneNum;
}
string SpeakerInfo::getSpeakingTopic() const
{
	return this->speakingTopic;
}
double SpeakerInfo::getFee() const
{
	return this->fee;
}

void SpeakerInfo::showInfo() const
{
	cout << name << endl
		<< "Telephone Number: " << telephoneNum << endl
		<< "Topic: " <<speakingTopic << endl
		<< "Speaker's fee: $" << fee << endl;
}
void SpeakerInfo::askInfo()
{
	cout << "Enter speaker's name: ";
	getline(cin,name);
	cout << "Enter telephone number: ";
	getline(cin, telephoneNum);
	cout << "Enter speaking topic: ";
	getline(cin,speakingTopic);
	cout << "Enter the speaker's fee: ";
	cin >> fee;
}

void SpeakerInfo::operator = (const SpeakerInfo& aSpeaker)
{
	this->name = aSpeaker.getName();
	this->telephoneNum = aSpeaker.getTelephone();
	this->speakingTopic = aSpeaker.getSpeakingTopic();
	this->fee = aSpeaker.getFee();
}

bool SpeakerInfo::operator==(const SpeakerInfo& aSpeaker) const
{
	return (this->getName() == aSpeaker.getName());

	/*	&& (this->getTelephone() == aSpeaker.getTelephone()) &&
		(this->getSpeakingTopic() == aSpeaker.getSpeakingTopic()) &&
		(this->getFee() == aSpeaker.getFee())));*/

}

bool SpeakerInfo::operator== (string aName) const
{
		if (this->name == aName)
			return true;

	return false;
}

bool SpeakerInfo::operator<(const SpeakerInfo& aSpeaker) const
{
	if (this->name < aSpeaker.getName())
		return true;
	else
		return false;
}

bool SpeakerInfo::operator > (const SpeakerInfo& aSpeaker) const
{
	if (this->name > aSpeaker.getName())
		return true;
	else
		return false;
}
ostream& operator << (ostream& out, const SpeakerInfo& aSpeaker)
{
	aSpeaker.showInfo();
	return out;
}
istream& operator >> (istream& in, SpeakerInfo& aSpeaker)
{
	aSpeaker.askInfo();
	return in;
}