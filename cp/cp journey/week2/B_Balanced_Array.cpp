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
    ll t;
    cin >> t;
    v32 v;
    forn(i,t){
        int value;
        cin>>value;
        v.push_back(value);
    }
    forn(i,t){
        if((v[i]/2)%2!=0){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        forsn(j,1,v[i]/2+1){
            cout<<j*2<<" ";

        }
        forn(j,v[i]/2-1){
            cout<<2*j+1<<" ";

        }
        cout<<2*(v[i]/2-1)+1+v[i]/2<<endl;

    }  

    return 0;
}