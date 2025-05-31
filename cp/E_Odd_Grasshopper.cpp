#include <bits/stdc++.h>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long long a,b;
        
        cin>>a>>b;

        for(int i=1;i<=b;i++){
            if(a%2==0){
                a-=i;}
                else a+=i;
        }
        cout<<a<<endl;
    }
    return 0;
}
