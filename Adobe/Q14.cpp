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
        data=val;
        right=NULL;
        left=NULL;
    }
};
pair<bool,int>solve(Node* root){
     if(root==NULL)return {true,0};
    if(root->left==NULL && root->right==NULL){
        return {true,root->data};
    }
    pair<bool,int>leftAns=solve(root->left);
    pair<bool,int>rightAns=solve(root->right);

    bool isleft=leftAns.first;
    bool isright=rightAns.first;

    int leftSum=leftAns.second;
    int rightSum=rightAns.second;

    bool curr=(root->data==leftSum+rightSum);

    int totalSum=root->data+leftSum+rightSum;
    bool isSumTree=isleft && isright && curr;
    return {isSumTree,totalSum};
   
}

bool isSumTree(Node* root){
     return solve(root).first;
}
int main(){
Node* root=new Node(20);
    root->left=new Node(10);
    root->right=new Node(10);
    cout << (isSumTree(root) ? "YES" : "NO") << endl;

}