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

    int n[10]={3, 24, 37, 56, 11, 1, 54, 17, 23, 8};
    inserionsort(n, 10);
   

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    
    cout << "Execution time: " << duration.count() << " nanoseconds" << endl;
    return 0;
}