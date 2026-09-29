#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100; // maximum number of actions the stack can hold

class ActionStack {
private:
    string actions[MAX_SIZE];
    int top; // index of the most recent action, -1 means empty

public:
    ActionStack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    // push() -- add a new action
    void push(string action) {
        if (isFull()) {
            cout << "Stack is full! Cannot perform more actions.\n";
            return;
        }
        top++;
        actions[top] = action;
        cout << "Action added successfully.\n";
    }

    // pop() -- remove the most recent action
    string pop() {
        if (isEmpty()) {
            cout << "No actions to undo.\n";
            return "";
        }
        string removed = actions[top];
        top--;
        return removed;
    }

    // peek() -- view the most recent action
    string peek() {
        if (isEmpty()) {
            return "";
        }
        return actions[top];
    }

    // display() -- display all stored actions (most recent first)
    void display() {
        if (isEmpty()) {
            cout << "No actions have been performed yet.\n";
            return;
        }
        cout << "===== ACTION HISTORY =====\n";
        int count = 1;
        for (int i = top; i >= 0; i--) {
            cout << count << ". " << actions[i] << "\n";
            count++;
        }
    }

    int count() {
        return top + 1;
    }

    void clear() {
        top = -1;
        cout << "All actions have been cleared.\n";
    }
};

void showMenu() {
    cout << "\n===== TEXT EDITOR =====\n";
    cout << "1. Perform Action\n";
    cout << "2. Undo Last Action\n";
    cout << "3. View Last Action\n";
    cout << "4. Display All Actions\n";
    cout << "5. Count Actions\n";
    cout << "6. Clear All Actions\n";
    cout << "7. Exit\n";
    cout << "Enter choice: ";
}

int main() {
    ActionStack editor;
    int choice;
    string action;

    do {
        showMenu();
        cin >> choice;
        cin.ignore(); // clear the newline left in the input buffer

        switch (choice) {
            case 1: {
                cout << "Enter action: ";
                getline(cin, action);
                editor.push(action);
                break;
            }
            case 2: {
                string undone = editor.pop();
                if (!undone.empty()) {
                    cout << "Undo: " << undone << "\n";
                }
                break;
            }
            case 3: {
                string last = editor.peek();
                if (!last.empty()) {
                    cout << "Last Action: " << last << "\n";
                } else {
                    cout << "No actions performed yet.\n";
                }
                break;
            }
            case 4:
                editor.display();
                break;
            case 5:
                cout << "Total Actions: " << editor.count() << "\n";
                break;
            case 6:
                editor.clear();
                break;
            case 7:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}