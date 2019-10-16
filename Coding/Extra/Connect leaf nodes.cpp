//
//  DistFromRoot.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 12/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
void FormDLLWithLeafNodes(Node *root)
{
    if(root == NULL)
        return;
    /*
      Again we are making use of In-Order traversal to achieve this.
      Since we are asked to connect leaf nodes from left to right,
      we can traverse through the tree using In-Order and check for
      leaf nodes and connect them as DLL. We can keep track of previous
      node using a static prevNode variable.
    */
    static Node* prevNode = NULL;
    FormDLLWithLeafNodes(root->lChild);
    // Check if it is a leaf node
    if( ( root->lChild == NULL ) &&
        ( root->rChild == NULL ) )
    {
        if(prevNode == NULL)
        {
            prevNode = root;
            cout<<root->data;
        }
        else
        {
            // Connect the leaf nodes here
            prevNode->rChild = root;
            root->lChild     = prevNode;
            prevNode         = root;
            
            cout<<"<=>"<<root->data;
        }
    }
    FormDLLWithLeafNodes(root->rChild);
}
