#include <iostream>
using namespace std;
int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Traversing the array using a for loop:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }   
    cout << endl;
    return 0;
}