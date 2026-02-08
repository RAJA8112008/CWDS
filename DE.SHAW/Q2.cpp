#include<iostream>
using namespace std;
//class for create node
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    //constructor
    Node(int val){
        this->data=val;
        this->next=NULL;
        this->prev=NULL;
    }
};
Node* createDLL(Node* head,int data){
    //create a new Node
    Node* newNode=new Node(data);
    if(head==NULL){
        return newNode;
    }
    //to traverse on DLL
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    //to arrange the prev pointer
    newNode->prev=temp;
    return head;
}
Node* reverseDLL(Node* head){
    //pointers to reverse the DLL'
    Node* curr=head;
    Node* prev=NULL;
    Node* next=NULL;
    while(curr!=NULL){
        //to arrange the next pointer to its actual place 
        next=curr->next;
        //reverse process
        curr->next=prev;
        curr->prev=next;// it save thw whole LL to destroy
        prev=curr;
        curr=next;
    }
    return prev;
}

//printing process
void printDLL(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
//creation of LL
Node* head=NULL;
head=createDLL(head,3);
head=createDLL(head,4);
head=createDLL(head,5);
cout<<"Actuall DLL "<<endl;
printDLL(head);
//reverse Doubly LL 
cout<<"Reverse DLL "<<endl;
head=reverseDLL(head);
printDLL(head);
}
