#include <iostream>
using namespace std;
#define N 5
int DEQUE[N];
int LEFT = -1, RIGHT = -1;
void insertLeft(int ITEM) {
    if ((LEFT == 0 && RIGHT == N - 1) || (LEFT == RIGHT + 1)) {
        cout << "OVERFLOW\n";
        return;
    }
    if (LEFT == -1) {
        LEFT = 0;
        RIGHT = 0;
    }
    else if (LEFT == 0) {
        LEFT = N - 1;
    }
    else {
        LEFT = LEFT - 1;
    }
    DEQUE[LEFT] = ITEM;
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
    insertLeft(10);
    insertLeft(20);
    insertLeft(30);
    insertLeft(40);
    insertLeft(50);
    insertLeft(60);
    displayDeque();
    return 0;
}