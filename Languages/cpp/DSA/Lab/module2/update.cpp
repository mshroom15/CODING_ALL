#include <iostream>
using namespace std;
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    cout << "Array before update: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Enter the position of the element to update (0 to " << n - 1 << "): ";
    int pos;
    cin >> pos;
    if (pos < 0 || pos >= n) {
        cout << "Invalid position!" << endl;
        return 1;
    }
    cout << "Enter the new value: ";
    cin >> x;   
    arr[pos] = x; 
    
    cout << "Array after update: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}