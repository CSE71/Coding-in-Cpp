//
//  19.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 06/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
// Detect Loops


// If N is given i.e here it is 300
//Cheap method :")
/*
    // C program to detect loop in a linked list
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
    using namespace std;
 
    struct Node {
        int data;
        struct Node *next;
        Node(int x) {
            data = x;
            next = NULL;
        }
    };
    void push(struct Node **head_ref, int new_data) {
        struct Node *new_Node = new Node(new_data);
        new_Node->next = (*head_ref);
 
        (*head_ref) = new_Node;
    }
    int detectloop(struct Node *list);
 
    int main() {
        int t, n, c, x, i;
        cin >> t;
        while (t--) {
 
            cin >> n;
            struct Node *head = NULL;
            struct Node *temp;
            struct Node *s;
            cin >> x;
            push(&head, x);
            s = head;
            for (i = 1; i < n; i++) {
                cin >> x;
                push(&head, x);
            }
 
            cin >> c;
            if (c > 0) {
                c = c - 1;
                temp = head;
                while (c--) temp = temp->next;
                s->next = temp;
            }
            int g = detectloop(head);
            if (g)
            cout << "True
            ";
            else
            cout << "False
            ";
        }
        return 0;
    }
 

/*This is a function problem.You only need to complete the function given below*/

/*
 struct Node {
 int data;
 struct Node *next;
 Node(int x) {
 data = x;
 next = NULL;
 }
 */
/*
int detectloop(Node *head) {
    
    // your code here
    Node* temp = head;
    Node* checkme=head;
    int i=0;
    while(checkme)
    {
        temp = checkme->next;
        i=0;
        while(temp)
        {
            if(temp->next==checkme)
            return 1;
            
            temp = temp->next;
            i++;
            if(i>300)
            {
                return 1;
            }
        }
        checkme = checkme->next;
    }
    
    
}
*/


// Brilliant method


int detectloop(Node *head) {
    
    // your code here
    Node* slow = head;
    Node* fast=head;
    
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast)
        return 1;
    }
    return 0;
    
}
