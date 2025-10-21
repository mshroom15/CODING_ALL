#include<bits/stdc++.h>
using namespace std;

class node{
public:
    char info;
    class node *link;
};
class node *start = nullptr;
void cleatell(){
    class node *ptr = nullptr, *newnode = nullptr;
    char ch = 'h';
    for (int i =0; i<4; i++){
        newnode = new node;
        newnode->info = ch;
        newnode->link = nullptr;
        if(start == nullptr){
            start = newnode;
            ptr = newnode;
        }
        else{
            ptr->link = newnode;
            ptr = newnode;
        }
        ch++;
    }

}
void tranverse(){
    class node *ptr = nullptr;
    ptr = start;
    while(ptr != nullptr){
        cout<< ptr->info << "\t" << ptr->link << "\n";
        ptr = ptr->link;
    }
}
int main(){
    cleatell();
    tranverse();
    return 0;
}