
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

node* insert(node* head,int ele)
{
    node* newnode = new node;
    newnode->data = ele;
    newnode->next = NULL;
    if(head==NULL)
    return newnode;
    
    else
    {
        node* temp=head;
        while(temp->next)
        temp = temp->next;
        
        temp->next = newnode;
        
    }
    return head;
}

node* reversehalf(node* head)
{
    node* slow=head,*fast=head;
    node* prev = NULL;
    node* after = slow->next;
    int count =0;
    while(fast->next && fast->next->next)
    {
        //slow=slow->next;
        //cout<<slow->data;
        count++;
        fast = fast->next->next;
        after = slow->next;
        slow->next = prev;
        prev = slow;
        slow = after;
        
        
    }
    
    node* p1 = prev;
    node* p = slow;
    if(count%2!=0)
    {
        head->next = slow;
        prev = NULL;
        slow = slow->next;
        while(after)
        {
            after = slow->next;
            slow->next = prev;
            prev = slow;
            slow = after;
            
            
        }
        p->next = prev;
    }
    
    else
    {
        p1 = after;
        node* p2 = after->next;
        p1->next = prev;
        prev=NULL;
        slow = p2;
        while(after)
        {
            after = slow->next;
            slow->next = prev;
            prev = slow;
            slow = after;
        }
        
        head->next = prev;
    
    }
    
    return p1;
}

int main()
{
    int n;
    cin>>n;
    int ele;
    node* head=NULL;
    
    
    for(int i=0;i<n;i++)
    {
        cin>>ele;
        head = insert(head,ele);
    }
    
    head = reversehalf(head);
    node* temp = head;
    while(temp)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
}

