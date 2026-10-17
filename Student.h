// i worked on it on my own text editor and then copied it over to the workspace

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

    // calculated total credits, total points, GPA, and standing
    int getTotalCredits() const;
    double getTotalPoints() const;
    double getGPA() const;
    string getStanding() const;
};