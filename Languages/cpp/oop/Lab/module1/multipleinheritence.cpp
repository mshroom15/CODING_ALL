#include <iostream>
using namespace std;
class A {
public:
    void display1() {
        cout << "Class A" << endl;
    }
};
class B {
public:
    void display2() {
        cout << "Class B" << endl;
    }
};
class C : public A, public B {
};
int main(){
     C class;
     class.display1();
     class.display2();
     return 0;

}