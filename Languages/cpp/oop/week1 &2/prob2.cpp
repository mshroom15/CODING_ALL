#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
    public:
        int edge1;
        int edge2;
        int edge3;
        float area;
        Triangle(int a, int b, int c) {
            edge1 = a;
            edge2 = b;
            edge3 = c;
        }
        bool isvalid() {
            if (edge1 + edge2 > edge3 && edge1 + edge3 > edge2 && edge2 + edge3 > edge1) {
                calculatearea();
                return true;
            } else {
                area = 0;
                return false;
            }
        }
        void calculatearea(){
            float s=(edge1 + edge2 + edge3) / 2;
            area = sqrt(s*(s-edge1)*(s-edge2)*(s-edge3));
        }
        float getarea() {
            return area;
        }
};

int main() {
    Triangle triangle1(3, 4, 5);
    Triangle triangle2(5, 12, 13);
    Triangle triangle3(7, 24, 25);
    cout << "Triangle 1: " << (triangle1.isvalid() ? "Valid" : "Invalid") << endl;
    cout << "Triangle 2: " << (triangle2.isvalid() ? "Valid" : "Invalid") << endl;
    cout << "Triangle 3: " << (triangle3.isvalid() ? "Valid" : "Invalid") << endl;
    cout << "Area of Triangle 1: " << triangle1.getarea() << endl;
    cout << "Area of Triangle 2: " << triangle2.getarea() << endl;
    cout << "Area of Triangle 3: " << triangle3.getarea() << endl;
    

    return 0;
}