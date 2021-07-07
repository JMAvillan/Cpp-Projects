#pragma once
#include <string>
#include<iostream>
using namespace std;

class StudentInfo
{
private:
	string name;
	int idNum;
	double* testScores;
	int testScoreSize;
	double average;
	char letterGrade;

	void initTestScores()
	{
		this->testScores = new double[this->testScoreSize];
	}

public:
	StudentInfo();
	StudentInfo(string name);
	StudentInfo(int testScoreSize,string name, int idNum, double average, char letterGrade);
	StudentInfo(double testScoresArray[], int testScoreSize, string name, int idNum, double average, char letterGrade);
	
	StudentInfo(const StudentInfo& aStudent);
	~StudentInfo();
	void setItems(int testScoreSize, string name, int idNum, double average, char letterGrade);
	StudentInfo& setName(string name);
	StudentInfo& setIdNum(int id);
	StudentInfo& setAverage(double average);
	StudentInfo& setLetterGrade(char letter);
	StudentInfo& setTestScores(double testScoreArr[]);
	StudentInfo& setTestScores(double testScoreArr[],int size);
	StudentInfo& setTestScoreSize(int size);
	string getName() const;
	int getIdNum() const;
	double getAverage() const;
	char getLetterGrade() const;
	double* getTestScores() const;
	double getATestScore(int index)const;
	int getTestScoreSize() const;

	void determineLetterGrade();
	void calcAverage();
	void askInfo();
	void print() const;

	friend ostream& operator<<(ostream& out, const StudentInfo& aStudent);
	friend istream& operator>>(istream& in, StudentInfo& aStudent);
	bool operator== (const StudentInfo& aStudent)const;

};

