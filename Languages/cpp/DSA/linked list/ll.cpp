#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    Node(int data1, Node* next1=nullptr):data{data1},next{next1}{}
};
Node* covertarr2llz(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next=temp;
        mover=temp;

    }
    return head;

}
int main(){
    vector<int> arr = {2,5,1,7,3};
    Node* head = covertarr2llz(arr);
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
