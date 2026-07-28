#include <iostream>   // for cin, cout (input/output)
#include <string>     // to allow use of the string data type
using namespace std;

int main() {
    string name;              // stores the student's name
    double math, science, english;  // stores marks for 3 subjects (decimal allowed)

    cout << "Enter student name: ";
    cin >> name;               // read name from user input
    getline(cin, name); //read and store the entire line, including space

    cout << "Enter Math mark: ";
    cin >> math;                // read Math mark
    cout << "Enter Science mark: ";
    cin >> science;              // read Science mark
    cout << "Enter English mark: ";
    cin >> english;              // read English mark

    double total = math + science + english;  // add all 3 marks together
    double average = total / 3;                // divide total by number of subjects

    // print all results
    cout << "\nName: " << name << endl;
    cout << "Math: " << math << ", Science: " << science << ", English: " << english << endl;
    cout << "Total: " << total << endl;
    cout << "Average: " << average << endl;

    return 0;  // end of program
}