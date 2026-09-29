#include <iostream>   // for cin/cout
using namespace std;

// ===========================================================
// Class: Book - blueprint for one book record
// ===========================================================
class Book {
private:   // only accessible inside the class
    string bookID;
    string title;
    string author;
    int copies;

public:    // accessible from main()

    // ---------- Part A: Constructors ----------

    // Default constructor - sets placeholder values
    Book() {
        bookID = "N/A";
        title = "Unknown";
        author = "Unknown";
        copies = 0;
    }

    // Parameterized constructor - sets given values
    Book(string id, string t, string a, int c) {
        bookID = id;
        title = t;
        author = a;
        copies = c;
    }

    // ---------- Getters (data is private, so these give safe read access) ----------
    // const = these functions promise not to modify the object
    string getID() const     { return bookID; }
    string getTitle() const  { return title; }
    string getAuthor() const { return author; }
    int getCopies() const     { return copies; }

    // ---------- Setter for Part E ----------
    void addCopies(int extra) {
        copies += extra;
    }

    // ---------- Print all details of one book ----------
    void display() const {
        cout << "Book ID: " << bookID << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Copies: " << copies << endl;
    }
};

int main() {

    // ---------- Part B: Array of 5 Book objects ----------
    Book books[5] = {
        Book("B101", "Data Structures",    "Mark Allen",  8),
        Book("B102", "C++ Programming",    "John Smith",  12),
        Book("B103", "Database Systems",   "Peter Brown", 5),
        Book("B104", "Operating Systems",  "Linda Tan",   9),
        Book("B105", "Computer Networks",  "David Lee",   7)
    };

    // ---------- Part C: Pointer Operations ----------
    // ptr points to the first element of the array
    Book* ptr = books;

    cout << "Library Books" << endl << endl;

    // Display all books using pointer arithmetic only (ptr + i, ->)
    // (ptr + i) moves to the i-th Book; parentheses needed since
    // -> binds tighter than +. No books[i] indexing used here.
    for (int i = 0; i < 5; i++) {
        cout << "Book ID: " << (ptr + i)->getID() << endl;
        cout << "Title: " << (ptr + i)->getTitle() << endl;
        cout << "Author: " << (ptr + i)->getAuthor() << endl;
        cout << "Copies: " << (ptr + i)->getCopies() << endl;
        cout << endl;
    }

    // ---------- Part D: Search Book ----------
    string searchID;
    cout << "Enter Book ID to search: ";
    cin >> searchID;

    // found stores the address of the matching book, or nullptr if none
    Book* found = nullptr;

    for (int i = 0; i < 5; i++) {
        if ((ptr + i)->getID() == searchID) {
            found = (ptr + i);   // save pointer to the matching book
            break;                 // stop once found
        }
    }

    // ---------- Part D & E: Display Result / Update Copies ----------
    if (found != nullptr) {
        cout << "\nBook Found" << endl;
        found->display();

        // Part E: update copies
        int extra;
        cout << "\nEnter additional copies: ";
        cin >> extra;

        found->addCopies(extra);   // update through the pointer

        cout << "\nUpdated Book Information" << endl;
        found->display();
    } else {
        cout << "Book not found." << endl;
    }

    return 0;
}