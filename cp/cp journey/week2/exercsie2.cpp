#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
typedef vector<ll> v64;

int main() {
    fastio;
    ll n;
    cin>>n;
    v64 v;
    for(ll i =0;i<2*n;i++){
        int val;
        cin>>val;
        v.push_back(val);
    }
    sort(v.begin(), v.end());
    int min_sum=0;
    for(ll i =1;i<2*n;i+=2){
        min_sum+=v[i];


    }
    cout<<min_sum;


    return 0;
}