//
//  36.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 10/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
//To Print Tree in spiral form


#include</Users/suryad/Coding/Coding/Coding/stdc++.h>

using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
void printSpiral(struct Node *root);
/* Driver program to test above functions*/
int main()
{
    int t;
    scanf("%d", &t);
          while (t--)
          {
              map<int, Node*> m;
              int n;
              scanf("%d",&n);
                    Node *root = NULL;
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
                        Node *child = new Node(n2);
                        if (lr == 'L')
                            parent->left = child;
                        else
                            parent->right = child;
                        m[n2]  = child;
                    }
                    printSpiral(root);
                    cout<<endl;
                    }
                    return 0;
                    }
                    
                    
              /*This is a function problem.You only need to complete the function given below*/
              /* A binary tree node has data, pointer to left child
               and a pointer to right child
               struct Node
               {
               int data;
               struct Node* left;
               struct Node* right;
               
               Node(int x){
               data = x;
               left = right = NULL;
               }
               }; */
    // Function to find height of the binary tree
    
int height(struct Node* root)
{
  if(root==NULL)
      return 0;
  
  int l = 1 + height(root->left);
  int r = 1 + height(root->right);
  if(l>r)
      return l;
  else
      return r;
}
    
void spiral(struct Node* root,int level,int flag)
{
  if(root==NULL)
      return;
  
  if(level==1)
      cout<<root->data<<" ";
  
  else
  {
      if(flag)
      {
          spiral(root->left,level-1,flag);
          spiral(root->right,level-1,flag);
      }
      else
      {
          spiral(root->right,level-1,flag);
          spiral(root->left,level-1,flag);
      }
  }
}
    
void printSpiral(struct Node *root)
{
  int maxh = height(root);
  int flag=0;
  for(int i=1;i<=maxh;i++)
  {
      spiral(root,i,flag);
      flag = !flag; // Changes direction
  }
}
