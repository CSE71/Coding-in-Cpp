
//  Coding
//
//  Created by Surya Dheeshjith on 07/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

//Divide the LL by two and reverse both sides. If odd elements, the middle element stays.
// 1->2->3->4->5->6 == > 3->2->1->6->5->4
// 1->2->3->30->4->5->6 == > 3->2->1->30->6->5->4
#include</Users/suryad/Coding/Coding/Coding/stdc++.h>
using namespace std;

typedef struct node{
    
    int data;
    struct node* next;
}node;

node* insertnode(node* head,int ele)
{
    node* newnode = new node;
    newnode->next = NULL;
    newnode->data = ele;
    if(!head)
        return newnode;
    
    node* temp = head;
    while(temp->next)
        temp = temp->next;
    
    temp->next = newnode;
    return head;
}


node* reverseinG(node* head,int k,int flag)
{
    node* temp =head,*prev = NULL,*after;
    int count=0;
    while(temp && count<k)
    {
        count++;
        after = temp->next;
        temp->next = prev;
        prev = temp;
        temp = after;
    }
    
    if(temp)
    {
        if(!flag)
            head->next = reverseinG(temp,k,flag);
        else
        {
            head->next = temp;
            temp->next = reverseinG(temp->next,k,flag);
            
        }
            
    }
        
    
    return prev;
}

int main()
{
    node* head = NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        head = insertnode(head,ele);
    }
    //int k;
    //cin>>k;
    int flag;
    
    if(n%2==0)
        flag =0;
    else
        flag=1;
    
    head = reverseinG(head,n/2,flag);
    
    node* temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    
    
    
}

