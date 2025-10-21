#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin >> n ;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    cout<<"number you want to find:"<<endl;
    cin>>m;
    bool found=false;
    int ub=n,lb=0;
    while(ub>=lb){
        if(m<a[(lb+ub)/2]){
            ub=(lb+ub)/2-1;
        }else if (m>a[(lb+ub)/2]){
            lb=(lb+ub)/2+1;
        }
        else if (m==a[(lb+ub)/2]){
            found=true;
            break;

    }
}
    if(found==true){
        cout<<"location is:" <<(lb+ub)/2<<endl;
        
    }else cout<<"not found"<<endl;


    return 0;

}