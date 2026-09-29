#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class UnsortedArray {
private:
    int arr[MAX_SIZE];
    int size;

public:
    UnsortedArray() {
        size = 0;
    }

    void insert(int value) {
        if (size >= MAX_SIZE) {
            cout << "Array is full!" << endl;
            return;
        }
        arr[size] = value;
        size++;
    }

    void display() {
        if (size == 0) {
            cout << "Array is empty." << endl;
            return;
        }
        cout << "Array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int search(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                return i;
            }
        }
        return -1;
    }

    bool remove(int value) {
        int index = search(value);
        if (index == -1) return false;

        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        return true;
    }

    int getSize() {
        return size;
    }
};

int main() {
    UnsortedArray ua;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        ua.insert(value);
    }

    cout << "\nOriginal ";
    ua.display();

    // Search demo
    int searchVal;
    cout << "\nEnter a value to search: ";
    cin >> searchVal;
    int index = ua.search(searchVal);
    if (index != -1)
        cout << "Value " << searchVal << " found at index " << index << endl;
    else
        cout << "Value " << searchVal << " not found." << endl;

    // Delete demo
    int deleteVal;
    cout << "\nEnter a value to delete: ";
    cin >> deleteVal;
    if (ua.remove(deleteVal))
        cout << "Value " << deleteVal << " deleted successfully." << endl;
    else
        cout << "Value " << deleteVal << " not found." << endl;

    cout << "\nUpdated ";
    ua.display();

    cout << "\nTotal elements now: " << ua.getSize() << endl;

    return 0;
}