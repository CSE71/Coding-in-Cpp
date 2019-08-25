//

//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.

// Inserting a Node Into a particular position


SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    
    SinglyLinkedListNode* temp = head;
    int i=0;
    while(i<position-1)
    {
        temp = temp->next;
        i++;
    }
    SinglyLinkedListNode* nex = temp->next;
    SinglyLinkedListNode* node = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    node->data = data;
    temp->next = node;
    node->next = nex;
    return head;
    
}

