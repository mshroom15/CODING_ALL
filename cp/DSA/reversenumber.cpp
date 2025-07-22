#include <bits/stdc++.h>
using namespace std;
int reverseNumber(int n) {
    int reversed = 0;
    while (n>0){
        int a=n%10;
        reversed=reversed*10+a;
        n/=10;
    }
    return reversed;
}
int main(){
    int num;
    cin>>num;
    cout<<reverseNumber(num);
}