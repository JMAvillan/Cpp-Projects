#include "Exam.h"
#include <iostream>
using namespace std;

Exam::Exam(){}
Exam::Exam(Questions tempQuest, Header tempHeader)
{
	this->exam1 = tempQuest;
	this->header1 = tempHeader;
}
Exam::Exam(const Exam& anExam)
{
	this->exam1 = anExam.exam1;
	this->header1 = anExam.header1;
}
Exam::~Exam(){}

void Exam::setExam(Questions anExam) 
{
 this->exam1=anExam;
}
void Exam::setHeader(Header aHeader)
{
 this->header1 = aHeader;
}
Questions Exam::getExam() const
{
	return this->exam1;
}
Header Exam::getHeader()const
{
	return this->header1;
}

void Exam::showExample() const
{
	cout << "\t\t    Example Exam" << endl;
	Header temp;
	cout << temp;
	exam1.showExample();
}

Exam& Exam::operator= (const Exam& anExam)
{
	this->exam1 = anExam.exam1;
	this->header1 = anExam.header1;
	return *this;
}
ostream& operator << (ostream& out, const Exam& anExam)
{
	cout << "\t\t\tExam" << endl;
	out << anExam.header1;
	out << anExam.exam1;
	return out;
}
istream& operator >> (istream& in, Exam& anExam)
{
	cout << "New Exam: " << endl << endl;
	in >> anExam.exam1;
	in >> anExam.header1;

	cout << "Exam created successfully.\n";
	return in;
}

int Exam::getExamSize()
{
	return this->exam1.getSize();
}

void Exam::addNewQuestion()
{
	MyString input;
	cout << "Add new question:\n";
	cin.ignore();
	cin >> input;
	this->exam1.addNewQuestion(input);
}

void Exam::addNewQuestion(MyString newQ)
{
	this->exam1.addNewQuestion(newQ);
}

void Exam::deleteQuestion()
{
	if (this->getExamSize() != 0)
	{
		cout << this->exam1;
		cout << "Which question do you wish to erase?\n";
		int i;
		cin >> i;
		this->exam1.deleteQuestion(i);
		cout << "Question " << i << " deleted.\n";
		cout << this->exam1;
	}
	else
		cout << "The exam list is empty." << endl;
}

void Exam::deleteExam()
{
	int count = this->exam1.getSize();
	for (int x = 0; x < count; x++)
		this->exam1.deleteQuestion(1);

	cout << "Exam successfully erased.\n";
}

void Exam::changeQuestion()
{
	if (this->getExamSize() == 0)
		cout << "Error: No exam exists. Create exam before attempting to edit." << endl;

	else
	{
		bool loop = true;
		int option;
		while (loop)
		{
			cout << (*this);
			cout << "Which question do you wish to change?\n";
			cin >> option;
			if (option-1 > this->getExamSize() || option < 0)
			{
				cout << "Error: Out of bounds. Please select a question from list";
			}
			else
				loop = false;

		}

		MyString newQ;
		cout << "Input new question: " << endl;
		cout << option << ". ";
		cin.ignore();
		cin >> newQ;
		this->exam1.returnSubscript(option-1) = newQ;
		cout << "Question " << option << " now is:\n";
		cout << this->exam1.returnSubscript(option-1) << endl;
	}
	cin.ignore();
}

const MyString& Exam::operator [] (int index) const
{
	return this->exam1.returnSubscript(index);
}
MyString& Exam::operator [] (int index)
{
	return this->exam1.returnSubscript(index);
}

bool Exam::hasSpace() {
	return this->exam1.hasSpace();
}

void Exam::incrementQuestionList() {
	this->exam1++;
	cout << "Exam list incremented. It now has "
		<< this->exam1.getSize() << " questions.\n";
}