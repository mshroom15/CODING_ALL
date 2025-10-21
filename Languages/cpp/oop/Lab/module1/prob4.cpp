#include <iostream>
using namespace std;
class Account{
    public:
    int acn;
    int amount;
    void setamount(int a){
        amount = a;
    }

};

createacn(){

}

int displayninput(){
        int option;
        cout<<"1. Create an acount"<<endl;
        cout<<"2. Deposit"<<endl;
        cout<<"3. Withdrawl"<<endl;
        cout<<"4. Transfer Money"<<endl;
        cout<<"5. Show Balance"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"   Enter you option:";
        cin>>option;
        return option;
}
int main(){
    int option;
    for(;;){
       option= displayninput();
       if(option==6)break;
       switch (option){
        case 1:
        createacn();
        break;
        case 2:
        deposit();

       }

}