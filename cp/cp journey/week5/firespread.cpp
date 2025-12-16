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

    ll a,b;
    cin>>a>>b;
    vector<vector<int>>v(a,vector<int>(b)); 
    queue<pair<ll,ll>>q;
    vector<vector<ll>> dist(a, vector<ll>(b, -1));
    forn(i,a){
        forn(j,b){
            cin>>v[i][j];
            if(v[i][j]==1){
                q.push({i,j});
                dist[i][j]=0;

        }
    }
}
    while(!q.empty()){
        auto [r,c]=q.front();q.pop();
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for(int d=0; d<4; d++){
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(nr<0 || nr>=a || nc<0 || nc>=b) continue;
            if(dist[nr][nc]!=-1) continue;
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr,nc});
}

    }
    forn(i,a){
        forn(j,b){
            cout<<dist[i][j]<<" ";

        }
        cout<<endl;
    }



    return 0;
}