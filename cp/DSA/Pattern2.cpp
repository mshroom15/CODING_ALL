#include <bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    for(int i=a;i>=1;i--){
        for(int j=0;j<i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}