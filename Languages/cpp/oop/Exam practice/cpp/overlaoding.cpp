#include<bits/stdc++.h>
using namespace std;

class a{
    int abra;
    public :
    a(int cd):abra(cd){} 
    friend int operator+(class a, class b);

};
class b{
    int cobra;
    public:
    b(int fs):cobra(fs){}  
    friend int operator+(class a, class b);
};
int operator+(class a objA, class b objB){
    return objA.abra + objB.cobra;
}
 int main(){
    class a obja(10);
    class b objb(20);
    int result= obja + objb;
    cout<<result;


    
 }


