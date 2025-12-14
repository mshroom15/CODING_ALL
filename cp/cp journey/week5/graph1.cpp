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
    ll n,e;
    cin>>n>>e;
    map<ll,v64> adj;
    forn(i,e){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n+1,false);
    v64 dist(n+1,-1);
    queue<ll> q;
    dist[1]=0;
    visited[1]=true;
    q.push(1);
    while(!q.empty()){
        ll node=q.front();
        q.pop();
        for(auto child:adj[node]){
            if(!visited[child]){
                visited[child]=true;
                dist[child]=dist[node]+1;
                q.push(child);
            }
        }
    }
    forn(i,n){
        cout<<dist[i+1]<<" ";
    }
    cout<<endl;

    return 0;
}