//

//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.

// Inserting a Node Into a Sorted Doubly Linked List

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    
    DoublyLinkedListNode* node = (DoublyLinkedListNode*)malloc(sizeof(DoublyLinkedListNode));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    if(head==NULL)
    return node;
    
    if(data<head->data)
    {
        node->next = head;
        head->prev = node;
        return node;
    }
    DoublyLinkedListNode* temp = head;
    DoublyLinkedListNode* prev;
    while(temp!=NULL&&data>temp->data)//Ordering important.
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = node;
    node->prev = prev;
    
    if(temp!=NULL)
    {
        node->next = temp;
        temp->prev=node;
    }
    
    
    return head;
}
