<<<<<<< HEAD
#include <iostream>
using namespace std;

int main() {
    int num = 10;
    cout << "Original Value: " << num << "\n";

    int *ptr = &num; // ptr holds the address of num and & gets the memory address of num
    *ptr = 50;      // change num's value using the pointer

    cout << "Updated Value: " << num << "\n";

    return 0;
=======
#include <iostream>
using namespace std;

int main() {
    int num = 10;
    cout << "Original Value: " << num << "\n";

    int *ptr = &num; // ptr holds the address of num and & gets the memory address of num
    *ptr = 50;      // change num's value using the pointer

    cout << "Updated Value: " << num << "\n";

    return 0;
>>>>>>> 63776095066d8088060959af4cf37d84d9786118
}