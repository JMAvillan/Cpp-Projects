#pragma once
class GradedActivity
{
protected:
	double score; // To hold the numeric score
public:
	// Default constructor
	GradedActivity();
	// Constructor
	GradedActivity(double s);

	// Mutator function
	void setScore(double s);

	// Accessor functions
	double getScore() const;

	char getLetterGrade() const;
};

