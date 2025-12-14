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
        forn(i,n){
            cin>>v[i];
        }
        bool t1=false;
        for(int i=2;i<n;i++){
            if(i%2){
                if(v[i]%2!=v[1]%2){
                    cout<<"NO"<<endl;
                    t1=true;
                    break;
                }
            }
            if(!(i%2)){
                if(v[i]%2!=v[0]%2){
                    cout<<"NO"<<endl;
                    t1=true;
                    break;
                }
            }


        }
        if(!t1)
        cout<<"YES"<<endl;

    }

    return 0;
}