#include <bits/stdc++.h>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int a,b;
        cin>>a>>b;
        if(a!=b){
            if(abs(a-b)%10==0)
            cout<<(abs(a-b)/10);
            else cout<<(abs(a-b)/10)+1;
        }else cout<<0;
        cout<<endl;
    }
    return 0;
}
