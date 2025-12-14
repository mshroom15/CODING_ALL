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

    int t; 
    cin >> t;
    while (t--) {
        ll n;
        cin>>n;
        v64 v(n);
        v64 v1(n);
        forn(i,n){
            cin>>v[i];      
        }
        forn(i,n){
            v1[i]=i;
        }
        bool check=true;
        forsn(i,1,n){
            v[i]=v[i-1]+v[i];
            v1[i]=v1[i-1]+v1[i];
            if(v1[i]>v[i]){
                cout<<"NO"<<endl;
                check=false;
                break;
            }

        }
        if(check){
            cout<<"YES"<<endl;
        }

    }

    return 0;
}