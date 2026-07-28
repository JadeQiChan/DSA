#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    double marks[3];

public:
    void inputData() {
        cout << "Enter student name: ";
        cin >> name;
        for (int i = 0; i < 3; i++) {
            cout << "Enter mark for subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    double calculateTotal() {
        double total = 0;
        for (int i = 0; i < 3; i++) {
            total += marks[i];
        }
        return total;
    }

    double calculateAverage() {
        return calculateTotal() / 3;
    }

    void displayReport() {
        cout << "\nName: " << name << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Subject " << i + 1 << ": " << marks[i] << endl;
        }
        cout << "Total: " << calculateTotal() << endl;
        cout << "Average: " << calculateAverage() << endl;
    }
};

int main() {
    Student classroom[3];  // array of 3 Student objects — like a "mini database" of students

    // Loop through the array to input data for each student
    for (int i = 0; i < 3; i++) {
        cout << "\n-- Student " << i + 1 << " --" << endl;
        classroom[i].inputData();   // call inputData() on the i-th Student object
    }

    cout << "\n===== Classroom Report =====";

    // Loop through the array again to display each student's report
    for (int i = 0; i < 3; i++) {
        classroom[i].displayReport();  // call displayReport() on the i-th Student object
    }

    return 0;
}