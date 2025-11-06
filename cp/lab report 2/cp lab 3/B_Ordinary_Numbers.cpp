#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int count = 0;
        for (int len = 1; len <= 9; len++) {
            for (int d = 1; d <= 9; d++) {
                long long num = 0;
                for (int i = 0; i < len; i++) {
                    num = num * 10 + d;
                }
                if (num <= a) {
                    count++;
                } else {
                    break;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}