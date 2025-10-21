#include <iostream>
using namespace std;
class A {
    private:
        int x;
    protected:
        int y;
    public:
        int z;
};
class B {
    private:
        int p;
    protected:
        int q;
    public:
        int r;
};
class C : public B,public A {
    public:
        void setValues(int a, int b, int c, int d = 0) {
            y = b; // Accessing protected member from A
            z = c; // Accessing public member from A
            q = a; // Accessing protected member from B
            r = d; // Accessing public member from B
        }
        
        void display() {
            cout << "y: " << y << ", z: " << z << endl; // Accessing protected and public members
            cout << "q: " << q << ", r: " << r << endl; // Accessing protected and public members from B
        }
};
int main() {
    C obj;
    obj.setValues(1, 2, 3,4);
    obj.display(); // Output: y: 2, z: 3
    return 0;
}