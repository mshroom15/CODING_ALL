#include <iostream>

class A {
private: 
    int ax; 
public:
    A(int a = 0) : ax(a) {
        std::cout << "A constructor called" << std::endl;
    }
    
    int getAx() const {
        return ax;
    }
    
    ~A() {
        std::cout << "A destructor called" << std::endl;
    }
};

class B {
private: 
    int bx; 
public:
    B(int b = 0) : bx(b) {
        std::cout << "B constructor called" << std::endl;
    }
    
    int getBx() const {
        return bx;
    }
    
    ~B() {
        std::cout << "B destructor called" << std::endl;
    }
};

class C : public A, public B {
private:
    int cx; 
public:
    C(int a = 10, int b = 20, int c = 30) : A(a), B(b), cx(c) {
        std::cout << "C constructor called" << std::endl;
    }
    
    int sum() const {
        return getAx() + getBx() + cx;
    }
    
    ~C() {
        std::cout << "C destructor called" << std::endl;
    }
};

int main() {
    C c;
    std::cout << "Sum of ax, bx, and cx: " << c.sum() << std::endl;
    return 0;
}
