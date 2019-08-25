//

//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.

// Height of binary tree

int height(Node* root) {
    // Write your code here.
    if(root==NULL)
    return -1;
    
    int l = 1+height(root->left);
    int r = 1+height(root->right);
    if(l<r)
    return r;
    
    else
    return l;
}
