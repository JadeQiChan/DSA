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

    // Bubble Sort (ascending order)
    void bubbleSort() {
        int comparisons = 0, swaps = 0;

        for (int i = 0; i < size - 1; i++) {
            bool swapped = false;

            for (int j = 0; j < size - 1 - i; j++) {
                comparisons++;
                if (arr[j] > arr[j + 1]) {
                    // swap
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swaps++;
                    swapped = true;
                }
            }

            // Optimization: if no swaps happened, array is already sorted
            if (!swapped) break;
        }

        cout << "\nBubble Sort complete. Comparisons: " << comparisons
             << ", Swaps: " << swaps << endl;
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

    ua.bubbleSort();

    cout << "Sorted ";
    ua.display();

    return 0;
}