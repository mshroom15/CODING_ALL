#include <bits/stdc++.h>
using namespace std;


#define fastio ios::sync_with_stdio(false); cin.tie(NULL);


int main(){
    fastio
    int n ;
    long long k;
    long long sum = 0; 
    cin>>n>>k;
    vector<int> v(n);
    for(int i =0;i<n;i++)
    cin>>v[i];
    
    for(int i =0;i<k;i++){
        sum +=v[i];
}
long long bsum=sum;
int bsumi=0;
   
    for(int i =k;i<n;i++){
        sum +=v[i] - v[i-k];
        if(bsum>sum){
        bsum=sum;
        bsumi=i-k+1;}

}
    
    cout<<bsumi+1;
    

    

    return 0;
}