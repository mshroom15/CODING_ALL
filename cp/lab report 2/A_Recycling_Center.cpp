#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
       int a,b;
         cin >> a >> b;
        vector<int> v(a);
        for(int j = 0; j < a; j++){
            cin >> v[j];
        }
        sort(v.begin(), v.end());
        int coin = 0;
        while(!v.empty()){
            while(!v.empty() && v.back() > b){
                coin++;
                v.pop_back();
            }

            if(v.empty()) break;
            
            v.pop_back();
            
            if(v.empty()) break;

            for(int j = 0; j < v.size(); j++){
                v[j] = v[j] * 2;
            }
        }
        cout << coin << endl;
    }
}