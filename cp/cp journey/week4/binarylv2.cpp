#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
typedef vector<ll> v64;
typedef vector<int> v32;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define all(x) (x).begin(), (x).end()

int main() {
    fastio;

    ll n, h;
    cin>>n>>h;
    v64 v(n);
    forn(i,n){
        cin>>v[i];      
    }
    ll l=1;
    ll r=*max_element(all(v));
    int it=-1;
    while(l<=r){
        int m=(l+r)/2;
        int sum=0;
        for(auto a:v){
            sum+=ceil((double)a/m);

        }
        if(sum<=h){
            r=m-1;
            it=m;
        }
        else{
            l=m+1;
        }
    }
    cout<<it<<endl;
    
    return 0;
}