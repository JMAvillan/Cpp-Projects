#pragma STUDENTTESTSCORES_H
 #include <string>
 using namespace std;

 const double DEFAULT_SCORE = 0.0;

 class StudentTestScores
 {
 private:
	 string studentName; // The student's name
	 double* testScores; // Points to array of test scores
	 int numTestScores; // Number of test scores

	 // Private member function to create an
	// array of test scores.
	 void createTestScoresArray(int size)
	 {
		 numTestScores = size;
		 testScores = new double[size];
		 for (int i = 0; i < size; i++)
			 testScores[i] = DEFAULT_SCORE;
	 }

 public:
	 // Constructor
	 StudentTestScores(string name, int numScores);
	 StudentTestScores(const StudentTestScores& obj); // Copy constructor
	 ~StudentTestScores(); // Destructor
	 void setTestScore(double score, int index);// The setTestScore function sets a specific
												// test score's value.
	 void setStudentName(string name);	 // Set the student's name.
	 string getStudentName() const; // Get the student's name.
	 double getTestScores(int) const;
	 int getNumTestScores() const;// Get the number of test scores
 };