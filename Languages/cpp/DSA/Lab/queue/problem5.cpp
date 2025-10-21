#include <iostream>
using namespace std;
#define N 5
int DEQUE[N];
int LEFT = -1, RIGHT = -1;

int deleteRight() {
    if (LEFT == -1) {  
        cout << "UNDERFLOW\n";
        return -1;
    }
    int ITEM = DEQUE[RIGHT];
    if (RIGHT == LEFT) { 
        LEFT = -1;
        RIGHT = -1;
    }
    else if (RIGHT == 0) { 
        RIGHT = N - 1;
    }
    else {
        RIGHT = RIGHT - 1;
    }
    return ITEM;
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
    LEFT = 0; 
    RIGHT = 4;
    DEQUE[0] = 10; 
    DEQUE[1] = 20; 
    DEQUE[2] = 30; 
    DEQUE[3] = 40; 
    DEQUE[4] = 50;
    
    cout << "Initial deque: ";
    displayDeque();
    
    int x = deleteRight();
    if (x != -1) cout << "Deleted from right: " << x << "\n";
    
    cout << "After deletion: ";
    displayDeque();
    
    return 0;
}