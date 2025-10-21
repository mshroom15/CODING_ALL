#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    int n[10] = {3, 24, 37, 56, 11, 1, 54, 17, 23, 8};
    int loc=-1, x=23;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < 10; i++) {
        if (x == n[i]) {
            loc = i;
            break;
        }
    }
    if (loc == -1) {
        cout << "Element " << x << " not found in the array " << endl;
    } else {
        cout << "Element " << x << " found at index" <<loc<< endl;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Execution time: " << duration.count() << " microseconds" << endl;
    return 0;
}
