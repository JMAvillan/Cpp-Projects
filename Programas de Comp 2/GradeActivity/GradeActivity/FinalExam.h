#pragma once
#include "GradedActivity.h"
class FinalExam : public GradedActivity
{
private:
int numQuestions; // Number of questions
double pointsEach; // Points for each question
int numMissed; // Number of questions missed

public:
 // Default constructor
	FinalExam();

 // Constructor
 FinalExam(int questions, int missed);

 // Mutator functions
 void set(int, int); 
void adjustScore(); 

 // Accessor functions
double getNumQuestions() const;

 double getPointsEach() const;

 int getNumMissed() const;

};
