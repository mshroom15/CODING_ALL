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

    ll x0,y0,x,y,a,b;
    cin>>x0>>y0>>x>>y>>a>>b;
    vector<vector<char>>v(a,vector<char>(b));
    forn(i,a){
        forn(j,b){
            cin>>v[i][j];
        }
    }
    vector<vector<ll>> dist(a, vector<ll>(b, -1));
    queue<pair<ll,ll>>q;
    q.push({x0,y0});
    dist[x0][y0]=0;
    while(!q.empty()){
        auto [r,c]=q.front();q.pop();
        if (r==x &&c==y)break;
        if(r-1>=0&&dist[r-1][c]==-1&&v[r-1][c]!='#'){
            dist[r-1][c]=dist[r][c]+1;
            q.push({r-1,c});
        }
        if(c-1>=0&&dist[r][c-1]==-1&&v[r][c-1]!='#'){
            dist[r][c-1]=dist[r][c]+1;
            q.push({r,c-1});
        }
        if(r+1<a&&dist[r+1][c]==-1&&v[r+1][c]!='#'){
            dist[r+1][c]=dist[r][c]+1;
            q.push({r+1,c});
        }
        if(c+1<b&&dist[r][c+1]==-1&&v[r][c+1]!='#'){
            dist[r][c+1]=dist[r][c]+1;
            q.push({r,c+1});
        }


    }
    cout<<dist[x][y];


    return 0;
}