#include <bits/stdc++.h>
using namespace std;
template <typename T>
class MyStack{
private:
    vector<T> v;
public:
    MyStack() {}
    void push(T data) {
        v.push_back(data);
    }
    void pop(){
        if(!v.empty()) {
            v.pop_back();
        } else {
            cout << "Stack is empty, cannot pop." << endl;
        }
    
    }
    T top() {
        if(!v.empty()) {
            return v.back();
        } else {
            cout << "Stack is empty, no top element." << endl;
            return T();
        }
    }
    bool empty() {
        return v.empty();
    }
    void display() {
        if(v.empty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for(int i = v.size() - 1; i >= 0; i--) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    MyStack<int> s;
    while(true){
        cout << "****** Stack Operations ******" << endl;
        int choice;
        cout << "1. Push\n2. Pop\n3. Display\n4. Top\n5. Check if empty\n0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1: {
                int data;
                cout << "Enter element to push: ";
                cin >> data;
                s.push(data);
                break;
            }
            case 2: {
                s.pop();
                break;
            }
            case 3: {
                s.display();
                break;
            }
            case 4: {
                int topElement = s.top();
                if(!s.empty()) {
                    cout << "Top element: " << topElement << endl;
                }
                break;
            }
            case 5: {
                if(s.empty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;
            }
            case 0:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
    return 0;
}