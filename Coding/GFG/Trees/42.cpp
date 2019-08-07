//
//  42.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 11/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

//Height of tree

int height(Node* node)
{
    // Your code here
    if(node==NULL)
        return 0;
    
    int l = 1+height(node->left);
    int r = 1+height(node->right);
    
    if(l<r)
        return r;
    else
        return l;
}

