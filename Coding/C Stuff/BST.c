//
//  7.c
//  Lab Programs
//
//  Created by Surya Dheeshjith on 07/12/18.
//  Copyright © 2018 Surya Dheeshjith. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

typedef struct node node;

node* insertBST(node* root,int ele)
{
    node* prev,*cur;
    node* newnode = (node*)malloc(sizeof(node));
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->data = ele;
    if(root==NULL)
    {
        return newnode;
    }
    cur = root;
    while(cur)
    {
        prev = cur;
        if(cur->data<ele)
        {
            cur = cur->right;
        }
        else{
            cur = cur->left;
        }
    }
    if(ele>prev->data)
    {
        prev->right=newnode;
    }
    else{
        prev->left = newnode;
    }
    return root;
}
node* findMin(node* root)
{
    while(root->left)
    {
        root=root->left;
    }
    return root;
}
node* deleteBST(node* root,int key)
{
    node* temp;
    if(root==NULL)
        return NULL;
    if(key>root->data)
    {
        root->right=deleteBST(root->right,key);
    }
    else if(key<root->data)
    {
        root->left = deleteBST(root->left,key);
    }
    
    else
    {
        if(root->left==NULL&&root->right==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left==NULL)
        {
            temp = root;
            root = root->right;
            return(root);
            free(temp);
        }
        else if(root->right==NULL)
        {
            temp = root;
            root = root->right;
            return(root);
            free(temp);
        }
        else
        {
            temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteBST(root->right,temp->data);
            
        }
    }
    return(root);
}

void inorder(node* root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
    printf("\n");
}

void preorder1(node* root)
{
    if(root)
    {
        printf("%d ",root->data);
        preorder1(root->left);
        preorder1(root->right);
    }
    printf("\n");
}

void postorder1(node* root)
{
    if(root)
    {
        postorder1(root->left);
        postorder1(root->right);
        printf("%d ",root->data);
    }
    printf("\n");
}

int main()
{
    node* root=NULL;
    int ch,ele;
    printf("Enter operation : 1. insert 2. Delete 3. Inorder 4. Preorder 5. Postorder\n");
    while(1)
    {
        printf("Enter choice - ");
        scanf("%d",&ch);
        switch(ch)
        {
                
            case 1:
                printf("\nEnter element ");
                scanf("%d",&ele);
                root = insertBST(root,ele);
                break;
            case 2:
                printf("Enter element ");
                scanf("%d",&ele);
                root = deleteBST(root,ele);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                preorder1(root);
                break;
            case 5:
                postorder1(root);
                break;
            case 6:
                exit(0);
            default:
                printf("Enter valid choice\n");
        }
    }
}
