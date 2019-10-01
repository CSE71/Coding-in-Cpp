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
void bottomView(Node *root);
/* Driver program to test size function*/
int main()
{
    int t;
    struct Node *child;
    scanf("%d
          ", &t);
          while (t--)
          {
              map<int, Node*> m;
              int n;
              scanf("%d
                    ",&n);
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
                    bottomView(root);
                    cout << endl;
                    }
                    return 0;
                    }
                    
                    
              /*This is a function problem.You only need to complete the function given below*/
              /* Tree node class
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
               }; */
                    // Method that prints the bottom view.

void bottomView(Node *root)
{
    if (root == NULL)
        return;
    
    // Initialize a variable 'hd' with 0
    // for the root element.
    int hd = 0;
    
    // TreeMap which stores key value pair
    // sorted on key value
    map<int, int> m; // To sort based on hd
    map<Node  *, int> mh; // To hold hd
    
    // Queue to store tree nodes in level
    // order traversal
    queue<Node *> q; // for traversal
    
    // Assign initialized horizontal distance
    // value to root node and add it to the queue.
    mh[root] = hd;
    q.push(root);
    
    // Loop until the queue is empty (standard
    // level order loop)
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        
        // Extract the horizontal distance value
        // from the dequeued tree node.
        hd = mh[temp];
        
        // Put the dequeued tree node to TreeMap
        // having key as horizontal distance. Every
        // time we find a node having same horizontal
        // distance we need to replace the data in
        // the map.
        m[hd] = temp->data; // Keeps getting overwritten
        
        // If the dequeued node has a left child add
        // it to the queue with a horizontal distance hd-1.
        if (temp->left != NULL)
        {
            mh[temp->left] = hd-1;
            q.push(temp->left);
        }
        
        // If the dequeued node has a left child add
        // it to the queue with a horizontal distance
        // hd+1.
        if (temp->right != NULL)
        {
            mh[temp->right] = hd+1;
            q.push(temp->right);
        }
    }
    
    // Traverse the map elements using the iterator.
    for (auto i = m.begin(); i != m.end(); ++i)
        cout << i->second << " ";
}
