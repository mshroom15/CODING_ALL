#include <iostream>
using namespace std;

// Base class A
class A {
private:
    int x;
protected:
    int y;
public:
    int z;
    
    A() : x(10), y(20), z(30) {
        cout << "A constructor called" << endl;
    }
    
    // Getter for private member x
    int getX() const {
        return x;
    }
    
    // Setter for private member x
    void setX(int val) {
        x = val;
    }
};

// Derived class B - use virtual to solve diamond problem
class B : virtual public A {
public:
    B() {
        cout << "B constructor called" << endl;
    }
};

// Derived class C - use virtual to solve diamond problem
class C : virtual public A {
public:
    C() {
        cout << "C constructor called" << endl;
    }
};

// Class D inherits from both B and C
class D : public B, public C {
public:
    D() {
        cout << "D constructor called" << endl;
    }
    
    // Method to access x (private in A)
    void accessX() {
        // Access x using public getter from A
        cout << "x = " << getX() << endl;
        // Can modify x using setter
        setX(100);
        cout << "After modification, x = " << getX() << endl;
    }
    
    // Method to access y (protected in A)
    void accessY() {
        cout << "y = " << y << endl;
        // Can directly modify y since it's protected
        y = 200;
        cout << "After modification, y = " << y << endl;
    }
    
    // Method to access z (public in A)
    void accessZ() {
        cout << "z = " << z << endl;
        // Can directly modify z since it's public
        z = 300;
        cout << "After modification, z = " << z << endl;
    }
};

int main() {
    D d;
    
    // Call methods of class D
    cout << "\nAccessing class A members through class D:" << endl;
    d.accessX();
    d.accessY();
    d.accessZ();
    
    return 0;
}