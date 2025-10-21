#include <iostream>
using namespace std;
#define N 5
int DEQUE[N];
int LEFT = -1, RIGHT = -1;
void insertRight(int ITEM) {
    if ((LEFT == 0 && RIGHT == N - 1) || (LEFT == RIGHT + 1)) {
        cout << "OVERFLOW\n";
        return;
    }
    if (RIGHT == -1) {
        LEFT = 0;
        RIGHT = 0;
    }
    else if (RIGHT == N - 1) {
        RIGHT = 0;
    }
    else {
        RIGHT = RIGHT + 1;
    }
    DEQUE[RIGHT] = ITEM;
    cout << "Inserted " << ITEM << "\n";
}
void displayDeque() {
    if (LEFT == -1) {
        cout << "Deque is empty\n";
        return;
    }
    int i = LEFT;
    while (true) {
        cout << DEQUE[i] << " ";
        if (i == RIGHT) break;
        i = (i + 1) % N;
    }
    cout << "\n";
}
int main() {
    insertRight(10);
    insertRight(20);
    insertRight(30);
    insertRight(40);
    insertRight(50);
    insertRight(60);
    displayDeque();
    return 0;
}   