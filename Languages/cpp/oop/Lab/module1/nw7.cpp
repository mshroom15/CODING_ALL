#include <iostream>

class A {
private:
	int a;
	int b;

public:
	A() : a(0), b(0) {}
	A(const A& other) : a(other.a), b(other.b) {
		std::cout << "Copy constructor called" << std::endl;
	}
	
	void SetData(int a_val, int b_val) {
		a = a_val;
		b = b_val;
	}
	
	void DisplayData() const {
		std::cout << "a = " << a << ", b = " << b << std::endl;
	}
};

int main() {
	A obj1;
	obj1.SetData(10, 20);
	std::cout << "Object 1 values: ";
	obj1.DisplayData();
	A obj2(obj1);
	std::cout << "Object 2 values: ";
	obj2.DisplayData();
	
	return 0;
}
