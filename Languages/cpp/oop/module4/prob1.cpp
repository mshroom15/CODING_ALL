#include<bits/stdc++.h>
using namespace std;
class test {
    public:
    int Sum(int a) {
        return a ;
    }
    int Sum(int a, int b) {
        return a + b;
    }
float Sum(float a, float b) {
    return a + b;
}
float Sum(int a, float b) {
    return a + b;
}
float Sum(float a, int b) {
        return a + b;
    }
};
int main() {
    test t;
    cout << t.Sum(10) << endl;          // Calls Sum(int a)
    cout << t.Sum(10, 20) << endl;      // Calls Sum(int a, int b)
    cout << t.Sum(5.7f, 20) << endl; 
    cout << t.Sum(10, 2.6f) << endl;
    cout << t.Sum(10.5f, 20.7f) << endl; // Calls Sum(float a, float b)
    return 0;
}
//c++ treat 5.6 as double , so it cause amguity erorr either make functions using double of use f when passing float values
// or use (float)5.6 to make it float
