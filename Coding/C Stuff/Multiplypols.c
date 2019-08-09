//
//  4.c
//  Lab Programs
//
//  Created by Surya Dheeshjith on 11/11/18.
//  Copyright © 2018 Surya Dheeshjith. All rights reserved.
//

#include <stdio.h>


struct poly{
    int co;
    int exp;
    struct poly* next;
};

typedef struct poly poly;

poly* insertpoly(poly* p,int co,int exp)
{
    poly* newnode = (poly*)malloc(sizeof(poly));
    newnode->co=co;
    newnode->exp=exp;
    newnode->next=NULL;
    
    if(p==NULL)
        return newnode;
    
    poly* temp;
    temp = p;
    int flag=0;
    while(temp)
    {
        if(temp->exp==exp)
        {
            flag=1;
            temp->co=temp->co+co;
            return p;
        }
        temp=temp->next;
    }
    if(flag==0)
    {
        temp = p;
        while(temp->next)
            temp= temp->next;
        temp->next = newnode;
        
    }
    return p;
}

poly* multiplypol(poly* p1,poly* p2,poly* p)
{
    poly *t1=p1;
    poly* t2=p2;
    while(t1)
    {
        t2=p2;
        while(t2)
        {
            p = insertpoly(p,t1->co*t2->co,t1->exp+t2->exp);
            t2=t2->next;
        }
        t1=t1->next;
    }
    return p;
}

void displaypol(poly* p)
{
    poly *t;
    t = p;
    
    if(t==NULL)
    {
        printf("Empty polynomial");
    return;}
    while(t->next)
    {
        printf("%d.x^%d+",t->co,t->exp);
        t=t->next;
    }
    printf("%d.x^%d",t->co,t->exp);
}



int main()
{
    poly* p1=NULL;
    poly* p2=NULL;
    poly* p=NULL;
    int m,n,i,co,exp;
    printf("Enter the number of terms in poly 1 and 2");
    scanf("%d %d",&m,&n);
    
    printf("Enter the coeffiecients and exponents of p1");
    
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&co,&exp);
        p1 = insertpoly(p1,co,exp);
    }
    
    printf("Enter the coeffiecients and exponents of p2");
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&co,&exp);
        p2 = insertpoly(p2,co,exp);
    }
    
    displaypol(p1);
    displaypol(p2);
    
    p=multiplypol(p1,p2,p);
    displaypol(p);
}
