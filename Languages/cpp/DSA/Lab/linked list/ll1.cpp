#include <iostream>
using namespace std;
char info[10];
int link[]={2,3,4,5,6,7,8,9,1,-1};
int start =-1;
int avail=0;
int newnode(){
    if(avail==-1){
        cout<<"Overflow";
        return -1;
    }
    int newindex=avail;
    avail=link[avail];
    return newindex;
}    
void createll(){
    int ptr = -1, i, newindex;
    char ch = 'h';
    for (i =0;i<8;i++){
        newindex = newnode();
        if(newindex==-1){
            break;                      
        }   
        info[newindex]=ch;
        link[newindex]=-1;
        if(start==-1){
            start=newindex;
            ptr = newindex; 


        }
        else {
            link[ptr]=newindex;
            ptr = newindex;
    
        }
        ch++;



    }
    ptr=-1;

}
void tranverse(){
    int ptr =0;
    ptr = start;
    while(ptr!=-1){
        cout<<ptr<< "\t"<<info[ptr]<< "\t"<<link[ptr]<< "\n";
        ptr=link[ptr];
    }
}
int main(){
    createll();
    tranverse();
    return 0;
}