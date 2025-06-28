#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    stack<char> st;
    bool correct = true;
    for (char c:s){
        if(c=='('||c=='{'||c=='['){
            st.push(c);
        }
        else if(c==')'||c=='}'||c==']'){
            if(st.empty()){
                correct =false;
                break;
            }
            char top = st.top();
            if(c=='('||top==')'||
               c=='{'||top=='}'||
               c=='['||top==']')
               st.pop();
               else{
                correct =false;
                break;
               }
            }
        }
    
    if(correct)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
return 0;
}

