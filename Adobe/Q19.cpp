#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    //constructor
    Node(int val){
        this->data=val;
        this->next=NULL;
    }
};
Node* reverseKGroup(Node* head,int k){
    Node* curr=head;
    Node* prev=NULL;
    Node* next=NULL;
    int count=0;
    while(curr!=NULL && count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL){
        head->next=reverseKGroup(next,k);
    }
    return prev;
}
//creation of LL
Node* createLL(Node* head,int data){
     Node* newNode=new Node(data); 
     if(head==NULL){
        return newNode;
     }
     Node* temp=head;
     while(temp->next!=NULL){
        temp=temp->next;
     }
     temp->next=newNode;
     return head;
}
//print
void printLL(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    Node* head=NULL;
    head=createLL(head,1);
    head=createLL(head,2);
    head=createLL(head,3);
    head=createLL(head,4);
    head=createLL(head,5);
    head=createLL(head,6);
    int k;
    cout<<"Enter the value of K for rotation:"<<endl;
    cin>>k;
    cout<<"Original LL is:"<<endl;
    printLL(head);
    cout<<endl;
    head=reverseKGroup(head,k);
    cout<<"Reversed LL is:"<<endl;
    printLL(head);
}