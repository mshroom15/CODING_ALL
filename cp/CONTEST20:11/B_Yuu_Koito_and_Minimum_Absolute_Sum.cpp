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
    cin>>t;
    forn(i,t){
        ll n;
        cin>>n;
        vector<int> v(n);
        forn(j,n) cin>>v[j];
        bool flag = false;
        if(v[0]<0 || v[n-1]<0) flag = true;
        rforn(j,n-1){
            if(v[j]<0){
             v[j]=0;
            }
        }
       
        ll sum = 0;
        forn(j,n-1) sum += v[j+1]-v[j];
        if(flag){
            if(sum>0 && v[0]==0) v[0]=sum;
            else if(sum<0 && v[n-1]==0) v[n-1]= -sum;
            sum =0;
        }
        cout << abs(sum) << endl;
        forn(j,n) cout << v[j] << " ";
        cout << endl;
    }

    return 0;
}