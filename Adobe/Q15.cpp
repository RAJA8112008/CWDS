#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    //constructor
    Node(int val){
        data=val;
    }
};
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
//merging process
Node* merge(Node* left,Node* right){
    if(left==NULL)return right;
    if(right==NULL)return left;
    //creating a new LL to get a sorted LL 
    Node* ans=new Node(-1);
    Node* temp=ans;
    while(left!=NULL && right!=NULL){
        if(left->data < right->data){
            temp->next=left;
            left=left->next;
        }else{
           temp->next=right;
            right=right->next; 
        }
        temp=temp->next;
    }
    //Adding Leaving nodes
    if(left!=NULL){
        temp->next=left;
    }
     if(right!=NULL){
        temp->next=right;
    }
    return ans->next;
}
//Printing Process
void printLL(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* mergeSort(Node* head){
    if(head == NULL || head->next == NULL) return head;
    //find middle of the LL
    Node* slow=head;
    Node* fast=head;
    Node* prev=NULL;
    while(fast && fast->next){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev->next=NULL;
    Node* right=slow;
    Node* left=head;
    
    //Divide Process
    right=mergeSort(right);
    left=mergeSort(left);
    return merge(left,right);
     
}

int main(){
    Node* head=NULL;
    head=createLL(head,40);
    head=createLL(head,20);
    head=createLL(head,60);
    head=createLL(head,10);
    head=createLL(head,50);
    head=createLL(head,30);
    cout<<"Real Linked List is:"<<endl;
     printLL(head);
     head=mergeSort(head);
    cout<<"Sorted Linked List is:"<<endl;
     printLL(head);
}