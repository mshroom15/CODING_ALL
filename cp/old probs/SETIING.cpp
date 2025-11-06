#include <iostream>
#include <set>
using namespace std;

int main() {
    int arr[] = {4, 2, 5, 2, 4, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    set<int> s;

    for (int i = 0; i < n; i++) {
        s.insert(arr[i]);
    }

    for (int x : s) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}