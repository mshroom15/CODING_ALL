#include <bits/stdc++.h>
using namespace std;
bool isprime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int nextprime(int n) {
    n++;
    while (!isprime(n)) {
        n++;
    }
    return n;
}
int main() {
    int t;  
    cin >> t;
    while (t--) {
        vector<int> arr(101);
        for (int i = 1; i < 101; i++) {
            arr[i]=i;
        }
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int from, to;
            cin >> from >> to;
            arr[from] = to;
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int from, to;
            cin >> from >> to;
            arr[from] = to;
        }
        int six , one , prime;
        cin >> six >> one >> prime;
        int thor,hulk;
        cin >> thor >> hulk;    
        int rollnum;
        cin >> rollnum;
        for(int i=0;i<rollnum;i++){
            int roll;
            cin>>roll;
            if(roll==6&&six){
                thor = max(thor-6,1);
                thor = arr[thor];
            }else if(roll==1&&one){
                if (thor + 6 <= 100) {
                    thor += 6;
                    thor = arr[thor];
                }       
            }else if (thor + roll <= 100) {
                thor += roll;
                thor = arr[thor];
            }
            
            if(isprime(thor)&&prime){
                int np=nextprime(thor);
                if(np<=100){
                    thor=np;
                    thor=arr[thor]; 
                }       
            }
        }
        for(int i=0;i<rollnum;i++){
            int roll;
            cin>>roll;
            if(roll==6&&six){
                hulk = max(hulk-6,1);
                hulk = arr[hulk];
            }else if(roll==1&&one){
                if (hulk + 6 <= 100) {
                    hulk += 6;
                    hulk = arr[hulk];
                }
            } else if (hulk + roll <= 100) {
                hulk += roll;
                hulk = arr[hulk];
            }

            if(isprime(hulk)&&prime){
                int np=nextprime(hulk);
                if(np<=100){
                    hulk=np;
                    hulk=arr[hulk]; 
                }       
            }
        }
        if (thor == 100 && hulk == 100) {
            cout << "Both player win" << endl;
        } else if (thor == hulk) {
            cout << "Draw" << endl;
        } else if (thor > hulk) {
            cout << "Thor wins by " << (thor - hulk) << " points" << endl;
        } else {
            cout << "Hulk wins by " << (hulk - thor) << " points" << endl;
        }
    }
    return 0;
}