#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string Name;
    string Company;
    int Age;

    void IntroduceYourself() {
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }
};

int main() {
    Employee employee1;

    employee1.Name = "Jivindra";
    employee1.Company = "Quest International University";
    employee1.Age = 29;

    employee1.IntroduceYourself();

    cout << endl;

    Employee employee2;
    employee2.Name = "Anmar";
    employee2.Company = "AIMST University";
    employee2.Age = 39;

    employee2.IntroduceYourself();

    return 0;
}