#include<iostream>
using namespace std;
int gcd_recursive(int a, int b) {
    if(a>b)
    swap(a,b);
    if (b == 0) {
        return a;
    }
    return gcd_recursive(b, a % b);
}
int main(){
    int a;
    cin>>a;
    int arr[a];
    for(int i=0;i<a;i++){
        cin>>arr[i];
    }
    int c=0
    int max=0;
    while (c<a-1){

    }

}