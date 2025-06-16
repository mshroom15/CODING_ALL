#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
void inserionsort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            } else {
                break;
            }
        }
    }
}




int main() {
    auto start = high_resolution_clock::now();

    int n[40]={3, 24, 37, 56, 11, 1, 54, 17, 23, 8,34,56,23, 12, 45, 67, 89, 90, 11, 22, 33, 44, 55, 66, 77, 88, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112};
    inserionsort(n, 30);
    for (int i = 0; i < 30; i++) {
        cout << n[i] << " ";
    }
   

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    
    cout << "Execution time: " << duration.count() << " nanoseconds" << endl;
    return 0;
}