#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    // constructor
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool solve(Node* root,int currSum,int target){
    if(root==NULL)return false;
    currSum+=root->data;
    if(root->left==NULL && root->right==NULL){
        return currSum==target;
    }
    return solve(root->left,currSum,target) || solve(root->right,currSum,target);
}
bool PathSum(Node *root,int target)
{
    return solve(root,0,target);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
     int target = 3;
    if (PathSum(root,target))
    {
        cout<< "Yes" <<endl;
    }
    else
    {
        cout<< "No" <<endl;
    }
}