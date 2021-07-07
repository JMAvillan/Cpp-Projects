#ifndef TESTSCORES_H
#define TESTSCORES_H
using namespace std;

class TestScores {
private:
	double *score;
	int numTests;
	const double DEFAULT_SCORE = 0.0;
	const int DEFAULT_AMOUNT = 3;
	//private memeber function to create an array of test scores
	void createTestScoresArray(int size)
	{
		numTests = size;
		score = new double[size];
		for (int x = 0; x < size; x++)
			score[x] = DEFAULT_SCORE;
	}

public:
	TestScores();
	TestScores(double, double, double);
	TestScores(const TestScores&);
	/*~TestScores();*/
	void setScores(double, int);
	double getScores(int) const;
	double getAverage();
	void display(int);
};



#endif TESTSCORES_H