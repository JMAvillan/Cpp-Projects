#include "Questions.h"

Questions::Questions() {
	this->size = 0;
	this->initQuestions();
}
Questions::Questions(int s)
{
	this->size = s;
	this->initQuestions();
}
Questions::Questions(MyString& str, int s) 
{	 
	this->size = s;
	this->initQuestions();
	for (int x = 0; x < this->size; x++)
		this->question[x] = str[x];

}
Questions::Questions(const Questions& aQuestion)
{
	this->size = aQuestion.size;
	this->initQuestions();
	(*this) = aQuestion;
}

Questions::~Questions()
{
	delete[] this->question;
	this->question = nullptr;
}

void Questions::setQuestion(MyString str)
{
	this->question = &str;
}
MyString* Questions::getQuestion() const
{
	return this->question;
}
void  Questions::setSize(int s)
{
	this->size = s;
}
int  Questions::getSize() const
{
	return this->size;
}

void  Questions::askQuestions()
{
	cout << "How many questions do you wish to enter?" << endl;
	cin >> size;
	initQuestions();
	cin.ignore();
	for (int x = 0; x < size; x++)
	{
		cout << "Enter question " << x + 1 << ":" << endl;
		cin >> question[x];
		cout << endl;
	}
}
void Questions::display() const
{
	cout << questionL;
	for (int x = 0; x < size; x++)
		cout << x+1 << ". " << question[x] << endl;
}

void Questions :: showExample() const
{ 
	//Questions example(4);
	MyString str[] = { "What do overloading operators do?","Show an example of an operator in use.",
						"When is it acceptable to use composition in a class?",
						"Create a class whose objects represent and integer.\n"
						"   Class should work as a type int." };
	Questions example(4);
	for (int x = 0; x < example.size; x++)
		example += str[x];
	cout << "Example ";
	cout << example;
}
bool Questions::hasSpace() {
	if (size != 0)
	{
		for (int x = size - 1; x >= 0; x--)
			if (this->question[x] == "")
				return true;
	}
	return false;

}
void Questions::addNewQuestion() 
{
	this->incrementQuestionList();
	cout << "Add new question: \n";
	cin >> this->question[size - 1];
}

void Questions::addNewQuestion(MyString newQ)
{
	this->incrementQuestionList();
	(*this) += newQ; 
	cout << "New question added.\n";
}

Questions& Questions::addToList(const Questions& aQuest)
{
	if (!(hasSpace()))
		(*this) = aQuest;
	else
		cout << "Question list already full.\n";

	return *this;
}

Questions& Questions::addToList(const MyString& aStr)
{
	if ((hasSpace()))
	{
		if (this->size == 1)
		{
			this->question[0] = aStr;
			return *this;
		}
		for (int x = 0; x < size; x++)
		{
			if (this->question[x] == "")
			{
				this->question[x] = aStr;
				return *this;
			}
		}
	}
	else
		cout << "Question list already full.\n";

	return *this;
}
Questions& Questions::addToList(const char ch)
{
	MyString temp = &ch;
	if ((hasSpace()))
		for (int x = 0; x < size; x++)
		{
			if (this->question[x] == "")
				this->question[x] = temp[x];
		}
	else
		cout << "Question list already full.\n";

	return *this;
}

const MyString& Questions::returnSubscript(int index) const
{
	return this->question[index];
}
MyString& Questions::returnSubscript(int index)
{
	return this->question[index];
}

void Questions::deleteQuestion(int index)
{
	size--;
	for (int x = index-1; x < size; x++)
		this->question[x] = this->question[x + 1];
}

Questions& Questions::incrementQuestionList() {
	Questions tempQ(*this);
	this->size++;
	
	delete[] this->question;
	this->initQuestions();
	for (int x=0; x< this->size-1;x++)
	(*this)+=tempQ.question[x];

	this->question[size - 1] = "";
	return (*this);
}
Questions& Questions::operator =(const Questions& aQuest)
{
	if (this->size != aQuest.size)	//validate size
	{
		delete[] this->question;
		this->size = aQuest.size;
		this->initQuestions();
	}
	for (int x = 0; x < size; x++)
	{
		(*this) += aQuest.question[x];
	}
	return *this;
}

Questions& Questions::operator ++()
{
	incrementQuestionList();
	return *this;
}

Questions& Questions::operator ++(int x)
{
	incrementQuestionList();
	return *this;
}

Questions& Questions::operator +=(const Questions& aQuest)
{
	this->addToList(aQuest);
	return *this;
}
Questions& Questions::operator +=(const MyString& aStr)
{
	this->addToList(aStr);
	return *this;
}

Questions& Questions::operator +=(const char ch)
{
	this->addToList(ch);
	return *this;
}
ostream& operator << (ostream& out, const Questions& aQuestion)
{
	aQuestion.display();
	return out;
}
istream& operator >> (istream& in, Questions& aQuestion)
{
	aQuestion.askQuestions();
	return in;
}
