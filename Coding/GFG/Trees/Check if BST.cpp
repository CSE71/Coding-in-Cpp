//
//  33.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 10/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//Check if BST

#include</Users/suryad/Coding/Coding/Coding/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
 and a pointer to right child */
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
/* Returns true if the given tree is a binary search tree
 (efficient version). */
bool isBST(struct Node* node);
int isBSTUtil(struct Node* node, int min, int max);
/* Driver program to test size function*/
int main()
{
    int t;
    struct Node *child;
    scanf("%d", &t);
          while (t--)
          {
              map<int, Node*> m;
              int n;
              scanf("%d",&n);
                    struct Node *root = NULL;
                    while (n--)
                    {
                        Node *parent;
                        char lr;
                        int n1, n2;
                        scanf("%d %d %c", &n1, &n2, &lr);
                        //  cout << n1 << " " << n2 << " " << (char)lr << endl;
                        if (m.find(n1) == m.end())
                        {
                            parent = new Node(n1);
                            m[n1] = parent;
                            if (root == NULL)
                                root = parent;
                        }
                        else
                            parent = m[n1];
                        child = new Node(n2);
                        if (lr == 'L')
                            parent->left = child;
                        else
                            parent->right = child;
                        m[n2]  = child;
                    }
                    cout << isBST(root) << endl;
                    }
                    return 0;
                    }
                    
                    
              /*This is a function problem.You only need to complete the function given below*/
              /* A binary tree node has data, pointer to left child
               and a pointer to right child
               struct Node {
               int data;
               Node* right;
               Node* left;
               
               Node(int x){
               data = x;
               right = NULL;
               left = NULL;
               }
               }; */
                    
    
int BST(Node* root, int min,int max)
{
  if(root==NULL)
  return 1;
  
  if(root->data<min || root->data>max)
  return 0;
  
  return BST(root->left,min,root->data-1) && BST(root->right,root->data+1,max);
}
    
bool isBST(Node* root)
{
    // Your code here
    return(BST(root,INT_MIN,INT_MAX));
}
    
