#include <iostream>
using namespace std;
int main() {
    string str;
    cin >> str;
    int num =0;
    int n = str.length();
    for(int i=1;i<=3 && i<n;i++){
        for(int j=i+1;j<=i+3 && j<n;j++){
            for(int k=j+1;k<=j+3 && k<n;k++){
                string a = str.substr(0,i);
                string b = str.substr(i,j-i);
                string c = str.substr(j,k-j);
                string d = str.substr(k);
                bool valid = true;
                if(a.empty() || b.empty() || c.empty() || d.empty()) {
                    valid = false;
                } else {
                    if((a.length()>1 && a[0]=='0') || a.length()>3 || stoi(a) > 255  )  valid = false;
                    if((b.length()>1 && b[0]=='0') || b.length()>3 || stoi(b) > 255  )  valid = false;
                    if((c.length()>1 && c[0]=='0') || c.length()>3 || stoi(c) > 255  )  valid = false;
                    if((d.length()>1 && d[0]=='0') || d.length()>3 || stoi(d) > 255  )  valid = false;
                    if(valid) num++;
                }

                }
            }
        }
    cout<<num<<endl;
    return 0;
}   