#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n; cin>>n;
    if(n==1){
        cout<<1<<" "<<1<<" "<<0<<endl;
        return 0;
    }
    long long l =1;
    long long h =n;
    long long k = n , s=0,b=0;
    while(l<=h){
        long long m = (l+h)/2;
        long long rem = n ;
        long long s1 = 0;
        long long b1 = 0;
        while(rem>0){
            long long take = min(m, rem);
            s1 += take;
            rem -= take;
            if(rem == 0) break;
            if(rem < 10) continue;;
            long long t = rem/10;
            b1+=t;
            rem-=t;
        }
        if(2*s1>=n){
            k = m;
            s = s1;
            b = b1;
            h = m-1;
        }
        else{
            l = m+1;
        }
    }
cout<<k<<" "<<s<<" "<<b<<endl;
    return 0;
}
