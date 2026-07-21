#include <iostream>
using namespace std;

int main() {
    int num = 10;
    cout << "Original Value: " << num << "\n";

    int *ptr = &num; // ptr holds the address of num and & gets the memory address of num
    *ptr = 50;      // change num's value using the pointer

    cout << "Updated Value: " << num << "\n";

    return 0;
}