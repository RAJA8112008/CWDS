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
bool isBST(Node* root,int minval,int maxval){
    if(!root)return true;
    //all false cases
    if((root->data>=maxval)||(root->data<=minval))return false;
   //leftside 
   bool left=isBST(root->left,minval,root->data);
   bool right=isBST(root->right,root->data,maxval);

return  left && right;
}
int Lengthcount(Node* root){
    if(!root)return 0;

    return 1+Lengthcount(root->left)+Lengthcount(root->right);
}
int largestBst(Node* root){
    //check tree is BST
    //find length of BST
    if(root==NULL)return 0;
    if(isBST(root,INT_MIN,INT_MAX)){
        return Lengthcount(root);
}
return max(largestBst(root->left),largestBst(root->right));
}
int main(){
 Node* root=new Node(5);
 root->left=new Node(2);
 root->right=new Node(4);
 root->left->left=new Node(1);
 root->left->right=new Node(3);
 cout<<"Length is:"<<largestBst(root)<<endl;
}