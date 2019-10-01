//
//  14.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 05/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//


//Middle element of LL


    // C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
    using namespace std;
    /* Link list Node */
    struct Node
    {
        int data;
        struct Node* next;
    };
int getMiddle(Node *head);
    void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
    {
        struct Node* new_node = new Node;
        new_node->data  = new_data;
        new_node->next = NULL;
        if (*head_ref == NULL)
        *head_ref = new_node;
        else
        (*tail_ref)->next = new_node;
        *tail_ref = new_node;
    }
    /* Function to get the middle of the linked list*/
    int getMiddle(struct Node *head);
    /* Driver program to test above function*/
    int main()
    {
        int T,i,n,l;
        cin>>T;
        while(T--){
            struct Node *head = NULL,  *tail = NULL;
            cin>>n;
            for(i=1;i<=n;i++)
            {
                cin>>l;
                append(&head, &tail, l);
            }
            printf("%d", getMiddle(head));
                   }
                   return 0;
                   }
                   
                   
            /*This is a function problem.You only need to complete the function given below*/
            /* Link list Node
             struct Node {
             int data;
             Node* next;
             }; */
            /* Should return data of middle node. If linked list is empty, then  -1*/
                   int getMiddle(Node *head)
            {
                if(head==NULL)
                return -1;
                Node* temp = head;
                int k=0;
                while(temp)
                {
                    k++;
                    temp=temp->next;
                }
                
                k=k/2+1;
                
                temp=head;
                int i=1;
                while(i<k)
                {
                    temp=temp->next;
                    i++;
                }
                return temp->data;
            }


// Better way to use slow and fast pointer.

// To get kth pointer from end. Take one pointer and go till kth pointer from beginning. Then take another pointer and traverse both untill the first pointer reaches the end.
