#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        set<char> seen;
        string ans = "";
        for (char c : s) {
            if (seen.find(c) == seen.end()) {
                ans += c;
                seen.insert(c);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
