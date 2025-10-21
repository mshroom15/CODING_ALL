#include <iostream>
using namespace std;
class A {
    private:
        int ax;
    public:
        
        A(int a = 0) : ax(a) {
            cout << "Constructor of class A called" << endl;
        }

        int getAx() const {
            return ax;
        }
        ~A() {
            cout << "Destructor of class A called" << endl;
        }
};
class B : public A {
    private:
        int bx;
    public:
        B(int a = 0, int b = 0) : A(a), bx(b) {
            cout << "Constructor of class B called" << endl;
        }
        int sum() const {
            
            return bx+getAx();
        }

        
    
};
int main() {
    B obj(34,45);
    cout << "Sum: " << obj.sum() << endl;


    
    return 0;
}