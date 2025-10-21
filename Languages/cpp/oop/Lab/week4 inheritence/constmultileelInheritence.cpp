#include <iostream>

class A {
private: 
    int ax; 
public: 
    // Constructor to initialize ax
    A(int a = 0) : ax(a) {
        std::cout << "A constructor called" << std::endl;
    }
    
    // Destructor
    ~A() {
        std::cout << "A destructor called" << std::endl;
    }
    
    // Getter for ax (needed for sum in class C)
    int getAx() const {
        return ax;
    }
};

class B : public A {
private: 
    int bx; 
public: 
    // Constructor to initialize bx
    B(int a = 0, int b = 0) : A(a), bx(b) {
        std::cout << "B constructor called" << std::endl;
    }
    
    // Destructor
    ~B() {
        std::cout << "B destructor called" << std::endl;
    }
    
    // Getter for bx (needed for sum in class C)
    int getBx() const {
        return bx;
    }
};

class C : public B {
private: 
    int cx; 
public:
    // Constructor to initialize cx
    C(int a = 10, int b = 20, int c = 30) : B(a, b), cx(c) {
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
    C c(1, 2, 3);
    
    // Call method of class C
    std::cout << "Sum of ax, bx, cx: " << c.sum() << std::endl;
    
    return 0;
}