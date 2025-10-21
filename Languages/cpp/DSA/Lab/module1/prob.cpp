
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    int n = 40,sum=0;
    
    auto start = high_resolution_clock::now();

    for(int i=0; i<n; i++){
        cout << i << endl;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    
    cout << "Execution time: " << duration.count() << " nanoseconds" << endl;
    return 0;
}