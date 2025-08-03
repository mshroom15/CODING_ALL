#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void solve() {
    string s;
    cin >> s;
    
    int total_time = 0;
    int current_pos = 1;
    
    for (char c : s) {
        int target_pos = c - '0';
        if (target_pos == 0) {
            target_pos = 10;
        }
        
        total_time += abs(target_pos - current_pos);
        total_time += 1; // Time to press the key
        
        current_pos = target_pos;
    }
    
    cout << total_time << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}