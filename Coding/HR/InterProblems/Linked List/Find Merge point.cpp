//

//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.

// Find merge point


int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    
    SinglyLinkedListNode *temp1,*temp2;
    temp1 = head1;
    temp2 = head2;
    while(temp1)
    {
        temp2 = head2;
        while(temp2)
        {
            if(temp1==temp2)
            return temp1->data;
            
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return -1;
}
