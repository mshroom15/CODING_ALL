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
        vector<int> a(n), b(n);
        forn(j,n) cin>>a[j];
        forn(j,n) cin>>b[j];
        ll scorea = 0;
        ll scoreb = 0;
        forn(j,n){
            scorea ^= a[j];
            scoreb ^= b[j];
        }
        ll aj=0;
        ll ml=0;

        forn(j,n){
            if(a[j] != b[j]){
                if(j%2==0){
                    aj ++;
                }
                else{
                    ml ++;
                }

            }
        }
        if((scorea < scoreb || scorea == scoreb ) && aj > ml){
            cout<<"Ajisai\n";
        }
        else if((scorea > scoreb || scorea == scoreb ) && aj < ml){
            cout<<"Mai\n";
        }
        else if(aj == ml && scorea > scoreb ){
            cout<<"Ajisai\n";
        }
        else if(aj == ml && scorea < scoreb ){
            cout<<"Mai\n";
        }
        else if(scorea < scoreb ){
            cout<<"Mai\n";
        }
        else if(scorea > scoreb ){
            cout<<"Ajisai\n";
        }
        else{
            cout<<"Tie\n";
        }
    }


    return 0;
}