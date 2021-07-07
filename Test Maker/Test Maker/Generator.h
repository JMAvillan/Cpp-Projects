#pragma once
#include "Exam.h"
#include "MyMenu.h"
class Generator
{
private:
	Exam exam;
public:
	/*Generator();
	Generator(Exam);
	Generator(const Generator&);
	~Generator();*/

	void setExam(Exam);
	Exam getExam();

	void showMenu();




};