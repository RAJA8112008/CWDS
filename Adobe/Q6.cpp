#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> LevelOrderTraversal(Node* root){
    queue<Node*> q;
    vector<int> ans;

    if(root == NULL) return ans;

    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        ans.push_back(temp->data);

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return ans;
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);

    vector<int> res = LevelOrderTraversal(root);

    for(auto x : res){
        cout << x << endl;
    }
}
