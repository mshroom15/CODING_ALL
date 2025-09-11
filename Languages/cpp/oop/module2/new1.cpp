#include<iostream>
using namespace std;
class bank{
     int acn;
     float balance;
     static int total;
     static int maxacn;
     static float maxbalance;
     public:
     bank(){
          acn=0;
          balance=0;
          total++;
          updateMax();
     }
     bank(int a,float b){
          acn=a;
          balance=b;
          total++;
          updateMax();
     }
     bank(const bank &other){ 
          acn = other.acn;
          balance = other.balance;
          total++;
          updateMax();
     }
     static int gettotal(){
          return total;
     }
     void show(){
          cout<<"Acc No: "<<acn<<"\nBalalnce: "<<balance<<endl;
     }
    void showdata() const {
        cout << "Acc No: " << acn << "\nBalalnce: " << balance << endl;
    }
     void setdata(int a,float b){
          balance=b;
          acn=a;
          updateMax();
     }
     void updateMax(){
          if(balance > maxbalance){
               maxbalance = balance;
               maxacn = acn;
          }
     }
     static void showHighestBalance(){
          cout << "Account with highest balance: " << maxacn 
               << " with balance: " << maxbalance << endl;
     }
};
int bank::total=0;
int bank::maxacn=0;
float bank::maxbalance=0.0;
int main(){
     bank b1;
     cout<<"\nTotal Onject: "<<b1.gettotal()<<endl;
     b1.show();
     bank b2(1,500);
     cout<<"\nTotal Onject: "<<b2.gettotal()<<endl;
     b2.show();
    bank b3 = b2; 
    cout<<"\nTotal Onject: "<<b3.gettotal()<<endl;
    b3.show();
    cout<<"\nTotal Onject: "<<bank::gettotal()<<endl;
    bank b[5];
    bank::showHighestBalance();
    
    return 0;
}

