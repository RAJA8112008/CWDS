#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    //constructor
    Node(int val){
        data=val;
        next=NULL;
    }
};
//LL creation
Node* createLL(Node* root,int data){

    Node* newNode=new Node(data);
    newNode->next=NULL;
  if(root==NULL){
    return newNode;
  }
  Node* temp=root;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=newNode;
  return root;
  
}
 //reverse process
Node* reverseLL(Node* head){
  Node* curr=head;
  Node* next=NULL;
  Node* prev=NULL;
  while(curr!=NULL){
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
  }
  return prev;
}
//printing process
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

int main(){
    Node* root=NULL;
    int n;
    int m;
    cout<<"Enter the LL size:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
      root=createLL(root,m);
    }
  cout<<"Original LL Is:";
  print(root);
  cout<<"Reverse LL Is:";
  root=reverseLL(root);
  print(root);
 

}