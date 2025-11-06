#include <bits/stdc++.h>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int tc=0;tc<t;tc++){
        long long a;
        bool found = false;
        
        cin>>a;
        for(long long i=1;i<=cbrt(a);i++){
            long long cube_i = i*i*i;
            long long j = 1;
            long long cube_j = 1;
            while(cube_i + cube_j <= a && j <= cbrt(a)){
                if(cube_i + cube_j == a){
                    found = true;
                    break;
                }
                j++;
                cube_j = j*j*j;
            }
            if(found) break;
        }
        if(found)
            cout<<"YES"<<endl;
        else 
            cout<<"NO"<<endl;
    }
    return 0;
}