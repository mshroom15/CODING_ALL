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
       ll a,b;
       cin>>a>>b;
       ll r=0;
       ll l=0;

       while(true){
        r=b+b/a-l/a;
        if(b/a==r/a){
            cout<<r<<endl;
            break;
        }
        l=b;
        b=r;

        

       }
    }

    return 0;
}
/*better or correct code 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ll n, k;
        cin >> n >> k;

        ll lo = 1, hi = k * n;      // safe upper bound
        ll ans = hi;

        while (lo <= hi) {
            ll mid = (lo + hi) / 2;

            // how many numbers <= mid are NOT divisible by n?
            ll cnt = mid - mid / n;

            if (cnt >= k) {
                ans = mid;          // mid is enough, try smaller
                hi = mid - 1;
            } else {
                lo = mid + 1;       // not enough, need bigger mid
            }
        }

        cout << ans << '\n';
    }

    return 0;
}

*/