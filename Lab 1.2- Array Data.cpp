#include <iostream>
#include <string>
using namespace std;

int main() {
    string names[3];        // 1D array to hold 3 student names
    double marks[3][3];     // 2D array: row = student, column = subject

    // Loop through each student to collect data
    for (int i = 0; i < 3; i++) {       // 3 students, 0 1 2)
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> names[i];             // store name of student i 

        // Inner loop collects marks for each subject of student i
        for (int j = 0; j < 3; j++) {
            cout << "Enter mark for subject " << j + 1 << ": ";        //3 subjects
            cin >> marks[i][j];       // store mark for student i, subject j
        }
    }

    // Loop through each student again to calculate and display results
    for (int i = 0; i < 3; i++) {
        double total = 0;             // reset total for each student

        // Add up all subject marks for student i
        for (int j = 0; j < 3; j++) {
            total += marks[i][j];      // total = total + marks[i][j]
        }
        double average = total / 3;    // calculate average for student i

        cout << "\nStudent: " << names[i] << endl;

        // Print each subject mark individually
        for (int j = 0; j < 3; j++) {
            cout << "Subject " << j + 1 << ": " << marks[i][j] << endl;
        }
        cout << "Total: " << total << ", Average: " << average << endl;
    }

    return 0;
}