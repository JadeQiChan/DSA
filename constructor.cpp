#include <iostream>
#include <string>

using namespace std;

class Employee
{
public:
    string Name;
    string Company;
    int Age;

    // Parameterized Constructor
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }

    void IntroduceYourself()
    {
        cout << "Name: " << Name << endl;
        cout << "Company: " << Company << endl;
        cout << "Age: " << Age << endl;
    }
};

int main()
{
    // Creating object and passing values to constructor
    Employee employee1 = Employee("Jivindra", "Quest International", 29);

    employee1.IntroduceYourself();

    return 0;
}