//
//  8.c
//  Lab Programs
//
//  Created by Surya Dheeshjith on 07/12/18.
//  Copyright © 2018 Surya Dheeshjith. All rights reserved.
//


#include <stdio.h>
#include<ctype.h>
#include<stdlib.h>

struct node{
    char data;
    struct node* left;
    struct node* right;
};

typedef struct node node;

int precedence(char ch)
{
    switch(ch)
    {
        case '^':
        case '$':return 4;
        case '/':
        case '*':return 3;
        case '+':
        case '-':return 2;
        default: return 1;
    }
}

node* createExpTree(node* root,char* exp)
{
    int k1=-1,k2=-1;
    node* opertree[15],*opndtree[15],*r,*l,*temp,*newnode;
    int i;
    for(i=0;exp[i];i++)
    {
        newnode = (node*)malloc(sizeof(node));
        newnode->left=NULL;
        newnode->right=NULL;
        newnode->data = exp[i];
        if(isalnum(exp[i]))
        {
            opndtree[++k1] = newnode;
        }
        else{
            if(k2==-1)
            {
                opertree[++k2]=newnode;
            }
            else{
                while(k2!=-1&&precedence(exp[i])<=precedence(opertree[k2]->data))
                {
                    temp = opertree[k2--];
                    r = opndtree[k1--];
                    l = opndtree[k1--];
                    temp->right = r;
                    temp->left=l;
                    opndtree[++k1]=temp;
                }
                opertree[++k2]=newnode;
            }
        }
    }
    while(k2!=-1)
    {
        temp = opertree[k2--];
        r = opndtree[k1--];
        l = opndtree[k1--];
        temp->right = r;
        temp->left=l;
        opndtree[++k1]=temp;
    }
    return opndtree[k1];
}

void inorder(node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%c",root->data);
        inorder(root->right);
    }
}

void preorder1(node* root)
{
    if(root!=NULL)
    {
        printf("%c",root->data);
        preorder1(root->left);
        preorder1(root->right);
    }
}

void postorder1(node* root)
{
    if(root!=NULL)
    {
        postorder1(root->left);
        postorder1(root->right);
        printf("%c",root->data);
    }
}
int main()
{
    node* root=NULL;
    char exp[50];
    int ch;
    printf("Enter choice - 1. Create 2. Inorder 3. preorder 4. postorder 5. exit\n");
    while(1)
    {
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter expression - ");
                getchar();
                gets(exp);
                root = createExpTree(root,exp);
                printf("%c",root->data);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                preorder1(root);
                break;
            case 4:
                postorder1(root);
                break;
            case 5: exit(0);
            default: printf("Enter valid choice\n");
        }
    }
    
}
