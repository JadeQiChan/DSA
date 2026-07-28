#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    // private = only accessible inside this class (encapsulation)
    string name;      // student's name
    double marks[3];  // array holding 3 subject marks

public:
    // public = accessible from outside the class (e.g. from main)

    void inputData() {
        // reads name and 3 marks from the user, stores in this object
        cout << "Enter student name: ";
        cin >> name;
        for (int i = 0; i < 3; i++) {
            cout << "Enter mark for subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    double calculateTotal() {
        // adds up all 3 marks and returns the sum
        double total = 0;
        for (int i = 0; i < 3; i++) {
            total += marks[i];
        }
        return total;
    }

    double calculateAverage() {
        // reuses calculateTotal() then divides by 3
        return calculateTotal() / 3;
    }

    void displayReport() {
        // prints name, each mark, total, and average
        cout << "\nName: " << name << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Subject " << i + 1 << ": " << marks[i] << endl;
        }
        cout << "Total: " << calculateTotal() << endl;
        cout << "Average: " << calculateAverage() << endl;
    }
};

int main() {
    Student s;         // create one Student object
    s.inputData();      // call method to collect data
    s.displayReport();  // call method to display results
    return 0;
}