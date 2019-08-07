//
//  20.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 06/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

//Removing Loop

void removeTheLoop(Node* head)
{
    
    if (detectloop(head) == 0)      // If loop doesn't exist return
    return;
    
    Node* slow = head;
    Node* fast=head;
    
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast)
        {
            Node* begin = head;
            
            while (1)
            {
                
                begin = begin->next;
                if (slow->next == begin)    // Find the position of the loop and mark the node as null
                {
                    slow->next = NULL;
                    return;
                }
                slow = slow->next;
                
                
            }
        }
    }
    
    
    
}
