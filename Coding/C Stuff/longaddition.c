//
//  5.c
//  Lab Programs
//
//  Created by Surya Dheeshjith on 11/11/18.
//  Copyright © 2018 Surya Dheeshjith. All rights reserved.
//


#include <stdio.h>
#include<string.h>
struct node{
    int data;
    struct node* next;
};

typedef struct node node;

node* insertend(node* h,int data)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    
    if(h==h->next)
    {
        h->next = newnode;
        newnode->next = h;
        return h;
    }
    node* temp=h;
    while(temp->next!=h)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=h;
    return h;
    
    
}

node* insertbegin(node* head,int data)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    
    if(head==head->next)
    {
        head->next=newnode;
        newnode->next=head;
        return head;
    }
    
    newnode->next=head->next;
    head->next=newnode;
    return head;
}

void display(node* head)
{
    if(head==head->next)
        printf("Empty");
    
    node* temp= head->next;
    while(temp!=head)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

node* reverse(node* head)
{
    node* prev=head,*cur=head->next,*next;
    while(cur!=head)
    {
        next = cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    head->next=prev;
    return head;
}
void add(node* h1,node* h2)
{
    node* h,*t1,*t2;
    t1= h1;
    t2 = h2;
    h=(node*)malloc(sizeof(node));
    h->next=h;
    
    
    t1 = reverse(t1);
    t2= reverse(t2);
    
    t1 = t1->next;
    t2=t2->next;
    int carry=0,x,sum;
    while(t1!=h1&&t2!=h2)
    {
        x = t1->data+t2->data+carry;
        sum = x%10;
        carry = x/10;
        h = insertend(h,sum);
        t1=t1->next;
        t2=t2->next;
    }
    if(carry>0)
        h=insertend(h,carry);
    h = reverse(h);
    display(h);
    
    
}

int main()
{
    node* h1;
    node* h2;
    h1 = (node*)malloc(sizeof(node));
    h2 = (node*)malloc(sizeof(node));
    h1->next=h1;
    h2->next=h2;
    h1->data=0;
    h2->data=0;
    
    char num1[50],num2[50];
    printf("Enter the first number - ");
    scanf("%s",num1);
    printf("Enter the second number - ");
    scanf("%s",num2);
    
    int i;
    for(i=0;num1[i];i++)
        h1= insertend(h1,num1[i]-'0');
    
    for(i=0;num2[i];i++)
        h2= insertend(h2,num2[i]-'0');
    
    int l1,l2;
    l1=strlen(num1);
    l2=strlen(num2);
    
    if(l1<l2)
    {
        for(i=1;i<=l2-l1;i++)
            h1=insertbegin(h1,0);
    }
    
    else
    {
        for(i=1;i<=l1-l2;i++)
            h2=insertbegin(h2,0);
    }
    display(h1);
    display(h2);
    
    add(h1,h2);
    
}
