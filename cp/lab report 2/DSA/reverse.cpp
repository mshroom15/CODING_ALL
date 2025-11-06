#include <bits/stdc++.h>
using namespace std;
void reverse(int arr[], int &i, int &r){
    if(i>=r)
    return;
    swap(arr[i],arr[r]);
    i++;
    r--;
    reverse(arr,i,r);
    return;
}
int main(){
    int arr[]={2,4,1,6,3,8,2,5,8,7};
    int i=0;
    int r=sizeof(arr)/sizeof(arr[0]) - 1;
    reverse(arr,i,r);
    for (auto a: arr){
        cout<<a<<" ";

    }
    return 0;
}
