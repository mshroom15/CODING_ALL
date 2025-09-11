#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin >> n ;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    cout<<"number you want to find:"<<endl;
    cin>>m;
    int k,loc=-1;
    for(k=0;k<n;k++){
        if(a[k]==m){
            loc=k;
            break;
        }
    }
    if(loc==-1){
        cout<<"not found"<<endl;

    }else cout<<"index after sorting is: "<<k<<endl;
    
    return 0;

}