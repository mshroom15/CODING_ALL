#include <iostream>

class Father {
private:
    int money = 1000;
protected:
    int gold = 500;
public:
    int land = 300;
    int getMoney() { return money; }
};

class Son : protected Father {
public:
    void showAccessFromSon() {
        // In Son, Father's 'public' and 'protected' members become 'protected'.
        std::cout << "Son can access Gold (now protected): " << gold << '\n';
        std::cout << "Son can access Land (now protected): " << land << '\n';
    }
};

class GrandSon : public Son {
public:
    void showAccessFromGrandSon() {
        // Son's protected members remain protected in GrandSon.
        std::cout << "GrandSon can access Gold: " << gold << '\n';
        std::cout << "GrandSon can access Land: " << land << '\n';
    }

    void displaySum() {
        long total = getMoney() + gold + land;
        std::cout << "Total assets for GrandSon: " << total << '\n';
    }
};

int main() {
    std::cout << "--- Access Demonstration ---\n";
    Son s;
    // s.showAccessFromSon(); // Error: Method is public, but an object of 'Son' cannot be used to access protected members of 'Father'.
    
    GrandSon g;
    g.showAccessFromGrandSon();
    g.displaySum();

    return 0;
}