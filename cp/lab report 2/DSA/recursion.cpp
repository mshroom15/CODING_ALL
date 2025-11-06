#include <bits/stdc++.h>
using namespace std;
void printsum(int n, int sum=0){
    if(n<1){
        cout<<sum;
        return;
    }
    sum+=n;
    printsum(n-1,sum);

}
int main(){
    int n=3;
    int sum=0;
    printsum(n,sum);
    return 0;
}