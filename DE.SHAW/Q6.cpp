#include<iostream>
using namespace std;
#include<bits/stdc++.h>
class Node{
    public:
    int data;
    Node* right;
    Node* left;
    //constructor
    Node(int val){
        this->data=val;
        this->right=NULL;
        this->left=NULL;
    }
};
vector<int>solve(Node* root,vector<int>&ans){
    //base cases
    if(root==NULL)return ans;
    if(root->left!=NULL && root->right==NULL)ans.push_back(root->left->data);
    if(root->left==NULL && root->right!=NULL)ans.push_back(root->right->data);
    solve(root->left,ans);
    solve(root->right,ans);
    return ans;
}

vector<int>noSibling(Node* head){
    vector<int>ans;
    solve(head,ans);
    //in assending order and if size of ans is 1 then return -1
    sort(ans.begin(),ans.end());
    if(ans.size()==0){
        return {-1};
    }
    return ans;
}

    //    1
    //   / \
    //  2   3
    // /
    // 4
int main(){
 Node* head=new Node(1);
 head->left=new Node(2);
 head->right=new Node(3);
 head->left->left=new Node(4);

 vector<int>arr=noSibling(head);
 cout<<"without siblings Nodes are:"<<endl;
 for(int i=0;i<arr.size();i++){
  cout<<arr[i]<<" ";
 }cout<<endl;
}