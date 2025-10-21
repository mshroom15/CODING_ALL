#include <iostream>

using namespace std;

int main() {
    char info[12]={' ', ' ', 'U', 'E', 'C', 'R', 'T', 'E', ' ', ' ', 'S',
         ' '};
    int link[12] = {0, 0, 8, 0, 11, 3, 5, 7, 0, 0, 4, 0};
    int start = 5;
    int current = start;
    cout << "The elements in the list are: ";
    while (current != 0) {
        cout << info[current];  // Removed space after character
        current = link[current];
    }
    cout << endl;

    return 0;
}
