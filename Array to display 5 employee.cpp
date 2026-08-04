#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string Name;
    string Company;
    int Age;

    void IntroduceYourself() {
        cout << "Name    : " << Name << endl;
        cout << "Company : " << Company << endl;
        cout << "Age     : " << Age << endl;
        cout << "--------------------------" << endl;
    }
};

int main() {
    Employee employees[5];

    // Employee 1
    employees[0].Name = "Jivindra";
    employees[0].Company = "Quest International University";
    employees[0].Age = 29;

    // Employee 2
    employees[1].Name = "Anmar";
    employees[1].Company = "AIMST University";
    employees[1].Age = 39;

    // Employee 3
    employees[2].Name = "Alice";
    employees[2].Company = "Google";
    employees[2].Age = 25;

    // Employee 4
    employees[3].Name = "Bob";
    employees[3].Company = "Microsoft";
    employees[3].Age = 31;

    // Employee 5
    employees[4].Name = "Charlie";
    employees[4].Company = "Apple";
    employees[4].Age = 28;

    // Display all employees
    for (int i = 0; i < 5; i++) {
        cout << "Employee " << i + 1 << endl;
        cout << endl; 
        employees[i].IntroduceYourself();
    }

    return 0;
}