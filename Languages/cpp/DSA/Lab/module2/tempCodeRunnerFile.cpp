#include<iostream>
using namespace std;

int main(){
    int n=10;
    int x;
    int k;
    int la[n]={32,45,75,23,56,23,7,45,89,36};
    cout<<"array before insertion:";
    for(int i=0;i<n;i++){
        cout<<la[i]<<" ";                   
    }
    cout<<endl;
    cout<<"what value do you want to insert?"<<endl;
    cin>>x;
    cout<<"what position do you want to insert it to? "<<endl;
    cin>>k;
    int j = n-1;
    while(k<=j){
        la[j+1]=la[j];
        j--;
    }
    la[k]=x;
    n++;
    cout<<"array after insertion:";
    for(int i=0;i<n;i++){
        cout<<la[i]<<" ";                   
    }
    return 0;



}
