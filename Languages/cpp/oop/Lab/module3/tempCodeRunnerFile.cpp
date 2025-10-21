#include <iostream>

class A {
private: 
    int ax; 
public: 
    A(int a = 0) : ax(a) {
        std::cout << "A constructor called" << std::endl;
    }
    ~A() {
        std::cout << "A destructor called" << std::endl;
    }
    int getAx() const {
        return ax;
    }
};

class B : public A {
private: 
    int bx; 
public:
    B(int a = 0, int b = 0) : A(a), bx(b) {
        std::cout << "B constructor called" << std::endl;
    }
    ~B() {
        std::cout << "B destructor called" << std::endl;
    }
    int getBx() const {
        return bx;
    }
};

class C : public B {
private: 
    int cx; 
public:
    C(int a = 10, int b = 20, int c = 30) : B(a, b), cx(c) {
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
    C c(1, 2, 3);
    std::cout << "Sum of ax, bx, cx: " << c.sum() << std::endl;
    
    return 0;
}