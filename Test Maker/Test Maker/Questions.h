#pragma once
#include "MyString.h"
#include <iostream>
class Questions
{
private:
	const MyString questionL = "Questions: \n"; //label
	MyString* question;
 	int size;
	void initQuestions()
	{
		this->question = new MyString[size];
		for (int x = 0; x < size; x++)
			this->question[x] += "";
	}
public:
	Questions();
	Questions(int s);
	Questions(MyString&, int); 
	Questions(const Questions&);
	~Questions();

	void setQuestion(MyString);
	MyString* getQuestion() const;
	void setSize(int);
	int getSize() const;
	void askQuestions();

	void addNewQuestion();
	void addNewQuestion(MyString);

	void deleteQuestion(int);

	Questions& addToList(const Questions& aQuest);
	Questions& addToList(const MyString&);
	Questions& addToList(const char ch);

	const MyString& returnSubscript(int index) const;
	MyString& returnSubscript(int index);


	Questions& incrementQuestionList();
	bool hasSpace();

	void display()const;
	void showExample() const;


	Questions& operator ++();
	Questions& operator ++(int);
	Questions& operator =(const Questions&);
	Questions& operator +=(const Questions&);
	Questions& operator +=(const MyString&);
	Questions& operator +=(const char ch);
	friend ostream& operator << (ostream&, const Questions&);
	friend istream& operator >> (istream&, Questions&);
};

