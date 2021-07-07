#include "GradedActivity.h"

// Default constructor
GradedActivity::GradedActivity()
{
	score = 0.0;
}

// Constructor
GradedActivity::GradedActivity(double s)
{
	score = s;
}

// Mutator function
void GradedActivity::setScore(double s)
{
	score = s;
}

// Accessor functions
double GradedActivity::getScore() const
{
	return score;
}
char GradedActivity::getLetterGrade() const
{
	if (score >= 90 && score <= 100)
		return 'A';
	if (score < 90 && score >=80)
		return 'B';
	if (score <80  && score >=70)
		return 'C';
	if (score <70 && score >= 60)
		return 'D';
	if (score < 60)
		return 'F';
}