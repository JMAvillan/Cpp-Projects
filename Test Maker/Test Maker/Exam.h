#pragma once
#include "Questions.h"
#include "Header.h"
#include <iostream>
using namespace std;
class Exam
{
private:
	Questions exam1;
	Header header1;
public:
	Exam();
	Exam(Questions, Header);
	Exam(const Exam&);
	~Exam();
	
	void setExam(Questions);
	void setHeader(Header);
	Questions getExam() const;
	Header getHeader()const;

	void showExample() const;
	
	int getExamSize();
	void addNewQuestion();
	void addNewQuestion(MyString);
	void changeQuestion();

	void deleteQuestion();
	void deleteExam();

	void incrementQuestionList();
	bool hasSpace();

	Exam& operator = (const Exam& anExam);
	friend ostream& operator << (ostream&, const Exam&);
	friend istream& operator >> (istream&, Exam&);
	const MyString& operator [] (int) const;
	MyString& operator [] (int);


};

