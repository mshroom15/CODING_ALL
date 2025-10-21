#include <iostream>
#include <cmath>
using namespace std;

class Circle {
public:
    int radius;
    float area;
    Circle(int r) {
        radius = r;
        calculateArea();
    }
    void calculateArea() {
        area = M_PI * radius * radius;
    }
    float getArea() const {
        return area;
    }
};

int main() {
    Circle circle1(5);
    Circle circle2(7);
    Circle circle3(10);
    cout << "Area of Circle 1: " << circle1.getArea() << endl;
    cout << "Area of Circle 2: " << circle2.getArea() << endl;
    cout << "Area of Circle 3: " << circle3.getArea() << endl;
    float totalArea = circle1.getArea() + circle2.getArea() + circle3.getArea();
    cout << "Total area of all circles: " << totalArea << endl;

    return 0;
}