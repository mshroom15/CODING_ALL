#include<iostream>
using namespace std;
class bank{
	  int acn;
	  float balance;
	  static int total;
	  static int maxAcn; 
	  static float maxBalance; 
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
		   if(balance > maxBalance){
				  maxBalance = balance;
				  maxAcn = acn;
		   }
	  }
	  static void showHighestBalance(){
		   cout << "Account with highest balance: " << maxAcn 
				 << " with balance: " << maxBalance << endl;
	  }
};
int bank::total=0;
int bank::maxAcn=0;
float bank::maxBalance=0.0;
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
	bank b[5];
	bank::showHighestBalance();
	
	return 0;
}