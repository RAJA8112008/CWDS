#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node* nextRight;
    //constructor
    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
        this->nextRight=NULL;
    }
};
Node* connect(Node* root){
     if(root == NULL) return NULL;
      queue<Node*>q;
      q.push(root);
      
      while(!q.empty()){
          int size=q.size();
          Node* prev=NULL;
          for(int i=0;i<size;i++){
              Node* curr=q.front();
              q.pop();
              if(prev!=NULL){
                  prev->nextRight=curr;
                  
              }
              prev=curr;
              if(curr->left){
                  q.push(curr->left);
              }
              
              if(curr->right){
                  q.push(curr->right);
              }
          }
          prev->nextRight=NULL;
      }
      return root;
    }
    //print 
void printTree(Node* root){
    while(root != NULL) {
        Node* curr = root;
        while(curr != NULL) {
            cout << curr->data << " ";
            curr = curr->nextRight;
        }
        cout << endl;
        root = root->left;
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
     /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */
    
    cout<<"Connected Tree is:"<<endl;
    connect(root);
  printTree(root);
    
}