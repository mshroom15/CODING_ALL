#include<iostream>
using namespace std;

class Account{
	public:
	int acn;
	float balance;
	void SetData(int n,float b){
		acn=n;
		balance=b;
	}
	float showbalance(){
		return balance;
	}
	void setbalance(float b){
		balance+=b;
		cout<<"New balance= "<<balance<<endl;
	}
	void send(float b){
		balance-=b;
		cout<<"Transfer Successful."<<endl;
		cout<<"New Balance: "<<balance<<endl;
	}
	void take(float b){
		balance+=b;
	}
	void withdraw(float b){
		balance-=b;
		cout<<"Withdraw Succesful.New balance: "<<balance<<endl;
	}

};
Account b[1000];
int Total=0;
void Create(){
	float x;
	cout<<"Your New Account Number: "<<Total+1<<endl;
	cout<<"Enter your new balance: ";
	cin>>x;
	cout<<endl;
	b[Total].SetData(Total+1,x);
	Total++;
	cout<<"New Account is created successfully.\n";
}
void show(){
	int x;
	float y;
	cout<<"Enter your Account Number: "<<endl;
	cin>>x;
	y=b[x-1].showbalance();
	cout<<"Your balance= "<<y<<endl;

}
void deposit(){
	int x;
	float y;
	cout<<"Enter your Account Number: "<<endl;
	cin>>x;
	cout<<"Enter Amount to deposit: "<<endl;
	cin>>y;
	b[x-1].setbalance(y);
	cout<<"Deposit Successful\n";

}
void withdrawl(){
	int x;
	float z;
	cout<<"Enter your Account Number: "<<endl;
	cin>>x;
	cout<<"Enter amount to withdraw: "<<endl;
	cin>>z;
	b[x-1].withdraw(z);
}
void transfer(){
	int x,y;
	float z;
	cout<<"Enter your Account Number: "<<endl;
	cin>>x;
	cout<<"Enter the Account Number u want to be transferred: "<<endl;
	cin>>y;
	cout<<"Enter Amount: "<<endl;
	cin>>z;
	b[x-1].send (z);
	b[y-1].take(z);
}

int main(){
	int i,option;
	for(;;){
		cout<<"<--Main Menu-->"<<endl;
		cout<<"1.New Account"<<endl;
		cout<<"2.Deposit"<<endl;
		cout<<"3.Withdrawal"<<endl;
		cout<<"4.Transfer Money"<<endl;
		cout<<"5.Show Balance"<<endl;
		cout<<"6.Exit"<<endl;
		cout<<"\nEnter your option: "<<endl;
		cin>>option;
		cout<<endl;
		if(option==6) break;
		switch(option){
			case 1:Create(); break;
			case 2:deposit(); break;
			case 3:withdrawl();break;
			case 4:transfer();break;
			case 5: show();break;
		}
	}
	return 0;
}