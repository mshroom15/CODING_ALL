#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    for (pair<char, int> p : freq) {
        if (p.second == 1) {
            cout << p.first << endl;
            return 0;
        }
    }