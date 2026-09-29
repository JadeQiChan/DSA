#ifndef CANCEL_LOG_H
#define CANCEL_LOG_H

#include "Ticket.h"

#include <iostream>
#include <string>

using namespace std;

// Assignment Part B: Stack (LIFO) implementation.
// CancelLog implements a stack using an array.
// The most recent cancellation is placed at the top and can be undone first.
class CancelLog {
public:
    CancelLog();

    bool recordCancel(const CancelEntry& entry);
    bool recordCancelSilently(const CancelEntry& entry);
    bool undoCancel(CancelEntry& entry);
    bool peekLatest(CancelEntry& entry) const;
    void showAllCancels() const;
    bool isEmpty() const;
    bool isFull() const;
    int getCount() const;
    bool saveToFile(const string& fileName, bool showMessage) const;
    bool loadFromFile(const string& fileName, bool showMessage);
    void clear();

private:
    // Fixed stack capacity for cancellation records.
    static const int MaxCapacity = 50;

    // Array stack storage and top pointer.
    CancelEntry entries[MaxCapacity];
    int topIndex;
};

#endif // CANCEL_LOG_H
