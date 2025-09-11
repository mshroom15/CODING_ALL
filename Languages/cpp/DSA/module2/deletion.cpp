#include <iostream>
using namespace std;4
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int x;
    cout << "Enter the position of the element to delete: ";  
    cin >> x;
    if (x < 0 || x >= n) {
        cout << "Invalid position!" << endl;
        return 1;
    }
    for (int i = x; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }   
    n--; 
    cout << "Array after deletion: ";   
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    
    cout << endl;

    return 0;
}