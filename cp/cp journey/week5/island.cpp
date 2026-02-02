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
    queue<pair<ll,ll>>Q;
    queue<pair<ll,ll>>q;
    vector<vector<bool>> visit(a, vector<bool>(b, false));
    forn(i,a){
        forn(j,b){
            cin>>v[i][j];
            if(v[i][j]==1){
                Q.push({i,j});
            }
        }
    }
ll count=0;
while(!Q.empty()){
    auto [x,y]=Q.front();Q.pop();
    if(visit[x][y]==true)continue;
    q.push({x,y});
    visit[x][y]=true;


    while(!q.empty()){
        auto [r,c]=q.front();q.pop();
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for(int d=0; d<4; d++){
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(nr<0 || nr>=a || nc<0 || nc>=b || v[nr][nc]==0) continue;
            if(visit[nr][nc]==true) continue;
            visit[nr][nc] = true;
            q.push({nr,nc});
        }

    }
    count++;

}
        cout<<count<<endl;
    



    return 0;
}