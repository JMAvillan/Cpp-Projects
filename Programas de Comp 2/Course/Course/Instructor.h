	 #ifndef INSTRUCTOR
	 #define INSTRUCTOR
	 #include <iostream>
	 #include <string>
	 using namespace std;
		// Instructor class
	 class Instructor
	 {
	 private:
	 string lastName; // Last name
	 string firstName; // First name
	 string officeNumber; // Office number
	 public:
	 // The default constructor stores empty strings
	 // in the string objects.
	Instructor();

	 Instructor(string, string, string);
	 Instructor(const Instructor&);
	 // set function
	 void set(string, string, string);
	 void setInst(const Instructor&);
	 string getLastName()const;
	 string getFirstName()const;
	 string getOffice() const;
	 Instructor getInfo() const;
	
	 // print function
	 void print() const;
	};
#endif

