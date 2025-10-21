#include<bits/stdc++.h>
using namespace std;
class base{
    int prv = 10;
    int newvar;
    public:
     base(int a):newvar(a){}
     base(): base(0){}
     
    int get(){
        return prv;
    }
    void set(int p){
        prv = p;
    }
    int add(int a);
    friend int dosomething(base a, base2 b);
    ~base(){
        cout<<"destroyed"<<"\n";
    }

};
int base::add(int a){
    return prv + a;
}
class base2{
    


};