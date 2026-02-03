#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    //Constructor
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
vector<int>SpiralTravels(Node* root){
   vector<int>ans;
   queue<Node*>q;
   q.push(root);
   bool leftToright=true;
   while(!q.empty()){
    int size=q.size();
     vector<int>level(size);
    for(int i=0;i<size;i++){ 
        Node* temp=q.front();
        q.pop();
        int idx=leftToright?i:size-i-1;
        level[idx]=temp->data;
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
     for(auto x:level){
        ans.push_back(x);
    }
    leftToright=!leftToright;
   }
    return ans;
}
int main(){
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
   vector<int>res =SpiralTravels(root);
   for(auto x:res){
    cout<<x<<" ";
   }
   cout<<endl;
}

