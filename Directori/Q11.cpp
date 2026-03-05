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
int solve(Node* root,int&maxSum){
    if(root==NULL)return 0;
    //getting left Sum  
    int leftSum=max(0,solve(root->left,maxSum));//reduce the negative case
    int rightSum=max(0,solve(root->right,maxSum));//reduce the negative case
    int pathSum=leftSum+rightSum+root->data;
    maxSum=max(maxSum,pathSum);
    return max(leftSum,rightSum)+root->data;
}
int maxPathSum(Node* root){
    if(root==NULL)return 0;
    int maxSum=INT_MIN;
    solve(root,maxSum);
    return maxSum;
}
int main(){
Node* root=new Node(3);
root->left=new Node(4);
root->right=new Node(5);
root->left->left=new Node(-10);
root->left->right=new Node(4);
cout<<maxPathSum(root)<<endl;
}