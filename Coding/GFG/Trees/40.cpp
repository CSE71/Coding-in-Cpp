//
//  40.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 11/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

//Two trees identical or not
bool isIdentical(Node *r1, Node *r2)
{
    //Your Code here
    
    if(r1==NULL && r2 ==NULL)
        return true;
    
    
    if(r1!=NULL && r2!=NULL)
    {
        if(r1->data == r2->data && isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right))
            return true;
    }
    else
        return false;
}
