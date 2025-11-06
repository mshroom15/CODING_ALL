#include <bits/stdc++.h>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long long a,b;
        
        cin>>a>>b;
        if(a%2!=0){
            long long rem = b % 4;
            if (rem == 1) {
                a += b;
            } else if (rem == 2) {
                a -= 1;
            } else if (rem == 3) {
                a = a - b - 1;
            }
            cout << a << endl;
        }
        else{
            long long rem = b % 4;
            if (rem == 1) {
                a -= b;
            } else if (rem == 2) {
                a += 1;
            } else if (rem == 3) {
                a = a + b + 1;
            }
            cout << a << endl;
        }
    }
    return 0;
}
