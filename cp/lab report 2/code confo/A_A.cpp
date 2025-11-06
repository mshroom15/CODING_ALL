#include <bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        int n;
        cin>>n;
        int a1[n];
        for(int j=0;j<n;j++){
            cin>>a1[j];
        }
        int u=n-1;
        int l=0;
        int c=0;
        while(!(u<=l)){
            if(a1[l]==1&&a1[u]==0){
                c++;
                l++;
                u--;
            }
            else if(a1[l]==0&&a1[u]==0){
                l++;
            }
            else if(a1[l]==1&&a1[u]==1){
                u--;
            }
            else if(a1[l]==0&&a1[u]==1){
                l++;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}
