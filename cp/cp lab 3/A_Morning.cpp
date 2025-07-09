#include<bits/stdc++.h>
using namespace std;

int getPosition(int digit) {
    if (digit == 0) return 9;  // 0 is at position 9
    return digit - 1;          // 1-9 are at positions 0-8
}

int getDistance(int from, int to) {
    // Calculate minimum distance on circular keypad
    int clockwise = (to - from + 10) % 10;
    int counterclockwise = (from - to + 10) % 10;
    return min(clockwise, counterclockwise);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        int count = 0;
        int currentPos = 0; // Start at position 0 (digit 1)
        
        for (char c : s) {
            int digit = c - '0';
            int targetPos = getPosition(digit);
            
            // Add distance to move + 1 to press
            count += getDistance(currentPos, targetPos) + 1;
            currentPos = targetPos;
        }
        
        cout << count << endl;
    }
    return 0;
}