#include <iostream>
using namespace std;
class c {
    int speed;
    public:
    c(int s) {
        speed = s;
    }
    void operator++() {
        speed+=5;
    }
    void operator--() {
        speed-=3; // This will cause an error since s is private
    }
    int getS() const {
        return speed;
    }
};
int main() {
    c cx(10); // Creating an object of class c
    cout << "Object created with value: " << cx.getS() << endl; 
    ++cx;
    --cx;
    return 0;
}