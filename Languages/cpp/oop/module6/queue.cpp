#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Queue {
private:
    vector<T> arr;
    int front_idx;
    int rear_idx;
    int size;
    
public:
    Queue() : front_idx(0), rear_idx(-1), size(0) {}
    
    void enqueue(T val) {
        arr.push_back(val);
        rear_idx++;
        size++;
    }
    
    T dequeue() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        T val = arr[front_idx];
        front_idx++;
        size--;
        
        if (isEmpty()) {
            arr.clear();
            front_idx = 0;
            rear_idx = -1;
        }
        
        return val;
    }
    
    T front() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return arr[front_idx];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    int getSize() {
        return size;
    }
};
int main(){
    Queue<int> q;
    while (true) {
        cout << "****** Queue Operations ******" << endl;
        int choice;
        cout << "1. Enqueue\n2. Dequeue\n3. Display Front\n4. Check if Empty\n5. Get Size\n0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter element to enqueue: ";
                cin >> data;
                q.enqueue(data);
                break;
            }
            case 2: {
                try {
                    cout << "Dequeued element: " << q.dequeue() << endl;
                } catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 3: {
                try {
                    cout << "Front element: " << q.front() << endl;
                } catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 4: {
                cout << (q.isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
                break;
            }
            case 5: {
                cout << "Queue size: " << q.getSize() << endl;
                break;
            }
            case 0:
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
    return 0;
}