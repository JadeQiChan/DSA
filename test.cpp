#include <iostream>
#include <string>
using namespace std;

class Course {
private:
    string courseCode;
    string courseName;
    int credits;
    int enrolledStudents;

public:
    // Default constructor
    Course() {
        courseCode = "N/A";
        courseName = "Unknown";
        credits = 0;
        enrolledStudents = 0;
    }

    // Parameterized constructor
    Course(string code, string name, int c, int enrolled) {
        courseCode = code;
        courseName = name;
        credits = c;
        enrolledStudents = enrolled;
    }

    // Getters
    string getCode() const       { return courseCode; }
    string getName() const       { return courseName; }
    int getCredits() const       { return credits; }
    int getEnrolled() const      { return enrolledStudents; }

    // Setter
    void addStudents(int n) {
        enrolledStudents += n;
    }

    // Display
    void display() const {
        cout << "Course Code: " << courseCode << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Credits: " << credits << endl;
        cout << "Enrolled Students: " << enrolledStudents << endl;
    }
};

int main() {
    Course c("CS101", "Intro to Programming", 3, 25);

    cout << "--- Before ---" << endl;
    c.display();

    c.addStudents(5);

    cout << "\n--- After ---" << endl;
    c.display();

    return 0;
}