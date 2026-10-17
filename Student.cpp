#include "Student.h"

using namespace std;

// Default constructor
Student::Student() {
    name = "";
}

// the constructor
Student::Student(string studentName) {
    name = studentName;
}

// getting the students name
string Student::getName() const {
    return name;
}

// getting the courses
vector<Course> Student::getCourses() const {
    return courses;
}

// adding a course
void Student::addCourse(Course course) {
    courses.push_back(course);
}

// finding total credits
int Student::getTotalCredits() const {
    int totalCredits = 0;

    for (int i = 0; i < courses.size(); i++) {
        totalCredits += courses[i].getCreditHours();
    }

    return totalCredits;
}

// finding total points
double Student::getTotalPoints() const {
    double totalPoints = 0;

    for (int i = 0; i < courses.size(); i++) {
        totalPoints += courses[i].getTotalPoints();
    }

    return totalPoints;
}

// calculating GPA
double Student::getGPA() const {
    if (getTotalCredits() == 0) {
        return 0.0;
    }

    return getTotalPoints() / getTotalCredits();
}

// finding academic standing
string Student::getStanding() const {
    double gpa = getGPA();

    if (gpa >= 3.70) {
        return "dean's List";
    }
    else if (gpa >= 2.00) {
        return "good standing";
    }
    else {
        return "probation";
    }
}