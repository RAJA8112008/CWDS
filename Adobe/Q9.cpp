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
//construct LL
Node* createLL(Node* head,int data){
    Node* newNode=new Node(data);
    newNode->next=NULL;
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
//Remove Duplication
Node* removeDuplicates(Node* head){
   Node* curr=head;
   while(curr!=NULL && curr->next!=NULL){
    if(curr->data==curr->next->data){
        Node* dup=curr->next;
        curr->next=dup->next;
        delete dup;
    }
    //if not equal
    else{
        curr=curr->next;
    }
   }
   return head;
}
//print the LL
void printLL(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
 Node* root=NULL;
root=createLL(root,2);
root=createLL(root,2);
root=createLL(root,4);
root=createLL(root,5); 
cout<<"Real LL is:"<<endl;
printLL(root);

 cout<<"After the remove LL is:"<<endl;
 root=removeDuplicates(root);
  printLL(root);
}