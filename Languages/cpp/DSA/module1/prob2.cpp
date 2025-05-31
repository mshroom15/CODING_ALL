
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    int n = 10,sum=0;
    
    auto start = high_resolution_clock::now();

    for(int i=0; i<n; i++){
        sum += i;
    }
    cout << endl;
    for(int i=0; i<n; i++){
        sum += i;
    }


    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    cout << "Execution time: " << duration.count() << " microseconds" << endl;
    return 0;
}