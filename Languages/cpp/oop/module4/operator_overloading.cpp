#include <iostream>
using namespace std;

class Circuit {
private:
    int real;
    int img;
public:

    Circuit(int r = 0, int i = 0) : real(r), img(i) {}
    
    Circuit operator+(const Circuit& c) const {
        return Circuit(real + c.real, img + c.img);
    }
    
    Circuit operator-(const Circuit& c) const {
        return Circuit(real - c.real, img - c.img);
    }
 
    Circuit operator*(const Circuit& c) const {
        return Circuit(real * c.real - img * c.img, real * c.img + img * c.real);
    }
    
    Circuit operator/(const Circuit& c) const {
        int denominator = c.real * c.real + c.img * c.img;
        return Circuit((real * c.real + img * c.img) / denominator,
                      (img * c.real - real * c.img) / denominator);
    }
    
    void display() const {
        cout << real;
        if (img >= 0) {
            cout << "+j" << img;
        } else {
            cout << "-j" << -img;
        }
    }
    Circuit reciprocal() const {
        int denominator = real * real + img * img;
        return Circuit(real / denominator, -img / denominator);
    }
    
    int getReal() const { return real; }
    int getImg() const { return img; }
};

int main() {
    Circuit z1(3, 4);
    Circuit z2(4, -3);
    Circuit z3(0, 6);
    
    cout << "Impedance z1 = ";
    z1.display();
    cout << endl;
    
    cout << "Impedance z2 = ";
    z2.display();
    cout << endl;
    
    cout << "Impedance z3 = ";
    z3.display();
    cout << endl;
    
    
    Circuit sum_reciprocals = z1.reciprocal() + z2.reciprocal() + z3.reciprocal();
    Circuit z_equivalent = sum_reciprocals.reciprocal();
    
    cout << "Equivalent impedance = ";
    z_equivalent.display();
    cout << endl;
    
    Circuit voltage(100, 50);
    cout << "Input voltage = ";
    voltage.display();
    cout << endl;
    
    Circuit current = voltage / z_equivalent;
    cout << "Current = ";
    current.display();
    cout << endl;
    
    return 0;
}