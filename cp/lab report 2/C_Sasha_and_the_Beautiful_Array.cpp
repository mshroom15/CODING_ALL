#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vector<int> v(x);
        for(int j = 0; j < x; j++) {
            cin >> v[j];        
        }
        sort(v.begin(), v.end());
        cout << v[v.size()-1]-v[0] << endl;
    }
    return 0;
}
