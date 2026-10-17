#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;

class Course{
private:
string name;
int creditHours;
string letterGrade;
double gradePoints;

//Helper method to convert letter grade string to grade points
double convertToPoints(const string& grade) const;

public:
//default constructor
Course();
//Parametized Constructor
Course(string courseName, int credits, string grade);

//Const Getters
string getName() const;
int getCreditHours() const;
string getLetterGrade() const;
double getGradePoints() const;
double getTotalPoints() const;

};


#endif