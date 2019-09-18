//

//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.

//Huffman Decoding
//INPUT : 100100 , root
//OUTPUT: ABCAB

void decode_huff(node * root, string s)
{
    node*temp=root;
    int i=0;
    for(i=0;i<=s.size();i++)
    {
        if(temp->right==NULL && temp->left==NULL)
        {
            cout<<temp->data;
            temp=root;
        }
        if(s[i]=='0')
            temp=temp->left;
        else if(s[i]=='1')
            temp=temp->right;
    }
}
