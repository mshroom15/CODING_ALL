#include <bits/stdc++.h>
using namespace std;
int printsum(int n){
    if(n<1){
        return 1;
    }
    return n*printsum(n-1);

}
int main(){
    int n=3;
    int sum=0;
    sum = printsum(n);
    cout<<sum;
    return 0;
}