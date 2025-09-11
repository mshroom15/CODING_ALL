#include <iostream>
using namespace std;

class A
{
private:
    int x;

protected:
    int y;

public:
    int z;

    A() : x(10), y(20), z(30)
    {
        cout << "A constructor called" << endl;
    }

    int getX() const
    {
        return x;
    }

    void setX(int val)
    {
        x = val;
    }
};

class B : virtual public A
{
public:
    B()
    {
        cout << "B constructor called" << endl;
    }
};

class C : virtual public A
{
public:
    C()
    {
        cout << "C constructor called" << endl;
    }
};

class D : public B, public C
{
public:
    D()
    {
        cout << "D constructor called" << endl;
    }

    void accessX()
    {
        cout << "x = " << getX() << endl;
        setX(100);
        cout << "After modification, x = " << getX() << endl;
    }

    void accessY()
    {
        cout << "y = " << y << endl;
        y = 200;
        cout << "After modification, y = " << y << endl;
    }

    void accessZ()
    {
        cout << "z = " << z << endl;
        z = 300;
        cout << "After modification, z = " << z << endl;
    }
};
int main()
{
    D d;
    cout << "\nAccessing class A members through class D:" << endl;
    d.accessX();
    d.accessY();
    d.accessZ();
    return 0;
}