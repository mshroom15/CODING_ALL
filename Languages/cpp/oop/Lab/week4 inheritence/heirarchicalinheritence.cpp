#include <iostream>

class A {
private:
    int x;
protected:
    int y;
public:
    int z;
    
    // Constructor to initialize values
    A() : x(10), y(20), z(30) {}
    
    // Getter for private member x
    int getX() const {
        return x;
    }
    
    // Setter for private member x
    void setX(int val) {
        x = val;
    }
};

class B : public A {
public:
    // Method to access x, y, and z
    void displayB() {
        // Cannot directly access x as it's private in A
        // Can access y as it's protected in A
        // Can access z as it's public in A
        std::cout << "Class B:" << std::endl;
        std::cout << "x (using getter): " << getX() << std::endl;
        std::cout << "y: " << y << std::endl;
        std::cout << "z: " << z << std::endl;
    }
    
    // Method to modify values
    void modifyB(int newX, int newY, int newZ) {
        setX(newX);  // Using inherited setter for x
        y = newY;    // Direct access to protected member
        z = newZ;    // Direct access to public member
    }
};

class C : public A {
public:
    // Method to access x, y, and z
    void displayC() {
        // Cannot directly access x as it's private in A
        // Can access y as it's protected in A
        // Can access z as it's public in A
        std::cout << "Class C:" << std::endl;
        std::cout << "x (using getter): " << getX() << std::endl;
        std::cout << "y: " << y << std::endl;
        std::cout << "z: " << z << std::endl;
    }
    
    // Method to modify values
    void modifyC(int newX, int newY, int newZ) {
        setX(newX);  // Using inherited setter for x
        y = newY;    // Direct access to protected member
        z = newZ;    // Direct access to public member
    }
};

int main() {
    B b;
    C c;
    
    // Call methods of class B
    std::cout << "Initial values:" << std::endl;
    b.displayB();
    
    // Call methods of class C
    c.displayC();
    
    // Modify values and display again
    std::cout << "\nAfter modification:" << std::endl;
    b.modifyB(100, 200, 300);
    c.modifyC(400, 500, 600);
    
    b.displayB();
    c.displayC();
    
    return 0;
}