//

//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.

// Find merge point

int find(SinglyLinkedListNode* temp1, SinglyLinkedListNode* temp2)
{
    while(temp1 && temp2)
    {
        if(temp1==temp2)
        return temp1->data;

        temp1=temp1->next;
        temp2=temp2->next;
    }
    
    return -1;
}
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    SinglyLinkedListNode *temp1,*temp2;
    temp1 = head1;
    temp2 = head2;

    int len1=0,len2=0;
    while(temp1)
    {
        temp1=temp1->next;
        len1++;
    }
    while(temp2)
    {
        temp2=temp2->next;
        len2++;
    }

    int d = len1-len2;
    temp1 = head1;
    temp2 = head2;
    if(d==0)
    {
        return find(temp1,temp2);
    }
    else if(d<0)
    {
        int rem = -d;
        while(rem>0)
        {temp2=temp2->next;rem--;}

        return find(temp1,temp2);
      
    }
    else
    {
        int rem = d;
        while(rem>0)
        {temp1=temp1->next;rem--;}

        return find(temp1,temp2);
       
    }

}
