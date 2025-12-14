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

    ll a,b;
    cin>>a>>b;
    vector<int> v(a);
    forn(i,a){
        cin>>v[i];
    }
    int l=0;
    int r=a-1;
    int it=-1;
    while(l<=r){
        int m=(l+r)/2;
        if(v[m]>=b){
            r=m-1;
            if(v[m]==b){
            it=m;
        }
        }
        else{
            l=m+1;
        }
    }
    cout<<it<<endl;

    return 0;
}