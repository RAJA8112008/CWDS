// Binary tree Level order Traversal
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// class for Node creation
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    // constructor to initilize the node
    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<int> LevelTraversal(Node *root)
{
    // queue creation to store the each level
    queue<Node *> q;
    // insertion in queue root Node
    // vector to store the values
    vector<int> ans;
    q.push(root);
    // while queue dosent empty
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            // getting node from the queue
            Node *temp = q.front();
            q.pop();
            ans.push_back(temp->data);
            // if lefdt exits of root node
            if (temp->left)
            {
                q.push(temp->left);
            }
            // right exits the n
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    };
    return ans;
}
int main()
{
    // tree Creation
    Node *root = new Node(5);
    root->left = new Node(6);
    root->right = new Node(9);
    root->left->left = new Node(7);
    root->left->right = new Node(8);
    root->right->left = new Node(10);
    root->right->right = new Node(11);
    root->left->left->left = new Node(12);
    root->left->right->left = new Node(13);
    vector<int> ans = LevelTraversal(root);
    cout << "Level Order  Traversal is:" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}