#include <bits/stdc++.h>
using namespace std;
void solvepattern(int n){
    for(int i=1; i<=2*n-1; i++){
        for(int j=1; j<=2*n-1; j++){
            int top = i ;
            int bottom = 2*n - i;
            int left = j; ;
            int right = 2*n - j;
            cout<<n - min(min(top, bottom), min(left, right));
        }
           
         cout<<endl; 
    }

}
int main(){
    int a;
    cin>>a;
  
    solvepattern(a);
    
    return 0;
}
   