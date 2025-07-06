#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
    int a ,b;
    cin>>a>>b;
    vector<int> c(a);
    for(int i=0;i<a;i++){
        cin>>c[i];
    }
    sort(c.begin(),c.end());
    int l=0,u=a-1,t=0;
    while(!(u<=l)){
        if(c[l]+c[u]>b){
            u--;
            t++;
        }
        else if(c[l]+c[u]<b){
            u--;
            l++;
            t++;
        }
        else {
            u--;
            l++;
            t++;
        }
    }
    if(u==l){
        t++;
    }
    cout<<t<<endl;
    return 0;

}