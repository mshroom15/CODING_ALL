#include<iostream>
using namespace std;
class bank1;
class bank2;
void Sum(bank1 &b1, bank2 &b2);

class bank1{
    private:
        int balance;
    public:
        bank1(int b = 0) : balance(b) {}
        friend void Sum(bank1 &b1, bank2 &b2);
};
class bank2{
    private:
        int balance;
    public:
        bank2(int b = 0) : balance(b) {}
        friend void Sum(bank1 &b1, bank2 &b2);
};
void Sum(bank1 &b1, bank2 &b2) {
    cout << "Total balance: " << b1.balance + b2.balance << endl;
}
int main() {
    bank1 b1(2000);
    bank2 b2(4000);
    Sum(b1, b2); 
    return 0;
}