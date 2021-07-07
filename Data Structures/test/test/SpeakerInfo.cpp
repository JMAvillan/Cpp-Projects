#include "SpeakerInfo.h"
#include <iostream>
#include <string>
using namespace std;

SpeakerInfo::SpeakerInfo(string name, string telephoneNum, string speakingTopic, double fee) :
	name(name), telephoneNum(telephoneNum), speakingTopic(speakingTopic), fee(fee)
{}
SpeakerInfo::SpeakerInfo(const SpeakerInfo& aSpeaker) :
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

void SpeakerInfo::showInfo()
{
	cout << name << endl
		<< telephoneNum << endl
		<< speakingTopic << endl
		<< "Speaker's fee: $" << fee << endl;
}
void SpeakerInfo::askInfo()
{
	cout << "Enter speaker name: ";
	getline(cin, name);
	cout << "Enter telephone number: ";
	getline(cin, telephoneNum);
	cout << "Enter speaking topic: ";
	getline(cin, speakingTopic);
	cout << "Enter the speaker's fee: ";
	cin >> fee;
}