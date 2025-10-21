#include<bits/stdc++.h>
using namespace std;
// Multiple Inheritance Example
class Mother {
protected:
    int jewelry;
public:
    string motherName;
    Mother() { jewelry = 50; motherName = "Mary"; }
    void showMother() { cout << "Mother's jewelry: " << jewelry << endl; }
};

class Child : public Father, public Mother {
public:
    void showAllInheritance() {
        cout << "From Father - Land: " << land << endl;
        cout << "From Father - Gold: " << gold << endl;
        cout << "From Mother - Name: " << motherName << endl;
        cout << "From Mother - Jewelry: " << jewelry << endl;
    }
};

// Hybrid Inheritance Example
class GrandParent {
protected:
    int house;
public:
    GrandParent() { house = 1; }
    void showHouse() { cout << "Houses: " << house << endl; }
};

class Parent1 : public GrandParent {
protected:
    int car;
public:
    Parent1() { car = 2; }
};

class Parent2 : public GrandParent {
protected:
    int business;
public:
    Parent2() { business = 1; }
};

class GrandChild : public Parent1, public Parent2 {
public:
    void showAllAssets() {
        cout << "Cars from Parent1: " << car << endl;
        cout << "Business from Parent2: " << business << endl;
        // Note: house is ambiguous due to diamond problem
        cout << "Houses from Parent1: " << Parent1::house << endl;
        cout << "Houses from Parent2: " << Parent2::house << endl;
    }
};
class Father {
private:
int money ;
protected:
int gold ;    
public:
int land ;
int getMoney() { return money; }
void showAccessFromFather() {
    cout << "Gold (from Father): " << gold << endl;
    cout << "Land (from Father): " << land << endl; }

};
class Son : public Father {
public:
void showAccessFromSon() {
    cout << "Gold (from Son): " << gold << endl; // Accessible
    cout << "Land (from Son): " << land << endl; // Accessible
    cout << "Money (from Son): " << getMoney() << endl; // Accessible
}
};
