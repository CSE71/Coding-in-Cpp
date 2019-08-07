//
//  CountLeaves.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 11/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

int countLeaves(Node* root)
{
    
    // Your code here
    if(root==NULL)
        return 0;
    
    if(root->left==NULL && root->right==NULL)
        return 1;
    
    return countLeaves(root->left) + countLeaves(root->right);
}
