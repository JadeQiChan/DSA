#include "Finder.h"

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// Print one aligned table row with fixed column widths.
static void printTableRow(const string& metric, const string& linearValue, const string& binaryValue) {
    cout << "| " << left << setw(26) << metric
         << " | " << left << setw(28) << linearValue
         << " | " << left << setw(28) << binaryValue
         << " |" << endl;
}

// Linear search checks tickets one by one from the start of the array.
int Finder::linearFind(const Ticket tickets[], int ticketCount, int ticketID, int& comparisons) {
    comparisons = 0;
    for (int index = 0; index < ticketCount; ++index) {
        comparisons++;
        if (tickets[index].ticketID == ticketID) {
            return index;
        }
    }
    return -1;
}

// Sort a copy of tickets by ticketID using insertion sort before binary search.
static void insertionSortByTicketID(Ticket sortedTickets[], int ticketCount) {
    for (int i = 1; i < ticketCount; ++i) {
        Ticket key = sortedTickets[i];
        int j = i;

        // Move elements that are greater than key.ticketID one position ahead.
        while (j > 0 && sortedTickets[j - 1].ticketID > key.ticketID) {
            sortedTickets[j] = sortedTickets[j - 1];
            --j;
        }
        sortedTickets[j] = key;
    }
}

// Binary search works on a sorted copy of the ticket array.
int Finder::binaryFind(const Ticket tickets[], int ticketCount, int ticketID, int& comparisons) {
    Ticket* sortedTickets = new Ticket[ticketCount];
    for (int index = 0; index < ticketCount; ++index) {
        sortedTickets[index] = tickets[index];
    }
    insertionSortByTicketID(sortedTickets, ticketCount);

    int left = 0;
    int right = ticketCount - 1;
    comparisons = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        comparisons++;
        if (sortedTickets[mid].ticketID == ticketID) {
            delete[] sortedTickets;
            return mid;
        }
        if (sortedTickets[mid].ticketID < ticketID) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    delete[] sortedTickets;
    return -1;
}

// Print Big-O comparison table for presentation/demo.
void Finder::printComparisonTable(int linearComparisons, int binaryComparisons) {
    const string border = "+----------------------------+------------------------------+------------------------------+";

    cout << border << endl;
    printTableRow("Metric", "Linear Search", "Binary Search");
    cout << border << endl;
    printTableRow("Comparisons (this run)", to_string(linearComparisons), to_string(binaryComparisons));
    printTableRow("Best Case", "O(1)", "O(1)");
    printTableRow("Worst Case", "O(n)", "O(log n)");
    printTableRow("Needs Sorted Data First", "No", "Yes, sort first");
    printTableRow("Advantage", "Simple, no sorting needed", "Fast on sorted data");
    printTableRow("Disadvantage", "Slow for large datasets", "Must sort data first");
    cout << border << endl;
}
