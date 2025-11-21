#include <bits/stdc++.h>
using namespace std;


#define fastio ios::sync_with_stdio(false); cin.tie(NULL);


int main(){
    fastio
    int n ;
    long long t;
    int left = 0, right = 0, sum = 0, ans = 0;
    cin>>n>>t;
    vector<int> v(n);
    for(int i =0;i<n;i++)
    cin>>v[i];
    
    for(int right =0;right<n;right++){
        sum +=v[right];
        while(sum>t){
            sum-=v[left];
            left++;
        }
        ans=max(ans,right-left+1);


    }
    cout<<ans;
    

    

    return 0;
}
