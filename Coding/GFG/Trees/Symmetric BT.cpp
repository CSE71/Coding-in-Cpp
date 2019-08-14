//
//  41.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 11/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

// Is binary tree symmetric


bool util(Node* r1,Node* r2)
{
    if(r1==NULL && r2==NULL)
    {
        return true;
    }
    
    if(r1!=NULL && r2!=NULL)
    {
        return r1->key == r2->key && util(r1->left,r2->right) && util(r1->right,r2->left);
    }
    else
        return false;
}
bool isSymmetric(struct Node* root)
{
    // Code here
    if(root==NULL)
        return true;
    
    return util(root->left,root->right);
}
