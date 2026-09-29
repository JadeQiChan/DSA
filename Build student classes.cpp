#include <iostream>
#include <string>
using namespace std;

// ---------- Abstraction ----------
class Person {
public:
    // Pure virtual function — no implementation here.
    // Any class inheriting from Person MUST provide its own version.
    virtual void introduce() const = 0;
};

// ---------- Inheritance ----------
class Student : public Person {
private:
    // ---------- Encapsulation (kept from Stage 1) ----------
    string name;
    string course;
    string studentID;

public:
    void setDetails(string n, string c, string id) {
        name = n;
        course = c;
        studentID = id;
    }

    string getName() const      { return name; }
    string getCourse() const    { return course; }
    string getStudentID() const { return studentID; }

    // ---------- Polymorphism ----------
    void introduce() const override {
        cout << "Student Name - " << name << endl;
        cout << "Course - " << course << endl;
        cout << "Student ID - " << studentID << endl;
    }
};

int main() {
    Student student1;
    student1.setDetails("Jivindra", "Quest International University", "29");
    student1.introduce();

    return 0;
}