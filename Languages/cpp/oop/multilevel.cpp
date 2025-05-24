#include <iostream>
using namespace std;
class Animal {
public:
    void eat() {
        cout << "Animal is eating..." << endl;
    }
};
class Mammal : public Animal {
public:
    void breathe() {
        cout << "Mammal is breathing..." << endl;
    }
};
class Dog : public Mammal {
public:
    void bark() {
        cout << "Dog is barking..." << endl;
    }
};

int main() {
    Dog dog;

    dog.eat();     // From Animal class
    dog.breathe(); // From Mammal class
    dog.bark();    // From Dog class
    
    return 0;
}