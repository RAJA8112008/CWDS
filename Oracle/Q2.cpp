#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    //constructor
    Node(int value){
        data=value;
        left=NULL;
        right=NULL;

    }
};
//using recursion
bool isBST(Node* root, long long minVal, long long maxVal){
        if(root == NULL) return true;

        if(root->data <= minVal || root->data >= maxVal) return false;

        return isBST(root->left, minVal, root->data) &&
               isBST(root->right, root->data, maxVal);
    }
bool CheckBST(Node* root){
   return isBST(root, LLONG_MIN, LLONG_MAX);
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(8);
    if(CheckBST(root)){
        cout<<"Yes,Given tree is BST"<<endl;
    }else{
        cout<<"NO,Given tree is not BST"<<endl;
    }
}