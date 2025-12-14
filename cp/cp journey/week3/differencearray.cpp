#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n,0);
    int q;
    cin>>q;
    for(int i =0;i<q;i++)  {
        int l,r,x;
        cin>>l>>r>>x;
        if(l>=n||r>=n||l>r){
            continue;
        }
        v[l]+=x;
        if(r+1<n)
        v[r+1]-=x;
        
    }
    cout<<v[0]<<" ";
    for(int j=1;j<n;j++){
            v[j]=v[j-1]+v[j];
            cout<<v[j]<<" ";

        }
        
}