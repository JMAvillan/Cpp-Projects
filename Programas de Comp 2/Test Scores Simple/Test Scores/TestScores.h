#ifndef TESTSCORES_H
#define TESTSCORES_H
using namespace std;

class TestScores {
private:
	double grade1, grade2, grade3;

public:
	TestScores();
	TestScores(const TestScores&);
	void setScores(double, double, double);
	double getScores(int);
	void getAverage();
};



#endif TESTSCORES_H