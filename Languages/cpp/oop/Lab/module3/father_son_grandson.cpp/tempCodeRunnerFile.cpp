#include <iostream>
using namespace std;

class Father {
private:
    int money;
protected:
    int gold;
public:
    int land;
    
    Father() {
        money = 1000;
        gold = 100;
        land = 10;
    }
};

// Case 1: public inheritance
class Son1 : public Father {
public:
    void accessMembers() {
        // money is not accessible (private in Father)
        // cout << "Money: " << money << endl;  // Error
        cout << "Gold: " << gold << endl;    // Accessible (protected in Father)
        cout << "Land: " << land << endl;    // Accessible (public in Father)
    }
};

class GrandSon1 : public Son1 {
public:
    void accessMembers() {
        // money is not accessible (private in Father)
        // cout << "Money: " << money << endl;  // Error
        cout << "Gold: " << gold << endl;    // Accessible (protected in Father -> Son1)
        cout << "Land: " << land << endl;    // Accessible (public in Father -> Son1)
        
        cout << "Sum of accessible members: " << gold + land << endl;
    }
};

// Case 2: protected inheritance
class Son2 : protected Father {
public:
    void accessMembers() {
        // money is not accessible (private in Father)
        // cout << "Money: " << money << endl;  // Error
        cout << "Gold: " << gold << endl;    // Accessible (protected in Father)
        cout << "Land: " << land << endl;    // Accessible (public in Father becomes protected in Son)
    }
};

class GrandSon2 : public Son2 {
public:
    void accessMembers() {
        // money is not accessible (private in Father)
        // cout << "Money: " << money << endl;  // Error
        cout << "Gold: " << gold << endl;    // Accessible (protected in Father -> Son2)
        cout << "Land: " << land << endl;    // Accessible (public in Father becomes protected in Son2)
        
        cout << "Sum of accessible members: " << gold + land << endl;
    }
};

// Case 3: private inheritance
class Son3 : private Father {
public:
    void accessMembers() {
        // money is not accessible (private in Father)
        // cout << "Money: " << money << endl;  // Error
        cout << "Gold: " << gold << endl;    // Accessible (protected in Father)
        cout << "Land: " << land << endl;    // Accessible (public in Father becomes private in Son)
    }
};

class GrandSon3 : public Son3 {
public:
    void accessMembers() {
        // All Father members are inaccessible directly because they became private in Son3
        // cout << "Gold: " << gold << endl;  // Error
        // cout << "Land: " << land << endl;  // Error
        // cout << "Money: " << money << endl; // Error
        cout << "No members from Father are accessible in GrandSon3." << endl;
    }
};

int main() {
    cout << "Inheritance Table Demonstration:" << endl;
    cout << "================================" << endl;
    
    cout << "\nCase 1: Son (public) -> GrandSon (public)" << endl;
    GrandSon1 gs1;
    gs1.accessMembers();
    // Outside the class, only public members are accessible
    cout << "Land (from outside): " << gs1.land << endl;
    
    cout << "\nCase 2: Son (protected) -> GrandSon (public)" << endl;
    GrandSon2 gs2;
    gs2.accessMembers();
    // Outside the class, nothing is accessible as public members of Father became protected in Son2
    // cout << "Land (from outside): " << gs2.land << endl; // Error
    
    cout << "\nCase 3: Son (private) -> GrandSon (public)" << endl;
    GrandSon3 gs3;
    gs3.accessMembers();
    // Outside the class, nothing is accessible as all members of Father became private in Son3
    // cout << "Land (from outside): " << gs3.land << endl; // Error
    
    return 0;
}