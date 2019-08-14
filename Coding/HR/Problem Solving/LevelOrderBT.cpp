
//
//  Coding
//
//  Created by Surya Dheeshjith on 07/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
//Print level wise node data in binary tree

void levelOrder(Node * root){
    //Write your code here
    Node* temp = root;
    queue<Node*> q;
    while(temp)
    {
        cout<<temp->data<<" ";
        if(temp->left)q.push(temp->left);
        if(temp->right)q.push(temp->right);
        
        if(!q.empty())
        {
            temp = q.front();
            q.pop();
        }
        else
            temp = NULL;
    }
    
    
}
