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
vector<bool>vis;
vector<vector<ll>>adj;
bool ok;

void dfs(ll u){
    vis[u] = true;
    if(adj[u].size()!=2){
        ok =false;
    }

    for(int v : adj[u]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
}
int main() {
    fastio;

    ll n,m;
    cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1);
    forn(i,m){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll cycle=0;
    forsn(i,1,n){
        if(!vis[i]){
            ok=true;
            dfs(i);
        if(ok){
            cycle++;

        }
    }

    }
    cout<<cycle<<endl;


    return 0;
}