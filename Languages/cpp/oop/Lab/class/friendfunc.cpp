#include <iostream>
using namespace std;
class sonali; // Forward declaration
class  Rupali
{
    int balance;
    Rupali(int b) : balance(b) {}
    friend void sum(Rupali r, sonali);

};
class  sonali
{
    int balance;
    sonali(int b) : balance(b) {}
    friend void sum(Rupali, sonali);

};

void sum



main