//Group Members:
//Alsseny Diallo: Worked on Main.cpp file
//Johnston Galan: Worked on Course.h and Course.cpp files
//Jack Lema: Worked on Student.h and Student.cpp files


#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <cctype>
#include "Course.h"
#include "Student.h"

using namespace std;

int main()
{
    string studentName;

    // Get the student's full name
    cout << "Enter student's full name: ";
    getline(cin, studentName);

    Student student(studentName);

    int numberOfCourses;

    // Check that the number of courses is from 1 to 10
    while (true)
    {
        cout << "Enter number of courses (1-10): ";

        if (cin >> numberOfCourses &&
            numberOfCourses >= 1 && numberOfCourses <= 10)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }

        cout << "Invalid input. Enter a number from 1 to 10.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Get information for each course
    for (int i = 0; i < numberOfCourses; i++)
    {
        string courseName;
        string grade;
        int credits;

        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter course name: ";
        getline(cin, courseName);

        // Check that credits are a whole number of 0 or more
        while (true)
        {
            cout << "Enter credit hours: ";

            if (cin >> credits && credits >= 0)
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }

            cout << "Invalid input. Enter 0 or a positive whole number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Check that the letter grade is allowed
        while (true)
        {
            cout << "Enter letter grade (A, A-, B+, B, B-, "
                 << "C+, C, C-, D, F): ";

            getline(cin, grade);

            // Allow lowercase letters too
            for (char &letter : grade)
            {
                letter = toupper(static_cast<unsigned char>(letter));
            }

            if (grade == "A" || grade == "A-" ||
                grade == "B+" || grade == "B" ||
                grade == "B-" || grade == "C+" ||
                grade == "C" || grade == "C-" ||
                grade == "D" || grade == "F")
            {
                break;
            }

            cout << "Invalid grade. Please try again.\n";
        }

        // Create the course and add it to the student
        Course course(courseName, credits, grade);
        student.addCourse(course);
    }

    // Sort courses by credits, highest first
    vector<Course> courses = student.getCourses();

    sort(courses.begin(), courses.end(),
         [](const Course &a, const Course &b)
         {
             if (a.getCreditHours() == b.getCreditHours())
             {
                 return a.getName() < b.getName();
             }

             return a.getCreditHours() > b.getCreditHours();
         });

    // Print the transcript
    cout << "\n";
    cout << setfill('=') << setw(76) << "" << setfill(' ') << endl;
    cout << "                     STUDENT GRADE REPORT\n";
    cout << setfill('=') << setw(76) << "" << setfill(' ') << endl;

    cout << "Student Name: " << student.getName() << "\n\n";

    cout << left << setw(27) << "Course Name"
         << right << setw(9) << "Credits"
         << setw(12) << "Grade"
         << setw(13) << "Grade Pts"
         << setw(15) << "Total Pts" << endl;

    cout << setfill('-') << setw(76) << "" << setfill(' ') << endl;

    cout << fixed << setprecision(2);

    // Display each course
    for (const Course &course : courses)
    {
        cout << left << setw(27) << course.getName()
             << right << setw(9) << course.getCreditHours()
             << setw(12) << course.getLetterGrade()
             << setw(13) << course.getGradePoints()
             << setw(15) << course.getTotalPoints()
             << endl;
    }

    cout << setfill('-') << setw(76) << "" << setfill(' ') << endl;

    // Display total credits and total points
    int totalCredits = student.getTotalCredits();
    double totalPoints = student.getTotalPoints();

    cout << left << setw(27) << "TOTALS"
         << right << setw(9) << totalCredits
         << setw(25) << totalPoints << endl;

    cout << "\n";

    // Display GPA and academic standing
    if (totalCredits > 0)
    {
        cout << "Semester GPA: " << student.getGPA() << endl;
        cout << "Academic Standing: " << student.getStanding() << endl;
    }
    else
    {
        cout << "Semester GPA: N/A (no credits earned)" << endl;
        cout << "Academic Standing: N/A" << endl;
    }

    cout << setfill('=') << setw(76) << "" << setfill(' ') << endl;

    return 0;
}
