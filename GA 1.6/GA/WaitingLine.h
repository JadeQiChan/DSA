#ifndef WAITING_LINE_H
#define WAITING_LINE_H

#include "Ticket.h"

#include <iostream>

using namespace std;

// Assignment Part A: Queue (FIFO) implementation.
// WaitingLine implements a queue using a linked list.
// The front node is served first, following FIFO (First In, First Out).
class WaitingLine {
public:
    WaitingLine();
    ~WaitingLine();

    bool joinLine(const Ticket& ticket);
    bool joinLineSilently(const Ticket& ticket);
    bool serveNext(Ticket& servedTicket);
    void showLine() const;
    void showFront() const;
    void showRear() const;
    bool isEmpty() const;
    bool isFull() const;
    int getCount() const;
    bool removeTicketByID(int ticketID);
    bool contains(int ticketID) const;
    bool updateTicketByID(const Ticket& ticket);
    void clearLine();

private:
    // Node stores one ticket and a pointer to the next customer in line.
    struct Node {
        Ticket ticket;
        Node* next;
    };

    // head is the front of the queue, tail is the rear of the queue.
    Node* head;
    Node* tail;

    // Internal helper used by destructor and clearLine().
    void clear();
};

#endif // WAITING_LINE_H
