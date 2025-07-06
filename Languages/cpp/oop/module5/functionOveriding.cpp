#include <iostream>
using namespace std;
class A {
public:
virtual void print() {
    cout << "A::print()" << endl;
}
};
class B : public A {
public: 
void print() {
    cout << "B::print()" << endl;
}
};
int main() {
    A a;
    B b;
    A* ptr = &b; // Pointer of type A pointing to an object of type B
    a.print();   // Calls A's print
    b.print();   // Calls B's print
    ptr->print(); // Calls B's print due to polymorphism
    return 0;
}