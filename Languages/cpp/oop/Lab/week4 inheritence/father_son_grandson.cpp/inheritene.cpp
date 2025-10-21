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
    
    int getMoney() {
        return money;
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
        cout << "Money (via getter): " << getMoney() << endl;  // Accessible via public method
    }
};

class GrandSon1 : public Son1 {
public:
    void accessMembers() {
        // money is not accessible (private in Father)
        // cout << "Money: " << money << endl;  // Error
        cout << "Gold: " << gold << endl;    // Accessible (protected in Father -> Son1)
        cout << "Land: " << land << endl;    // Accessible (public in Father -> Son1)
        cout << "Money (via getter): " << getMoney() << endl;  // Accessible via public method
        
        cout << "Sum: " << getMoney() + gold + land << endl;
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
        cout << "Money (via getter): " << getMoney() << endl;  // Accessible via public method
    }
};

class GrandSon2 : public Son2 {
public:
    void accessMembers() {
        // money is not accessible (private in Father)
        // cout << "Money: " << money << endl;  // Error
        cout << "Gold: " << gold << endl;    // Accessible (protected in Father -> Son2)
        cout << "Land: " << land << endl;    // Accessible (public in Father becomes protected in Son2)
        cout << "Money (via getter): " << getMoney() << endl;  // Accessible via public method
        
        cout << "Sum: " << getMoney() + gold + land << endl;
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
        cout << "Money (via getter): " << getMoney() << endl;  // Accessible via public method
    }
    
    // Expose methods to access inherited members
    int getSonLand() { return land; }
    int getSonGold() { return gold; }
    int getSonMoney() { return getMoney(); }
};

class GrandSon3 : public Son3 {
public:
    void accessMembers() {
        // All Father members are inaccessible directly because they became private in Son3
        // cout << "Gold: " << gold << endl;  // Error
        // cout << "Land: " << land << endl;  // Error
        // cout << "Money: " << getMoney() << endl;  // Error
        
        // But we can access them through Son3's public methods
        cout << "Gold (via Son): " << getSonGold() << endl;
        cout << "Land (via Son): " << getSonLand() << endl;
        cout << "Money (via Son): " << getSonMoney() << endl;
        
        cout << "Sum: " << getSonMoney() + getSonGold() + getSonLand() << endl;
    }
};

int main() {
    cout << "Inheritance Table Demonstration:" << endl;
    cout << "================================" << endl;
    
    cout << "\nCase 1: Son (public) -> GrandSon (public)" << endl;
    GrandSon1 gs1;
    gs1.accessMembers();
    
    cout << "\nCase 2: Son (protected) -> GrandSon (public)" << endl;
    GrandSon2 gs2;
    gs2.accessMembers();
    
    cout << "\nCase 3: Son (private) -> GrandSon (public)" << endl;
    GrandSon3 gs3;
    gs3.accessMembers();
    
    return 0;
}