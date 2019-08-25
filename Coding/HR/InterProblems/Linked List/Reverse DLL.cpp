//

//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.

// Reverse a DLL


DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    
    DoublyLinkedListNode* temp,*prev,*next;
    prev = NULL;
    temp = head;
    
    while(temp)
    {
        next = temp->next;
        temp->next = prev;
        temp->prev = next;
        prev = temp;
        temp = next;
        
    }
    return prev;
    
}
