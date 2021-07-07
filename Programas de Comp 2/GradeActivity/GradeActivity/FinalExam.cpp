#include "FinalExam.h"
// Default constructor
FinalExam::FinalExam()
{
	numQuestions = 0;
	pointsEach = 0.0;
	numMissed = 0;
}

// Constructor
FinalExam::FinalExam(int questions, int missed)
{
	set(questions, missed);
}

// Mutator functions
void FinalExam::set(int questions, int missed)
{
	double numericScore; // To hold the numeric score
	
	 // Set the number of questions and number missed.
	 numQuestions = questions;
	 numMissed = missed;
	
	// Calculate the points for each question.
	 pointsEach = 100.0 / numQuestions;
	 // Calculate the numeric score for this exam.
	 numericScore = 100.0 - (missed * pointsEach);
	
	 // Call the inherited setScore function to set
	 // the numeric score.
	 setScore(numericScore);
	
	 // Call the adjustScore function to adjust
	// the score.
	 adjustScore();
}

void FinalExam::adjustScore()
{
 double fraction = score - static_cast<int>(score);
 if (fraction >= 0.5)
 {
	 // Adjust the score variable in the GradedActivity class.
	 score += (1.0 - fraction);
 }
}
	
 // Accessor functions
double FinalExam::getNumQuestions() const
{
	return numQuestions;
}

double FinalExam::getPointsEach() const
{
	return pointsEach;
}

int FinalExam::getNumMissed() const
{
	return numMissed;
}
