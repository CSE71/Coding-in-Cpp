//

//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.

// Does loop exist
bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    if(head==NULL)
    return 0;
    Node* temp,*temp1;
    temp = head;
    temp1 = head->next;
    
    while(temp1->next)
    {
        if(temp==temp1)
        return 1;
        temp = temp->next;
        temp1= temp1->next->next;
    }
    return 0;
}
