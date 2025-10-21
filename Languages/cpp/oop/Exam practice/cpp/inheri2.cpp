#include<bits/stdc++.h>
using namespace std;
class base{
    public:
   
     base(){
        cout<< "B1";
        
    }
    virtual void show(){
        cout <<"Base";
    }
    ~base(){
        cout<<"-B";
    
    }

};
class derived: public 