#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    // INFO and LINK arrays (indexing starts from 1)
    char INFO[13] = {' ', '-', '-', 'U', 'E', 'C', 'R', 'T', 'E', '-', '-', 'S', '-'};
    int LINK[13]  = {0, 10, 0, 8, 0, 11, 3, 5, 7, 1, 12, 4, 2};

    int START = 6;
    char ITEM;
    cout << "Enter item to search: ";
    cin >> ITEM;

    int PTR = START;
    int LOC = 0;

    // Start timing
    auto startTime = high_resolution_clock::now();

    // Linear search in unsorted linked list
    while (PTR != 0) {
        if (INFO[PTR] == ITEM) {
            LOC = PTR;
            break;
        }
        PTR = LINK[PTR];
    }

    // End timing
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(endTime - startTime);

    // Output result
    if (LOC != 0)
        cout << "Item '" << ITEM << "' found at location: " << LOC << endl;
    else
        cout << "Item '" << ITEM << "' not found (LOC = NULL)" << endl;

    cout << "Execution Time: " << duration.count() << " nanoseconds" << endl;

    return 0;
}