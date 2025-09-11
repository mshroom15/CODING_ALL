#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Vector{
    private:
        T *arr;
        size_t capacity;
        size_t size;
    public:
        Vector(size_t cap = 10) : capacity(cap), size(0) {
            arr = new T[capacity];
        }
        ~Vector() {
            delete[] arr;
        }
        void push_back(T val) {
            if (size == capacity) {
                T *newArr = new T[capacity * 2];
                for (size_t i = 0; i < size; i++) {
                    newArr[i] = arr[i];
                }
                delete[] arr;
                arr = newArr;
                capacity *= 2;
            }
            arr[size++] = val;
        }
        void pop_back() {
            if (size > 0) {
                size--;
            } else {
                throw runtime_error("Vector is empty");
            }
        }
        T back() {
            if (size > 0) {
                return arr[size - 1];
            } else {
                throw runtime_error("Vector is empty");
            }
        }
        void push_front(T val) {
            if (size == capacity) {
                T *newArr = new T[capacity * 2];
                for (size_t i = 0; i < size; i++) {
                    newArr[i + 1] = arr[i];
                }
                delete[] arr;
                arr = newArr;
                capacity *= 2;
            } else {
                for (size_t i = size; i > 0; i--) {
                    arr[i] = arr[i - 1];
                }
            }
            arr[0] = val;
            size++;
        }
        void pop_front() {
            if (size > 0) {
                for (size_t i = 0; i < size - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                size--;
            } else {
                throw runtime_error("Vector is empty");
            }
        }
        T* Begin() {
            return arr;
        }
        T* End() {
            return arr + size;
        }
        void insert(size_t index, T val) {
            if (index > size) {
                throw out_of_range("Index out of range");
            }
            if (size == capacity) {
                T *newArr = new T[capacity * 2];
                for (size_t i = 0; i < index; i++) {
                    newArr[i] = arr[i];
                }
                newArr[index] = val;
                for (size_t i = index; i < size; i++) {
                    newArr[i + 1] = arr[i];
                }
                delete[] arr;
                arr = newArr;
                capacity *= 2;
            } else {
                for (size_t i = size; i > index; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[index] = val;
            }
            size++;
        }
        void erase(size_t index) {
            if (index >= size) {
                throw out_of_range("Index out of range");
            }
            for (size_t i = index; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
        }
};
int main(){
    Vector<int> v;
    while (true) {
        cout << "****** Vector Operations ******" << endl;
        int choice;
        cout << "1. Push Back\n2. Pop Back\n3. Display Back\n4. Push Front\n5. Pop Front\n6. Insert\n7. Erase\n0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter element to push back: ";
                cin >> data;
                v.push_back(data);
                break;
            }
            case 2: {
                try {
                    v.pop_back();
                } catch (const runtime_error &e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 3: {
                try {
                    cout << "Back element: " << v.back() << endl;
                } catch (const runtime_error &e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 4: {
                int data;
                cout << "Enter element to push front: ";
                cin >> data;
                v.push_front(data);
                break;
            }
            case 5: {
                try {
                    v.pop_front();
                } catch (const runtime_error &e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 6: {
                int index, data;
                cout << "Enter index and element to insert: ";
                cin >> index >> data;
                try {
                    v.insert(index, data);
                } catch (const out_of_range &e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 7: {
                int index;
                cout << "Enter index to erase: ";
                cin >> index;
                try {
                    v.erase(index);
                } catch (const out_of_range &e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 0:
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}