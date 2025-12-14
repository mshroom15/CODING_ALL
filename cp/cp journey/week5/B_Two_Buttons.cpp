#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fastio;

    ll n, m;
    cin >> n >> m;

    if (n >= m) {
        cout << n - m << "\n";
        return 0;
    }

    queue<ll> q;
    queue<ll> q1;
    vector<int> vis(2*m + 5, 0);

    q.push(n);
    vis[n] = 1;
    ll steps = 0;

    bool found = false;

    while (true) {
        while (!q.empty()) {
            ll x = q.front();
            q.pop();

            if (x == m) {
                found = true;
                break;
            }

            if (2*x < 2*m+5 && !vis[2*x]) {
                vis[2*x] = 1;
                q1.push(2*x);
            }
            if (x-1 >= 0 && !vis[x-1]) {
                vis[x-1] = 1;
                q1.push(x-1);
            }
        }

        if (found) break;

        steps++;
        swap(q, q1);
    }

    cout << steps << "\n";
    return 0;
}
