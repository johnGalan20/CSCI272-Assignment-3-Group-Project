#include <string>
#include <vector>
#include "Course.h"

using namespace std;

class Student {

private:
    string name;
    vector<Course> courses;

public:
    Student();
    Student(string studentName);

    string getName() const;
    vector<Course> getCourses() const;

    void addCourse(Course course);

    // Calculate total credits, total points, GPA, and standing
    int getTotalCredits() const;
    double getTotalPoints() const;
    double getGPA() const;
    string getStanding() const;
};