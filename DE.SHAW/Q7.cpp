#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    //constructor
    Node(int val){
        this->data=val;
        this->right=NULL;
        this->left=NULL;
    }
};
int solve(Node* root,int l,int h){
    int count=0;
    if(root==NULL)return count;
    if(root->data>=l && root->data<=h)count++;
    return count + solve(root->left,l,h) +solve(root->right,l,h);
}
int getCount(Node* head,int l,int h){
    return solve(head,l,h);
}
int main(){
    Node* head=new Node(10);
    head->left=new Node(5);
    head->right=new Node(50);
    head->left->left=new Node(1);
    head->right->left=new Node(40);
    head->right->right=new Node(100);
// minimum range of nodes
    cout<<"Enter the low  range :"<<endl;
    int l;
    cin>>l;
    // maximum range of nodes
    cout<<"Enter the high  range :"<<endl;
    int h;
    cin>>h;
    cout<<getCount(head,l,h)<<" nodes exists in Given tree "<<endl;

}