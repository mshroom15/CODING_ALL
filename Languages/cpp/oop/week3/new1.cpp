#include<iostream>
using namespace std;
class bank{
     int acn;
     float balance;
     static int total;
     public:
     bank(){
          acn=0;
          balance=0;
          total++;
     }
     bank(int a,float b){
          acn=a;
          balance=b;
          total++;
     }
     bank(const bank &other){ 
          acn = other.acn;
          balance = other.balance;
          total++;
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
     }
};
int bank::total=0; 
int main(){
     bank b1;
     cout<<"\nTotal Onject: "<<b1.gettotal()<<endl;
     b1.show();
     bank b2(1,1000);
     cout<<"\nTotal Onject: "<<b2.gettotal()<<endl;
     b2.show();
    bank b3 = b2; 
    cout<<"\nTotal Onject: "<<b3.gettotal()<<endl;
    b3.show();
    cout<<"\nTotal Onject: "<<bank::gettotal()<<endl;
    return 0;
    bank b[5];
    

}