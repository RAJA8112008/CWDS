#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left=NULL;
    Node* right=NULL;
    //Constructor
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
vector<int>RightView(Node* root){
    queue<Node*>q;
    vector<int>ans;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();
            if(i==size-1){
                ans.push_back(temp->data);
            }
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        
    }
    return ans;
}
int main(){
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    vector<int>res=RightView(root);
    for(auto x:res){
        cout<<x<<" ";
    }cout<<endl;
}