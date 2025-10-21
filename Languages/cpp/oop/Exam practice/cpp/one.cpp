#include <iostream>
using namespace std;

// Base class
class Animal {
protected:
    string name;
public:
    Animal(string n) : name(n) {
        cout << "Animal constructor called\n";
    }
    
    void eat() {
        cout << name << " is eating\n";
    }
};

// Intermediate classes using virtual inheritance
class Mammal : virtual public Animal {
public:
    Mammal(string n) : Animal(n) {
        cout << "Mammal constructor called\n";
    }
};

class WingedAnimal : virtual public Animal {
public:
    WingedAnimal(string n) : Animal(n) {
        cout << "WingedAnimal constructor called\n";
    }
};

// Derived class - Diamond problem solved
class Bat : public Mammal, public WingedAnimal {
public:
    Bat(string n) : Animal(n), Mammal(n), WingedAnimal(n) {
        cout << "Bat constructor called\n";
    }
    
    void display() {
        cout << "I am a " << name << "\n";
        eat(); // No ambiguity due to virtual inheritance
    }
};

int main() {
    cout << "Creating Bat object:\n";
    Bat bat("Bat");
    bat.display();
    
    return 0;
}