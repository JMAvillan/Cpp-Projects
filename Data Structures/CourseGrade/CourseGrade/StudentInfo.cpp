#include "StudentInfo.h"
#include <iostream>
#include <iomanip>
using namespace std;

StudentInfo::StudentInfo() {
	this->setItems(1, " ", 0, 0, ' ');
}

StudentInfo::StudentInfo(string name) {
	this->setItems(1, name, 0, 0, ' ');
}
StudentInfo::StudentInfo(int testScoreSize, string name, int idNum, double average, char letterGrade){
	this->setItems(testScoreSize, name, idNum, average, letterGrade);
}

StudentInfo::StudentInfo(double testScoresArray[], int testScoreSize, string name, int idNum, double average, char letterGrade) {
	this->setItems(testScoreSize, name, idNum, average, letterGrade);
	setTestScores(testScoresArray);
}

StudentInfo::StudentInfo(const StudentInfo& aStudent): name(aStudent.getName()), idNum(aStudent.getIdNum()),
	average(aStudent.getAverage()), letterGrade(aStudent.getLetterGrade())
{
	setTestScores(aStudent.getTestScores(), aStudent.getTestScoreSize()); 
}

StudentInfo::~StudentInfo()
{
	testScores = nullptr;
	delete[] testScores;
	testScoreSize = 0;
}


void StudentInfo::setItems(int testScoreSize, string name, int idNum, double average, char letterGrade)
{
	this->setIdNum(idNum).setAverage(average).setLetterGrade(letterGrade).setTestScoreSize(testScoreSize).setName(name);
	this->initTestScores();
}

StudentInfo& StudentInfo::setName(string name)
{
	this->name = name;
	return (*this);
}
StudentInfo& StudentInfo::setIdNum(int id)
{
	this->idNum = id;
	return (*this);
}
StudentInfo& StudentInfo::setAverage(double average)
{
	this->average = average;
	return (*this);
}
StudentInfo& StudentInfo::setLetterGrade(char letter)
{
	this->letterGrade = letter;
	return (*this);
}

StudentInfo& StudentInfo::setTestScores(double testScoreArr[])
{
	
	for (int x = 0; x < this->getTestScoreSize(); x++)
		this->testScores[x] = testScoreArr[x];

	this->calcAverage();
	this->determineLetterGrade();
	return (*this);
}

StudentInfo& StudentInfo::setTestScores(double testScoreArr[], int size)
{
	if (this->testScoreSize != size)
	{
		this->setTestScoreSize(size);
		initTestScores();
	}
	for (int x = 0; x< this->getTestScoreSize();x++)
		this->testScores[x] = testScoreArr[x];

	this->calcAverage();
	this->determineLetterGrade();
	return (*this);
}

StudentInfo& StudentInfo::setTestScoreSize(int size)
{
	this->testScoreSize = size;
	return (*this);
}

string StudentInfo::getName() const
{
	return this->name;
}
int StudentInfo::getIdNum() const
{
	return this->idNum;
}
double StudentInfo::getAverage() const
{
	return this->average;
}
char StudentInfo::getLetterGrade() const
{
	return this->letterGrade;
}
double* StudentInfo::getTestScores() const
{
	return this->testScores;
}
double StudentInfo::getATestScore(int index) const
{
	return this->testScores[index];
}

int StudentInfo::getTestScoreSize() const {
	return this->testScoreSize;
}

void StudentInfo::determineLetterGrade()
{
	if (this->average <= 100 && this->average > 90)
		this->letterGrade = 'A';
	else if (this->average <= 90 && this->average > 80)
		this->letterGrade = 'B';
	else if (this->average <= 80 && this->average > 70)
		this->letterGrade = 'C';
	else if (this->average <= 70 && this->average > 60)
		this->letterGrade = 'D';
	else 
		this->letterGrade = 'F';
}
void StudentInfo::calcAverage()
{
	double sum = 0;
	for (int x = 0; x < this->testScoreSize; x++)
		sum += this->testScores[x];
	this->average = sum / this->testScoreSize;
}

//void StudentInfo::addNewTestResult(double testResult)
//{
//	double* copyTestScores = new double[testScoreSize];
//	for (int x = 0; x < this->testScoreSize; x++)
//		copyTestScores[x] = this->testScores[x];
//	delete testScores;
//	this->testScoreSize++;
//	initTestScores();
//	for (int x = 0; x < this->testScoreSize - 1; x++)
//		this->testScores[x] = copyTestScores[x];
//
//	this->testScores[this->testScoreSize - 1] = testResult;
//
//	delete copyTestScores;
//	copyTestScores = nullptr;
//}

void StudentInfo::askInfo()
{
	cin.ignore();
	cout << "Enter name: ";
	getline(cin,this->name);
	cout << "Enter ID number: ";
	cin >> this->idNum;
	cout << "Enter test scores: \n";
	for (int x = 0; x < this->testScoreSize; x++)
	{
		cout << x + 1 << ". ";
		cin >> testScores[x];
	}
	this->calcAverage();
	this->determineLetterGrade();
}
void StudentInfo::print() const
{
	cout << "Name: " << this->getName() << endl;
	cout << "   ID Number: " << this->getIdNum() << endl;
	cout << "   Grade Average: " << this->getLetterGrade() << " " << setprecision(2) << this->getAverage() << endl;
	cout << "   Test Scores: \n";
	for (int x = 0; x < this->testScoreSize; x++)
		cout << "   " << x+1 << ". " <<testScores[x] << endl;
}
ostream& operator<<(ostream& out, const StudentInfo& aStudent)
{
	aStudent.print();
	return out;
}

bool StudentInfo::operator== (const StudentInfo& aStudent)const
{
	if (this->name == aStudent.getName())
		return true;
	else
		return false;
}