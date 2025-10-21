#include <iostream>
using namespace std;
#define N 5
void QINSERT(int QUEUE[], int &FRONT, int &REAR, int ITEM) {
    if ((FRONT == 1 && REAR == N) || (FRONT == REAR + 1)) {
        cout << "OVERFLOW" << endl;
        return;
    }
    if (FRONT == 0) {
        FRONT = 1;
        REAR = 1;
    }
    else if (REAR == N) {
        REAR = 1;
    }
    else {
        REAR = REAR + 1;
    }
    QUEUE[REAR - 1] = ITEM;
}
int main() {
    int QUEUE[N] = {0};
    int FRONT = 0, REAR = 0;
    QINSERT(QUEUE, FRONT, REAR, 10);
    QINSERT(QUEUE, FRONT, REAR, 20);
    QINSERT(QUEUE, FRONT, REAR, 30);
    QINSERT(QUEUE, FRONT, REAR, 40);
    QINSERT(QUEUE, FRONT, REAR, 50);
    QINSERT(QUEUE, FRONT, REAR, 60);
    cout << "Queue contents: ";
    if (FRONT != 0) {
        int i = FRONT;
        while (true) {
            cout << QUEUE[i - 1] << " ";
            if (i == REAR) break;
            i = (i % N) + 1;
        }
    }
    cout << endl;
    return 0;
}