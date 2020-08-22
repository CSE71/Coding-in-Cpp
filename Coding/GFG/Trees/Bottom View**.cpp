//
//  34.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 10/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
// C++ Program to print Bottom View of Binary Tree
#include</Users/suryad/Coding/Coding/Coding/stdc++.h>
using namespace std;

// Tree node class
struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};

// Method that prints the bottom view.
void bottomView(Node *root)
{
    if(root==NULL)
        return;
    queue<pair<Node*,int>> q;
    map<int,int> mp;

    q.push({root,0});

    while(!q.empty())
    {
        pair<Node*,int> p = q.front();
        q.pop();

        Node* cur = p.first;
        int hd = p.second;
        mp[hd] = cur->data;

        if(cur->left)
        {
            q.push({cur->left,hd-1});
        }
        if(cur->right)
        {
            q.push({cur->right,hd+1});
        }

    }

    for(auto x=mp.begin();x!=mp.end();x++)
        cout<<x->second<<" ";



}

// Driver Code
int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    cout << "Bottom view of the given binary tree :\n";
    bottomView(root);
    return 0;
}
