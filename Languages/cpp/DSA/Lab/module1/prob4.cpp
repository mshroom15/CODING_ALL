#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    int m=10;
    int n[m] = {3, 24, 37, 56, 11, 1, 54, 17, 23, 8};
    int loc=0, max = n[0];

    auto start = high_resolution_clock::now();

    for (int i = 0; i < m; i++) {
        if (n[i] > max) {
            max = n[i];
            loc = i;
        }
    }
    cout << "Maximum element is " << max << " at index " << loc << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Execution time: " << duration.count() << " microseconds" << endl;
    return 0;
}