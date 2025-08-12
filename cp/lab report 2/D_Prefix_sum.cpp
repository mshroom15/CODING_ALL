#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        vector<long long> v(x);
        for(long long j = 0; j < x; j++) {
            cin >> v[j];
        }
        vector<long long> prefix_sum(x);
        prefix_sum[0] = v[0];
        for(long long j = 1; j < x; j++) {
            prefix_sum[j] = prefix_sum[j-1] + v[j];
        }
        long long a;
        cin >> a;
        for(long long j = 0; j < a; j++) {
            long long b, c;
            cin >> b >> c;
            cout << prefix_sum[c-1] - (b > 1 ? prefix_sum[b-2] : 0) << "\n";
        }
    }
    return 0;
}
