
//  Coding
//
//  Created by Surya Dheeshjith on 12/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
// Check if string is palindrome when string given in linked list format
bool IsPalindrome(Node *curr)
{
    bool rc = false;
    static Node *head = curr;
    if(curr != NULL)
    {
        rc = IsPalindrome(curr->next);
    }
    else
    {
        return true;
    }
 
    if(rc)
    {
        if(curr->data == head->data)
        {
            head = head->next;
            rc = true;
        }
        else
        {
            rc = false;
        }
    }
 
    return rc;
}
