//
//  23.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 07/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

// Merge multiple sorted linked lists
Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if(b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if(a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }

    return result;
}

// The main function that takes an array of lists
// arr[0..last] and generates the sorted output
Node* mergeKLists(Node* arr[], int N)
{
    int last=N-1; // last index in array
    // repeat until only one list is left
    int i = 0, j = last;
    while (last != 0)
    {  
        // merge List i with List j and store
        // merged list in List i
        arr[i] = SortedMerge(arr[i], arr[j]);

        // consider next pair
        i++, j--;

        // If all pairs are merged, update last
        if (i >= j){
            i=0;
            last = j;
          }

    }

    return arr[0];
}
