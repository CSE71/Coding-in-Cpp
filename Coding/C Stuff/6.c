//
//  6.c
//  Lab Programs
//
//  Created by Surya Dheeshjith on 11/11/18.
//  Copyright © 2018 Surya Dheeshjith. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    int col;
    int row;
    struct node* left;
    struct node* right;
};

typedef struct node node;

node* insertd(node* n, int row, int col, int ele)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->left = NULL;
    newnode->right=NULL;
    newnode->row = row;
    newnode->col = col;
    newnode->data = ele;
    if(n==NULL)
    {
        return newnode;
    }
    node* cur = n;
    while(cur->right)
    {
        cur = cur->right;
    }
    cur->right = newnode;
    newnode->left=cur;
    return n;
}
void displaymatrix(node* n,int m,int n1)
{
    int i,j;
    for(i = 0;i<m;i++)
    {
        for(j = 0; j<n1 ;j++)
        {
            if(n->row==i&&n->col==j&&n)
            {
                printf("%d\t",n->data);
                n= n->right;
            }
            else{
                printf("0\t");
            }
        }
        printf("\n");
    }
}
int main()
{
    node* nod=NULL;
    int m,n,i,j,ch;
    printf("Enter order of matrix - ");
    scanf("%d %d",&m,&n);
    printf("Enter the values \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&ch);
            if(ch!=0)
            {
                nod = insertd(nod,i,j,ch);
            }
        }
    }
    
    displaymatrix(nod,m,n);
    
}
