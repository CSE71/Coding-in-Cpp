//
//  DistFromRoot.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 12/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
#include <iostream>

using namespace std;



typedef struct Node{
    
    char data;
    struct Node* left;
    struct Node* right;
}Node;


Node* newNode(char ch)
{
    Node* newnode  = (Node*)malloc(sizeof(Node));
    newnode->data = ch;
    newnode->left = newnode->right = NULL;
    return newnode;
}


int lengthutil(Node* root,char ch,int level)
{
    if(root==NULL)
        return -1;
    
    if(root->data==ch)
        return level;
    
    int k = lengthutil(root->left,ch,level+1);
    if(k==-1)
        k =lengthutil(root->right,ch,level+1);
    return k;
}
int lengthfromroot(Node *root, char x)
{

    return lengthutil(root,x,0);
}
int main()
{
    // Let us construct the BST shown in the above figure
    struct Node *root        = newNode('A');
    root->left               = newNode('B');
    root->right              = newNode('C');
    root->right->left        = newNode('E');
    root->right->right       = newNode('F');
    root->right->left->left  = newNode('G');
    root->right->left->left->left  = newNode('I');
    root->right->left->left->right = newNode('J');
    root->right->right->right      = newNode('H');
    root->right->right->right->left = newNode('K');
    
    char k = 'H';
    cout << "Distace to key " << k << " is "<< lengthfromroot(root, k) << endl;
    k = 'C';
    cout << "Distace to key " << k << " is "<< lengthfromroot(root, k) << endl;
    k = 'E';
    cout << "Distace to key " << k << " is "<< lengthfromroot(root, k) << endl;
    k = 'B';
    cout << "Distace to key " << k << " is "<< lengthfromroot(root, k) << endl;
    
    return 0;
}
