#include<iostream>
#include<bits/stdc++.h>
using namespace std;
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
Node* mappedParent(Node* root,int target,unordered_map<Node*,Node*>&parentTochild){
  
//Level order Traversal
   queue<Node*>q;
   Node* res=NULL;
   q.push(root);
   parentTochild[root]=NULL;
   while(!q.empty()){
    Node* temp=q.front();
    q.pop();
    
    if(temp->data==target){
        res=temp;
    }
    if(temp->left!=NULL){
        parentTochild[temp->left]=temp;
        q.push(temp->left);
    }

    if(temp->right!=NULL){
        parentTochild[temp->right]=temp;
        q.push(temp->right);
    }
   }
   return res;
}
int burnTree(Node* root,Node* target,unordered_map<Node*,Node*>&parentTochild){

    unordered_map<Node*,bool>visited;
    queue<Node*>q;
    q.push(target);
    visited[target]=true;
  int time=0;
    while(!q.empty()){
        bool flag=false;
        int size=q.size();
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();
                //to burn Left
            if(temp->left!=NULL && !visited[temp->left]){
                flag=true;
                visited[temp->left]=true;
                q.push(temp->left);
            }
                //to burn Right
            if(temp->right!=NULL && !visited[temp->right]){
                flag=true;
                visited[temp->right]=true;
                q.push(temp->right);
            }

            //to burn Parent
           
                if(parentTochild[temp] && !visited[parentTochild[temp]]){
                    flag=true;
                    visited[parentTochild[temp]]=true;
                    q.push(parentTochild[temp]);
            }
        }
        if(flag==true)time++;
    }
return time;

}
 int  minTime(Node* root,int target){
    if(root == NULL) return 0;

    //mapping parent to childs  return target Node
    unordered_map<Node*,Node*>parentTochild;
    Node* targetNode=mappedParent(root,target,parentTochild);
    if(targetNode == NULL)
        return 0;
     return burnTree(root,targetNode,parentTochild);

 }

int main(){
Node* root=new Node(1);
root->left=new Node(2);
root->right= new Node(3);
root->left->left=new Node(4);
root->left->right=new Node(5);
root->left->left->left=new Node(8);
root->left->right->right=new Node(5);
root->left->right->right->right=new Node(10);
root->right->right=new Node(7);
  cout<<"Enter the target:"<<endl;
  int target;
  cin>>target;
  cout<<"Min time to burn tree is"<<minTime(root,target)<<endl;

}