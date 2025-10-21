#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
int main() {
    const int SIZE = 13;
    char INFO[SIZE] = {' ', ' ', ' ', 'U', 'E', 'C', 'R', 'T', 'E', ' ', ' ', 'S', ' '};
    int LINK[SIZE] = {0, -1, -1, 8, -1, 11, 3, 5, 7, -1, -1, 4, -1};
    int START = 6;
    int AVAIL = 2;
    cout << "Initial Linked List:\n";
    int PTR = START;
    while (PTR != -1) {
        cout << "INFO[" << PTR << "] = " << INFO[PTR]
             << " | LINK[" << PTR << "] = " << LINK[PTR] << endl;
        PTR = LINK[PTR];
    }
    char ITEM;
    int LOC;
    cout << "\nEnter ITEM to insert: ";
    cin >> ITEM;
    cout << "Enter node location after which to insert (-1 to insert at beginning): ";
    cin >> LOC;
    auto start_time = high_resolution_clock::now();
    if (AVAIL == -1) {
        cout << "OVERFLOW: No available space to insert.\n";
        return 0;
    }
    int NEW = AVAIL;
    AVAIL = LINK[AVAIL];
    INFO[NEW] = ITEM;
    if (LOC == -1) {
        LINK[NEW] = START;
        START = NEW;
    } else {
        LINK[NEW] = LINK[LOC];
        LINK[LOC] = NEW;
    }
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end_time - start_time);
    cout << "\nUpdated Linked List:\n";
    PTR = START;
    while (PTR != -1) {
        cout << "INFO[" << PTR << "] = " << INFO[PTR]
             << " | LINK[" << PTR << "] = " << LINK[PTR] << endl;
        PTR = LINK[PTR];
    }
    cout << "\nExecution Time: " << duration.count() << " nanoseconds\n";
    return 0;
}