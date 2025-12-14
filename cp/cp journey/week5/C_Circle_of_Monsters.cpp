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
        cin >> n;
        v64 a(n);
        v64 b(n);
        v64 pre(n);
        ll mini=LLONG_MAX;
        ll temp1=0;
        forn(i,n){
            cin>>b[i];
            a[i]=b[i]>temp1?(b[i]-temp1):0;
            cin>>temp1;

        }
        a[0]=a[0]>temp1?(a[0]-temp1):0;
        ll sum=0;
        forn(j,n){
            sum+=a[j];


            }
        forn(i,n){
            ll sum1=0;
            sum1=sum-a[i]+b[i];
            mini=min(sum1,mini);

        }
        cout<<mini<<endl;

    }

    return 0;
}