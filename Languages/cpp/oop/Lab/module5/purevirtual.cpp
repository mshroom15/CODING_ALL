#include <iostream>
using namespace std;
class A {
public:
virtual void print()=0;
};
class B : public A {
public: 
void print() {
    cout << "B::print()" << endl;
}
};
int main() {
    B b;
    A* ptr = &b; 
    b.print();  
    ptr->print(); 
    return 0;
}