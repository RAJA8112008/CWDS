#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
 int data;
 Node* next;
 Node* random;
 //constructor
 Node(int val){
    this->data=val;
    this->next=NULL;
    this->random=NULL;
 }
};
//cloning Process
Node* cloneLL(Node* root){
   //simple node creation 
   Node* Oldhead=root;
   Node* newHead=new Node(root->data);
   //pointers to travese on both LL
   Node* Oldtemp=Oldhead->next;
   Node* newtemp=newHead;
   while(Oldtemp!=NULL){
     newtemp->next=new Node(Oldtemp->data);
     Oldtemp=Oldtemp->next;
     newtemp=newtemp->next;
    
   }
   //to get the randome pointer
   unordered_map<Node*,Node*>mp;
   Oldtemp=Oldhead;
   newtemp=newHead;
   while(Oldtemp!=NULL){
    mp[Oldtemp]=newtemp;
     Oldtemp=Oldtemp->next;
     newtemp=newtemp->next;
   }
   //To arrange the Randome pointer
    Oldtemp=Oldhead;
    newtemp=newHead;
   while(Oldtemp!=NULL){
     newtemp->random=mp[Oldtemp->random];
     Oldtemp=Oldtemp->next;
     newtemp=newtemp->next;
   }
    return newHead;
}
void printLL(Node* root){
    Node* temp=root;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

int main(){
    Node* root=new Node(5);
    root->next=new Node(6);
    root->next->next=new Node(7);
    root->next->next->next=new Node(8);
    root->next->next->next->next=new Node(9);
    //randome pointer arrangement
    root->random = root->next->next;
    root->next->random=root->next->next->next->next;
    cout<<"Original LL"<<endl;
     printLL(root);
   Node* head=cloneLL(root);
   cout<<"Clone LL"<<endl;
    printLL(head);
   
}