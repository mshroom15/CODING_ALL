#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n, m;
        cin>>n>>m;
        vector<int> arr(n);
        int initialSum = 0;
        for(int j=0;j<n;j++){
            cin>>arr[j];
            initialSum += arr[j];
        }

        for(int j=0;j<m;j++){
            int l, r, x;
            cin >> l >> r >> x;
            
            int sumChange = 0;
            for(int idx=l-1; idx<r; idx++){
                sumChange += (x - arr[idx]);
            }
            
            int newSum = initialSum + sumChange;
            if(newSum % 2 == 0)
                cout<<"NO"<<endl;
            else 
                cout<<"YES"<<endl;
        }
    }
}


