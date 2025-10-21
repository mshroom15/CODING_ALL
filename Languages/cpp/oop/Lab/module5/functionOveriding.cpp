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
    A* ptr = &b;
    a.print();
    b.print();
    ptr->print();
    return 0;
}