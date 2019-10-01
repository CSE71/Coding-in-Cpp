//
//  35.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 10/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
// Print top view of tree

#include</Users/suryad/Coding/Coding/Coding/stdc++.h>

using namespace std;
/* A binary tree node has data, pointer to left child
 and a pointer to right child */
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
void verticalOrder(Node *root);
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
                    verticalOrder(root);
                    cout << endl;
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
               };
               */
void verticalOrder(Node *root)
{
  //Your code
  
  map<int,vector<int>>mp;
  queue<pair<Node*,int>> q;
  q.push({root,0});
  
  while(!q.empty())
  {
      pair<Node*,int> t = q.front();
      Node* temp = t.first;
      int dist = t.second;
      mp[dist].push_back(temp->data);
      q.pop();
      
      if(temp->left)
      {
          q.push({temp->left,dist-1});
      }
      
      if(temp->right)
      {
          q.push({temp->right,dist+1});
      }
      
      
      
  }
  
  for(auto i = mp.begin();i!=mp.end();i++)
  {
      vector<int> temp = i->second;
      for(auto x:temp)
      {
          cout<<x<<" ";
      }
  }
}
