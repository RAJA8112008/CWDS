//merge two sorted lists
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//nod ecreation
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

Node* merged(Node* l1,Node* l2){
    Node* dummy=new Node(-1);
    Node* head1=l1;
    Node* head2=l2;
    Node* dummyhead=dummy;
    while(head1!=NULL && head2!=NULL){
        
        if(head1->data<=head2->data){
            dummyhead->next=new Node(head1->data);
            head1=head1->next;
        }else{
             dummyhead->next=new Node(head2->data);
             head2=head2->next;
        }
        dummyhead=dummyhead->next;
    }
    //remaining elements (Node);
    while(head1!=NULL){
        dummyhead->next=new Node(head1->data);
        dummyhead=dummyhead->next;
        head1=head1->next;
    }
     while(head2!=NULL){
        dummyhead->next=new Node(head2->data);
        dummyhead=dummyhead->next;
        head2=head2->next;
    }
    return dummy->next;
}
//LL creatipn
Node* createLL(Node* head,int val){
     Node* newNode=new Node(val);
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
void printLL(Node* root){
    Node* temp=root;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
     cout<<"First list is:"<<endl;
Node* root=NULL;
root=createLL(root,1);
root=createLL(root,2);
root=createLL(root,4);
printLL(root);
cout<<" "<<endl;
 cout<<"Second list is:"<<endl;
 
Node* root2=NULL;
root2=createLL(root2,1);
root2=createLL(root2,3);
root2=createLL(root2,4);
printLL(root2);
cout<<"MergeD Sorted List"<<endl;
Node* head=merged(root,root2);
printLL(head);

}