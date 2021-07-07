#pragma once
#include <iostream>
#include <string>
using namespace std;

class SpeakerInfo
{
private:
	string name, telephoneNum, speakingTopic;
	double fee;

public:
	SpeakerInfo(string name = " ", string telephoneNum = " ", string speakingTopic = " ", double fee = 0.0);
	SpeakerInfo(const SpeakerInfo& aSpeaker);
	~SpeakerInfo();

	void setName(string name);
	void setTelephoneNum(string telephone);
	void setSpeakingTopic(string speakingTopic);
	void setFee(double fee);

	string getName()const;
	string getTelephone() const;
	string getSpeakingTopic() const;
	double getFee() const;
	
	void operator = (const SpeakerInfo& aSpeaker);
	bool operator==(const SpeakerInfo& aSpeaker) const;
	bool operator == (string aName) const;
	bool operator < (const SpeakerInfo& aSpeaker) const;
	bool operator > (const SpeakerInfo& aSpeaker) const;

	friend ostream& operator << (ostream& out, const SpeakerInfo& aSpeaker);
	friend istream& operator >> (istream& in, SpeakerInfo& aSpeaker);
	void showInfo() const;
	void askInfo();
};

