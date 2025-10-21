#include <iostream>
using namespace std;
#define N 5
int QUEUE[N];
int front = -1, rear = -1;
void QINSERT(int item) {
    if ((front == 0 && rear == N - 1) || (front == rear + 1)) {
        cout << "OVERFLOW" << endl;
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (rear == N - 1) {
        rear = 0;
    } else {
        rear++;
    }
    QUEUE[rear] = item;
}
void QDELETE() {
    if (front == -1) {
        cout << "UNDERFLOW" << endl;
        return;
    }
    int item = QUEUE[front];
    cout << "Deleted: " << item << endl;
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == N - 1) {
        front = 0;
    } else {
        front++;
    }
}
void displayQUEUE() {
    if (front == -1) {
        cout << "QUEUE is empty" << endl;
        return;
    }
    cout << "QUEUE elements: ";
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            cout << QUEUE[i] << " ";
    } else {
        for (int i = front; i < N; i++)
            cout << QUEUE[i] << " ";
        for (int i = 0; i <= rear; i++)
            cout << QUEUE[i] << " ";
    }
    cout << endl;
}
int main() {
    QINSERT(10);
    QINSERT(20);
    QINSERT(30);
    QINSERT(40);
    QINSERT(50);
    displayQUEUE();
    QDELETE();
    QDELETE();
    displayQUEUE();
    return 0;
}