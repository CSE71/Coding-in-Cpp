//
//  37.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 10/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

//To connect level wise nodes

#include</Users/suryad/Coding/Coding/Coding/stdc++.h>

using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* nextRight;
    Node(int x){
        data = x;
        left = right = NULL;
        nextRight = NULL;
    }
};
void connect(struct Node *p);
/* Helper function that allocates a new node with the
 given data and NULL left and right pointers. */
void printSpecial(Node *root)
{
    if (root == NULL)
        return;
    Node *node = root;
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->nextRight;
    }
    if (root->left)
        printSpecial(root->left);
    else
        printSpecial(root->right);
}
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
/* Driver program to test size function*/
int main()
{
    int t;
    scanf("%d", &t);
          while (t--)
          {
              map<int, Node*> m;
              int n;
              scanf("%d",&n);
              struct Node *root = NULL;
              struct Node *child;
              while (n--)
              {
                  Node *parent;
                  char lr;
                  int n1, n2;
                  scanf("%d %d %c", &n1, &n2, &lr);
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
              connect(root);
              printSpecial(root);
              printf("");
                     inorder(root);
                     printf("");
                            }
                            return 0;
                            }
                            
                            
              /*This is a function problem.You only need to complete the function given below*/
              /* struct Node
               {
               int data;
               Node *left,  *right;
               Node *nextRight;  // This has garbage value in input trees
               }; */
                            // Should set the nextRight for all nodes
                            void util(Node* root,int l,map<int,vector<Node*>> &temp)
              {
                  if(root==NULL)
                      return;
                  
                  temp[l].push_back(root);
                  util(root->left,l+1,temp);
                  util(root->right,l+1,temp);
                  
                  
                  
              }
                            void connect(Node *root)
              {
                  if(root==NULL)
                      return;
                  map<int,vector<Node*>> mp;
                  util(root,0,mp);
                  for(auto i = mp.begin();i!=mp.end();i++)
                  {
                      for(int j=0;j<i->second.size();j++)
                      {
                          if(j==i->second.size()-1)
                          {
                              i->second[j]->nextRight = NULL;
                          }
                          else
                          {
                              i->second[j]->nextRight = i->second[j+1];
                          }
                      }
                  }
                  
                  
              }
