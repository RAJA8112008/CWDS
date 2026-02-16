#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    //constructor
    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};

bool isCousin(Node* root,int l1,int l2){
 if(root == NULL)return false;
 queue<pair<Node*,Node*>>q;
   q.push({root,NULL});
   while(!q.empty()){
    int size=q.size();
   Node* parent1=NULL;
   Node* parent2=NULL;
    for(int i=0;i<size;i++){
        auto temp=q.front();
        q.pop();
        Node* node=temp.first;
        Node* parent=temp.second;
       if(node->data==l1){
        parent1=parent;
       }
        if(node->data==l2){
        parent2=parent;
       }
       //insertin in Queue
       if(node->left){
        q.push({node->left,node});
       }
       if(node->right){
        q.push({node->right,node});
       }
    }
      if(parent1 && parent2)
        return parent1 != parent2;

        // If only one found → not cousins
        if(parent1 || parent2)
            return false;
    }

    return false; 
}
int main(){
 Node* root=new Node(1);
 root->left=new Node(2);
 root->right=new Node(3);
 root->left->left= new Node(4);
 root->left->right=new Node(5);
 root->right->left = new Node(6);

 cout<<(isCousin(root,4,6)?"Yes":"NO")<<endl;
}