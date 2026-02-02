#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    //Constructor
    Node(int val){
        data=val;
        next=NULL;
    }
};
 int middleLL(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;

}
int main(){
   Node* root=new Node(1);
   root->next=new Node(2);
    root->next->next=new Node(3);
    root->next->next->next=new Node(4);
    root->next->next->next->next=new Node(5);
   cout<<"Middle Element is:" <<middleLL(root)<<endl;
}