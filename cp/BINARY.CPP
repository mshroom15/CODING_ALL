#include <iostream>
#include <queue>
using namespace std;

void generateBinary(int n) {
    queue<string> q;
    q.push("1");

    for (int i = 0; i < n; i++) {
        string current = q.front();
        q.pop();

        cout << current << endl;

        q.push(current + "0");
        q.push(current + "1");
    }
}

int main() {
    int n;
    cin >> n;
    generateBinary(n);
    return 0;
}