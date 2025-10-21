#include <iostream>
using namespace std;

class ArrayLinkedList {
private:
    static const int MAX_SIZE = 100;
    int data[MAX_SIZE];     // Array to store data values
    int next[MAX_SIZE];     // Array to store next indices (-1 means NULL)
    int head;               // Index of head node
    int freeIndex;          // Next available index
    
public:
    ArrayLinkedList() {
        head = -1;
        freeIndex = 0;
        
        // Initialize next array to create free list
        for (int i = 0; i < MAX_SIZE - 1; i++) {
            next[i] = i + 1;
        }
        next[MAX_SIZE - 1] = -1;
    }
    
    // Insert at beginning
    void insertAtBeginning(int value) {
        if (freeIndex == -1) {
            cout << "List is full!" << endl;
            return;
        }
        
        int newIndex = freeIndex;
        freeIndex = next[freeIndex];
        
        data[newIndex] = value;
        next[newIndex] = head;
        head = newIndex;
    }
    
    // Insert at end
    void insertAtEnd(int value) {
        if (freeIndex == -1) {
            cout << "List is full!" << endl;
            return;
        }
        
        int newIndex = freeIndex;
        freeIndex = next[freeIndex];
        
        data[newIndex] = value;
        next[newIndex] = -1;
        
        if (head == -1) {
            head = newIndex;
            return;
        }
        
        int temp = head;
        while (next[temp] != -1) {
            temp = next[temp];
        }
        next[temp] = newIndex;
    }
    
    // Display the list
    void display() {
        int temp = head;
        while (temp != -1) {
            cout << data[temp] << " -> ";
            temp = next[temp];
        }
        cout << "NULL" << endl;
    }
    
    // Delete a node
    void deleteNode(int value) {
        if (head == -1) return;
        
        if (data[head] == value) {
            int temp = head;
            head = next[head];
            next[temp] = freeIndex;
            freeIndex = temp;
            return;
        }
        
        int current = head;
        while (next[current] != -1 && data[next[current]] != value) {
            current = next[current];
        }
        
        if (next[current] != -1) {
            int temp = next[current];
            next[current] = next[next[current]];
            next[temp] = freeIndex;
            freeIndex = temp;
        }
    }
};

int main() {
    ArrayLinkedList list;
    
    // Adding elements
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtBeginning(5);
    
    cout << "Array-based Linked List: ";
    list.display();
    
    // Delete an element
    list.deleteNode(20);
    cout << "After deleting 20: ";
    list.display();
    
    return 0;
}

/*
EXPLANATION:
- data[]: stores the actual values
- next[]: stores the index of the next node (not pointers, but array indices)
- This simulates pointers using array indices
- -1 represents NULL
- Free list management for memory reuse
*/
