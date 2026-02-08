#include<iostream>
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
Node* findIntersection(Node* head1,Node* head2){
    if(head1==NULL || head2==NULL)return NULL;
    Node* dummy=new Node(-1);
    Node* tail=dummy;
    Node* ptr1=head1;
    Node* ptr2=head2;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data==ptr2->data){
            tail->next=new Node(ptr1->data);
            tail=tail->next;
          ptr1=ptr1->next;
           ptr2=ptr2->next;
        }else if(ptr1->data<ptr2->data){
            ptr1=ptr1->next;
        }else{
            ptr2=ptr2->next;
        }
    }
return dummy->next;
}

//printing process
void printLL(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
//creation of first LL
Node* root=new Node(1);
root->next=new Node(2);
root->next->next=new Node(3);
root->next->next->next=new Node(4);
root->next->next->next->next=new Node(5);
root->next->next->next->next->next=new Node(6);
//creation of second LL
Node* root2=new Node(2);
root2->next=new Node(4);
root2->next->next=new Node(6);
root2->next->next->next=new Node(8);
 root= findIntersection(root,root2);
 printLL(root);
}