//

//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.

// Lowest common ancestor

Node *lca(Node *root, int v1,int v2) {
    // Write your code here.
    if(root==NULL)
    return NULL;
    
    if(v1<root->data && v2<root->data)
    return lca(root->left,v1,v2);
    
    if(v1>root->data && v2>root->data)
    return lca(root->right,v1,v2);
    
    return root;
    
}

