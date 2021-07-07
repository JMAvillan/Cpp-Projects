#include "StudentTestScores.h"

// Constructor
StudentTestScores::StudentTestScores(string name, int numScores)
{
	studentName = name;
	createTestScoresArray(numScores);
}

// Copy constructor
StudentTestScores::StudentTestScores(const StudentTestScores& obj)
{
	studentName = obj.studentName;
	numTestScores = obj.numTestScores;
	testScores = new double[numTestScores];
	for (int i = 0; i < numTestScores; i++)
		testScores[i] = obj.testScores[i];
}

// Destructor
StudentTestScores::~StudentTestScores()

{
	delete[] testScores;
}
// The setTestScore function sets a specific
// test score's value.
void StudentTestScores::setTestScore(double score, int index)
{
	testScores[index] = score;
}
// Set the student's name.
void StudentTestScores::setStudentName(string name)
{
	studentName = name;
}

// Get the student's name.
string StudentTestScores::getStudentName() const
{
	return studentName;
}

// Get the number of test scores.
int StudentTestScores::getNumTestScores() const
{
	return numTestScores;
}
// Get a specific test score.
double StudentTestScores::getTestScores(int index) const
{
	return testScores[index];
}

