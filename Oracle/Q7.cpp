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

void removeLoop(Node* head){

if (head == NULL || head->next == NULL) return;
    Node* slow=head;
    Node* fast=head;
    //flag to check loop is exist or not 
    bool isloop=false;
    while(fast && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            isloop=true;//loop is exist
            break;
        }
    }
    //if loop exist or not
    if(!isloop)return;
    //find starting node where the loop starts
    slow=head;//reintilize slow 
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    //find the last node from where loop starts
    while(fast->next!=slow){
        fast=fast->next;
    }
    fast->next=NULL;
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
int main(){
  Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);

    // create loop: 4 → 2
    head->next->next->next->next = head->next;
   removeLoop(head);
   printLL(head);

}