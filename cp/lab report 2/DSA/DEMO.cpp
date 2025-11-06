#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        set<int> s;
        for(int i=0;i<n;i++){
            while(a[i]%2==0)a[i]/=2;
            s.insert(a[i]);
        }
        int ok=1;
        for(int i=n;i>=1;i--){
            int x=i;
            while(x){
                if(s.find(x)!=s.end()){
                    s.erase(x);
                    break;
                }
                x/=2;
            }
            if(!x)ok=0;
        }
        if(ok)cout<<"YES\n";
        else cout<<"NO\n";
    }
}
