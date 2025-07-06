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
class B : public A {
    public:
        void setValues(int a, int b, int c) {
            // x = a; // Error: x is private in class A
            y = b;   // OK: y is protected in class A
            z = c;   // OK: z is public in class A
        }
        
        void display() {
            cout << "y: " << y << ", z: " << z << endl;
        }
};
int main() {
    B obj;
    obj.setValues(1, 2, 3);
    obj.display(); // Output: y: 2, z: 3
    return 0;
}