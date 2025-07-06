#include <iostream>

class A {
private: 
    int ax; 
public:
    // Constructor to initialize ax
    A(int a = 0) : ax(a) {
        std::cout << "A constructor called" << std::endl;
    }
    
    // Getter for ax (needed for sum method in class C)
    int getAx() const {
        return ax;
    }
    
    // Destructor
    ~A() {
        std::cout << "A destructor called" << std::endl;
    }
};

class B {
private: 
    int bx; 
public:
    // Constructor to initialize bx
    B(int b = 0) : bx(b) {
        std::cout << "B constructor called" << std::endl;
    }
    
    // Getter for bx (needed for sum method in class C)
    int getBx() const {
        return bx;
    }
    
    // Destructor
    ~B() {
        std::cout << "B destructor called" << std::endl;
    }
};

class C : public A, public B {
private:
    int cx; 
public:
    // Constructor to initialize cx and call parent constructors
    C(int a = 10, int b = 20, int c = 30) : A(a), B(b), cx(c) {
        std::cout << "C constructor called" << std::endl;
    }
    
    // Method to sum ax, bx and cx
    int sum() const {
        return getAx() + getBx() + cx;
    }
    
    // Destructor
    ~C() {
        std::cout << "C destructor called" << std::endl;
    }
};

int main() {
    C c;
    
    // Call the sum method of class C
    std::cout << "Sum of ax, bx, and cx: " << c.sum() << std::endl;
    
    return 0;
}