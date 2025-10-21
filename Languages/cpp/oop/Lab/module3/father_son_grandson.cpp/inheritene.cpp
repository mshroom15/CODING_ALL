#include <iostream>
using namespace std;
class Father {
private:
int money = 1000;
protected:
int gold = 500;
public:
int land = 300;
int getMoney() {
return money;
}
};
class Son : public Father {
public:
void showAccessFromSon() {
// cout << "Money: " << money << endl; //Not accessible
cout << "Gold (from Son): " << gold << endl; //Accessible
cout << "Land (from Son): " << land << endl; //Accessible
}
};
class GrandSon : public Son {
public:
void showAccessFromGrandSon() {
// cout << "Money: " << money << endl; //Not accessible
cout << "Gold (from GrandSon): " << gold << endl; //Accessible
cout << "Land (from GrandSon): " << land << endl; //Accessible
}
void displaySum() {
int total = getMoney() + gold + land;
cout << "Total (Money + Gold + Land): " << total << endl;
}
};
int main() {
Son s;
cout << "--- Access from Son ---" << endl;
s.showAccessFromSon();
GrandSon g;
cout << "--- Access from GrandSon ---" << endl;
g.showAccessFromGrandSon();
cout << "--- Sum Displayed in GrandSon ---" << endl;
g.displaySum();
return 0;
}
/*
Case 02:
#include <iostream>
using namespace std;
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
// cout << money << endl; // Not accessible
cout << "Gold (from Son): " << gold << endl; //Accessible
cout << "Land (from Son): " << land << endl; //Accessible
}
};
class GrandSon : public Son {
public:
void showAccessFromGrandSon() {
// cout << money << endl; // Not accessible
cout << "Gold (from GrandSon): " << gold << endl; // Accessible
// cout << "Land (from GrandSon): " << land << endl; // Not
accessible
}
void displaySum() {
int total = getMoney() + gold + 0; // land not accessible
cout << "Total (Money + Gold + Land): " << total << endl;
}
};
int main() {
cout << "--- Son and GrandSon Access Demonstration ---\n";
Son s;
// s.showAccessFromSon(); // Cannot access showAccessFromSon()
because Son inherited Father as protected
GrandSon g;
g.showAccessFromGrandSon();
g.displaySum();
return 0;
}
Case 03:
#include <iostream>
using namespace std;
class Father {
private:
int money = 1000;
protected:
int gold = 500;
public:
int land = 300;
int getMoney() { return money; }
};
class Son : private Father {
public:
int getGold() { return gold; }
int getLand() { return land; }
int getMoneyFromFather() { return getMoney(); }
void showAccessFromSon() {
// cout << money << endl; // Not accessible
cout << "Gold (from Son): " << gold << endl; // Accessible
cout << "Land (from Son): " << land << endl; // Accessible
}
};
class GrandSon : public Son {
public:
void showAccessFromGrandSon() {
// cout << gold << endl; // Not accessible directly
cout << "Gold (from GrandSon via getter): " << getGold() << endl;
cout << "Land (from GrandSon via getter): " << getLand() << endl;
}
void displaySum() {
int total = getMoneyFromFather() + getGold() + getLand();
cout << "Total (Money + Gold + Land): " << total << endl;
}
};
int main() {
cout << "--- Son and GrandSon Access Demonstration---\n";
Son s;
s.showAccessFromSon();
GrandSon g;
g.showAccessFromGrandSon();
g.displaySum();
return 0;
}
Case 04:
#include <iostream>
using namespace std;
class Father {
private:
int money = 1000;
protected:
int gold = 500;
public:
int land = 300;
int getMoney() { return money; }
};
class Son : public Father {
public:
void showAccessFromSon() {
// cout << money << endl; // Not accessible
cout << "Gold (from Son): " << gold << endl; // Accessible
cout << "Land (from Son): " << land << endl; // Accessible
}
};
class GrandSon : protected Son {
public:
void showAccessFromGrandSon() {
// cout << money << endl; // Not accessible
cout << "Gold (from GrandSon): " << gold << endl; // Accessible
cout << "Land (from GrandSon): " << land << endl; // Accessible
}
void displaySum() {
int total = getMoney() + gold + land;
cout << "Total (Money + Gold + Land): " << total << endl;
}
};
int main() {
cout << "--- Son and GrandSon Access Demonstration---\n";
Son s;
s.showAccessFromSon();
GrandSon g;
g.showAccessFromGrandSon();
g.displaySum();
return 0;
}
Case 05:
#include <iostream>
using namespace std;
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
// cout << money << endl; // Not accessible
cout << "Gold (from Son): " << gold << endl; // Accessible
cout << "Land (from Son): " << land << endl; // Accessible
}
};
class GrandSon : protected Son {
public:
void showAccessFromGrandSon() {
// cout << money << endl; // Not accessible
cout << "Gold (from GrandSon): " << gold << endl; //
Accessible (as protected)
// cout << land << endl; // Not accessible
}
void displaySum() {
int total = getMoney() + gold + 0; // land inaccessible
directly
cout << "Total (Money + Gold + Land): " << total << endl;
}
};
int main() {
cout << "--- Son and GrandSon Access Demonstration ---\n";
Son s;
// s.showAccessFromSon(); // Not accessible, Son is protectedly
inherited
GrandSon g;
g.showAccessFromGrandSon();
g.displaySum();
return 0;
}
Case 06:
#include <iostream>
using namespace std;
class Father {
private:
int money = 1000;
protected:
int gold = 500;
public:
int land = 300;
int getMoney() { return money; }
};
class Son : private Father {
public:
int getGold() { return gold; }
int getLand() { return land; }
int getMoneyFromFather() { return getMoney(); }
void showAccessFromSon() {
// cout << money << endl; // Not accessible
cout << "Gold (from Son): " << gold << endl; // Accessible
cout << "Land (from Son): " << land << endl; // Accessible
}
};
class GrandSon : protected Son {
public:
void showAccessFromGrandSon() {
// cout << gold << endl; // Not accessible directly
cout << "Gold (from GrandSon via getter): " << getGold() << endl;
cout << "Land (from GrandSon via getter): " << getLand() << endl;
}
void displaySum() {
int total = getMoneyFromFather() + getGold() + getLand();
cout << "Total (Money + Gold + Land): " << total << endl;
}
};
int main() {
cout << "--- Son and GrandSon Access Demonstration ---\n";
Son s;
s.showAccessFromSon();
GrandSon g;
g.showAccessFromGrandSon();
g.displaySum();
return 0;
}
Case 07:
#include <iostream>
using namespace std;
class Father {
private:
int money = 1000;
protected:
int gold = 500;
public:
int land = 300;
int getMoney() { return money; }
};
class Son : public Father {
public:
void showAccessFromSon() {
// cout << money << endl; //Not accessible
cout << "Gold (from Son): " << gold << endl; //Accessible
cout << "Land (from Son): " << land << endl; //Accessible
}
};
class GrandSon : private Son {
public:
void showAccessFromGrandSon() {
// cout << money << endl; //Not accessible
cout << "Gold (from GrandSon): " << gold << endl; //Accessible
cout << "Land (from GrandSon): " << land << endl; //Accessible
}
void displaySum() {
int total = getMoney() + gold + land;
cout << "Total (Money + Gold + Land): " << total << endl;
}
};
int main() {
cout << "--- Son and GrandSon Access Demonstration ---\n";
Son s;
s.showAccessFromSon();
GrandSon g;
g.showAccessFromGrandSon();
g.displaySum();
return 0;
}
Case 08:
#include <iostream>
using namespace std;
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
// cout << money << endl; //Not accessible
cout << "Gold (from Son): " << gold << endl; //Accessible
cout << "Land (from Son): " << land << endl; //Accessible
}
};
class GrandSon : private Son {
public:
void showAccessFromGrandSon() {
// cout << gold << endl; //Not directly accessible
cout << "Gold (from GrandSon): " << gold << endl; //Accessible
cout << "Land (from GrandSon): " << land << endl; //Accessible }
void displaySum() {
int total = getMoney() + gold + land;
cout << "Total (Money + Gold + Land): " << total << endl;
}
};
int main() {
cout << "--- Son and GrandSon Access Demonstration ---\n";
Son s;
s.showAccessFromSon();
GrandSon g;
g.showAccessFromGrandSon();
g.displaySum();
return 0;
}
Case 09:
#include <iostream>
using namespace std;
class Father {
private:
int money = 1000;
protected:
int gold = 500;
public:
int land = 300;
int getMoney() { return money; }
};
class Son : private Father {
public:
int getGold() { return gold; }
int getLand() { return land; }
int getMoneyFromFather() { return getMoney(); }
void showAccessFromSon() {
// cout << money << endl; // Not accessible
cout << "Gold (from Son): " << gold << endl; // Accessible
cout << "Land (from Son): " << land << endl; // Accessible
}
};
class GrandSon : private Son {
public:
void showAccessFromGrandSon() {
// cout << gold << endl; // Not accessible directly
cout << "Gold (from GrandSon via getter): " << getGold() <<
endl;
cout << "Land (from GrandSon via getter): " << getLand() <<
endl;
}
void displaySum() {
int total = getMoneyFromFather() + getGold() + getLand();
cout << "Total (Money + Gold + Land): " << total << endl;
}
};
int main() {
cout << "--- Son and GrandSon Access Demonstration ---\n";
Son s;
s.showAccessFromSon();
GrandSon g;
g.showAccessFromGrandSon();
g.displaySum();
return 0;
}
Case 10:
#include <iostream>
using namespace std;
class Father {
private:
int money = 1000;
protected:
int gold = 500;
public:
int land = 300;
int getMoney() { return money; }
};
class Son : private Father {
public:
int getGold() { return gold; }
int getLand() { return land; }
int getMoneyFromFather() { return getMoney(); }
void showAccessFromSon() {
// cout << money << endl; // Not accessible
cout << "Gold (from Son): " << gold << endl; // Accessible
cout << "Land (from Son): " << land << endl; // Accessible
}
};
class GrandSon : private Son {
public:
void showAccessFromGrandSon() {
// cout << gold << endl; // Not accessible directly
cout << "Gold (from GrandSon via getter): " << getGold() <<
endl;
cout << "Land (from GrandSon via getter): " << getLand() <<
endl;
}
void displaySum() {
int total = getMoneyFromFather() + getGold() + getLand();
cout << "Total (Money + Gold + Land): " << total << endl;
}
};
int main() {
cout << "--- Son and GrandSon Access Demonstration ---\n";
Son s;
s.showAccessFromSon();
GrandSon g;
g.showAccessFromGrandSon();
g.displaySum();
return 0;
}
*/