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

    ll n,t;
    cin>>n>>t;
    vector<ll> v1(n);
    vector<ll> v2(n,0);
    forn(i,n){
        cin>>v1[i];
    }
    
    forn(i,t)  {
        int l,r;
        cin>>l>>r;
        v2[l-1]+=1;
        if(r<n)
        v2[r]-=1;
        
    }
    for(int j=1;j<n;j++){
            v2[j]=v2[j-1]+v2[j];

        }
    sort(v1.rbegin(),v1.rend());
    
    sort(v2.rbegin(),v2.rend());
    ll sum=0;
    forn(i,n){
        sum=sum+v1[i]*v2[i];    }
    cout<<sum;


    

    return 0;
}
