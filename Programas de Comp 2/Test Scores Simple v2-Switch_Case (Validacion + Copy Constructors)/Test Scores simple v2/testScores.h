#ifndef TESTSCORES_H
#define TESTSCORES_H
using namespace std;

class TestScores {
private:
	double grade1, grade2, grade3;

public:
	TestScores();
	TestScores(double, double, double);
	TestScores(const TestScores&);
	void setScores(double, int);
	double getScores(int) const;
	double getAverage();
	void display();
};



#endif TESTSCORES_H