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

    ll a,b,x,y,sx,sy;
    cin>>a>>b;
    vector<vector<char>>v(a,vector<char>(b)); 
    queue<pair<ll,ll>>q;
    vector<vector<ll>> dist(a, vector<ll>(b, -1));
    vector<vector<pair<ll,ll>>> parent(a, vector<pair<ll,ll>>(b, {-1, -1}));
    forn(i,a){
        forn(j,b){
            cin>>v[i][j];
            if(v[i][j]=='S'){
                q.push({i,j});
                dist[i][j]=0;
                sx=i;
                sy=j;

            }
            if(v[i][j]=='T'){
             x=i;
             y=j;

            }


    }
}
    while(!q.empty()){
        auto [r,c]=q.front();q.pop();

        if (r==x &&c==y)break;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for(int d=0; d<4; d++){
            ll nr = r + dr[d];
            ll nc = c + dc[d];
            if(nr<0 || nr>=a || nc<0 || nc>=b || v[nr][nc]=='#') continue;
            parent[nr][nc]={r,c};
            if(dist[nr][nc]!=-1) continue;
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr,nc});
}

    }
    if (dist[x][y] == -1){
            cout<<"NO"<<endl;
            return;
        }
        vector<pair<ll,ll>> path;
    int r = x, c = y;

    while(!(r == sx && c == sy)) {
        path.push_back({r,c});
        auto p = parent[r][c];
        r = p.first;
        c = p.second;
    }
    path.push_back({sx,sy});
    reverse(path.begin(), path.end());


   cout<<"YES"<<endl;
   cout<<dist[x][y]<<endl;
   for(auto p :path){
    cout<<p.first<<","<<p.second<<" ";
   }



    return 0;
}