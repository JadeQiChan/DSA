#include <iostream>
#include <string>
using namespace std;

class Student {
    public: 
        string Name;
        string Course;
        string Student_id;

        void StudentProfile(){
            cout << "Student Name - " << Name << endl;
            cout << "Course - " << Course << endl;
            cout << "Student ID - " << Student_id << endl;
        }

};

int main () {
    Student student1;
        student1.Name = "Jivindra";
        student1.Course = "Quest International University";
        student1.Student_id = 29;
        student1.StudentProfile();
        cout << endl;

    Student student2;
        student2.Name = "Jivindra";
        student2.Course = "Quest International University";
        student2.Student_id = 29;
        student2.StudentProfile();
        cout << endl;


    Student student3;
        student3.Name = "Jivindra";
        student3.Course = "Quest International University";
        student3.Student_id = 29;
        student3.StudentProfile();
        cout << endl;
}