#include "CancelLog.h"

#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

const int CancelLogWidth = 100;

void printCancelSeparator() {
    cout << string(CancelLogWidth, '-') << endl;
}

void printCancelTitle(const string& title) {
    int leftPadding = (CancelLogWidth - static_cast<int>(title.length())) / 2;
    if (leftPadding < 0) {
        leftPadding = 0;
    }
    cout << string(leftPadding, ' ') << title << endl;
}

void printCancelField(const string& label, const string& value) {
    cout << "  " << left << setw(14) << label << right << ": " << value << endl;
}

void printCancelEntryDetails(const CancelEntry& entry) {
    printCancelField("Ticket ID", to_string(entry.ticketID));
    printCancelField("Customer", entry.customerName);
    printCancelField("Reason", entry.note);
    printCancelField("Cancelled At", entry.cancelledAt);
}

string cleanCancelFileField(const string& text) {
    string cleanedText = text;
    for (char& ch : cleanedText) {
        if (ch == '|') {
            ch = '/';
        }
    }
    return cleanedText;
}

CancelLog::CancelLog()
    : topIndex(-1) {
}

// Push a cancellation record onto the stack.
bool CancelLog::recordCancel(const CancelEntry& entry) {
    if (isFull()) {
        cout << "Cannot record cancellation: cancel log is full." << endl;
        return false;
    }

    topIndex++;
    entries[topIndex] = entry;
    cout << "Cancellation recorded: Ticket #" << entry.ticketID << " at " << entry.cancelledAt << "." << endl;
    return true;
}

bool CancelLog::recordCancelSilently(const CancelEntry& entry) {
    if (isFull()) {
        return false;
    }

    topIndex++;
    entries[topIndex] = entry;
    return true;
}

// Pop the latest cancellation record for undo operation.
bool CancelLog::undoCancel(CancelEntry& entry) {
    if (isEmpty()) {
        cout << "No cancellations to undo." << endl;
        return false;
    }

    entry = entries[topIndex];
    topIndex--;
    cout << "Undoing cancellation for Ticket #" << entry.ticketID << "." << endl;
    return true;
}

// View the latest cancellation without removing it from the stack.
bool CancelLog::peekLatest(CancelEntry& entry) const {
    if (isEmpty()) {
        cout << "No cancellations available to peek." << endl;
        return false;
    }

    entry = entries[topIndex];
    cout << endl;
    printCancelSeparator();
    printCancelTitle("Latest Cancellation");
    printCancelSeparator();
    printCancelEntryDetails(entry);
    printCancelSeparator();
    return true;
}

// Display cancellation records from newest to oldest.
void CancelLog::showAllCancels() const {
    if (isEmpty()) {
        cout << "Cancellation log is empty." << endl;
        return;
    }

    cout << endl;
    printCancelSeparator();
    printCancelTitle("Cancellation Records (Most Recent First)");
    printCancelSeparator();
    for (int index = topIndex; index >= 0; --index) {
        const CancelEntry& entry = entries[index];
        cout << endl;
        printCancelTitle("Cancellation " + to_string(topIndex - index + 1));
        printCancelEntryDetails(entry);
    }
    printCancelSeparator();
}

bool CancelLog::isEmpty() const {
    return topIndex < 0;
}

bool CancelLog::isFull() const {
    return topIndex >= MaxCapacity - 1;
}

int CancelLog::getCount() const {
    return topIndex + 1;
}

// Save cancellation stack records so cancellation history is kept after restarting the program.
bool CancelLog::saveToFile(const string& fileName, bool showMessage) const {
    ofstream outputFile(fileName);
    if (!outputFile) {
        if (showMessage) {
            cout << "Unable to open cancellation log file for saving." << endl;
        }
        return false;
    }

    outputFile << "TicketID|CustomerName|Reason|CancelledAt" << endl;
    for (int index = 0; index <= topIndex; ++index) {
        const CancelEntry& entry = entries[index];
        outputFile << entry.ticketID << "|"
                   << cleanCancelFileField(entry.customerName) << "|"
                   << cleanCancelFileField(entry.note) << "|"
                   << cleanCancelFileField(entry.cancelledAt) << endl;
    }

    if (showMessage) {
        cout << "Cancellation log saved to " << fileName << "." << endl;
    }
    return true;
}

// Load saved cancellation records back into the array stack.
bool CancelLog::loadFromFile(const string& fileName, bool showMessage) {
    ifstream inputFile(fileName);
    if (!inputFile) {
        if (showMessage) {
            cout << "Unable to open cancellation log file for loading." << endl;
        }
        return false;
    }

    clear();
    string line;
    getline(inputFile, line);
    int loadedCount = 0;
    int skippedCount = 0;
    while (getline(inputFile, line)) {
        if (line.empty()) {
            continue;
        }

        stringstream lineStream(line);
        string idText;
        string customerName;
        string reason;
        string cancelledAt;
        string extraText;
        getline(lineStream, idText, '|');
        getline(lineStream, customerName, '|');
        getline(lineStream, reason, '|');
        getline(lineStream, cancelledAt, '|');
        bool hasExtraColumn = static_cast<bool>(getline(lineStream, extraText, '|'));

        stringstream idStream(idText);
        int ticketID = 0;
        bool invalidLine = !(idStream >> ticketID)
            || ticketID <= 0
            || !isValidText(customerName)
            || !isValidText(reason)
            || !isValidText(cancelledAt)
            || hasExtraColumn
            || isFull();

        if (invalidLine) {
            skippedCount++;
            continue;
        }

        topIndex++;
        entries[topIndex] = CancelEntry{ticketID, customerName, reason, cancelledAt};
        loadedCount++;
    }

    if (showMessage) {
        cout << "Loaded " << loadedCount << " cancellation record(s) from " << fileName << "." << endl;
    }
    if (showMessage && skippedCount > 0) {
        cout << "Skipped " << skippedCount << " invalid cancellation row(s)." << endl;
    }
    return true;
}

void CancelLog::clear() {
    topIndex = -1;
}
