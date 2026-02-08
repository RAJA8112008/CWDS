#include<iostream>
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

bool areMirror(Node* a,Node* b){
    //base cases 
    if(a==NULL  && b==NULL)return true;
    if((a!=NULL && b==NULL)||(a==NULL && b!=NULL))return false;
    if(a->data!=b->data)return false;
    return areMirror(a->left,b->right) && areMirror(a->right,b->left);
}
int main(){
    //LeftTree
    //     1
    //    / \
    //   3   2
    //      / \
    //     5   4



Node* root=new Node(1);
 root->left=new Node(3);
 root->right=new Node(2);                     
 root->right->left=new Node(5);
  root->right->right=new Node(4);
  //RightTree
    //     1
    //    / \
    //   2   3
    //  /     \
    // 4       5

  Node* root2=new Node(1);
  root2->right=new Node(3);
  root2->left=new Node(2);
  root2->left->left=new Node(4);
  root2->right->right=new Node(5);

  cout<<(areMirror(root,root2)?"Yes":"NO")<<endl;
}