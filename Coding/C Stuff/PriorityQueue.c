//
//  10.c
//  Lab Programs
//
//  Created by Surya Dheeshjith on 11/11/18.
//  Copyright © 2018 Surya Dheeshjith. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>

int addVertex(int minHeap[], int size, int newValue)
{
    ++size;
    minHeap[size] = newValue;
    int i = size;
    int temp;
    while (i > 1) {
        if (minHeap[i / 2] > minHeap[i]) {
            // Parent node is greater than Child Node
            // Heap Property violated
            // So, swap
            temp = minHeap[i / 2];
            minHeap[i / 2] = minHeap[i];
            minHeap[i] = temp;
            i = i / 2;
        } else {
            // Parent is less or equal to the child
            // Heap property not violated
            // So, Insertion is done, break
            break;
        }
    }
    return size;
    
    
    
}
void heapify(int minHeap[], int size, int index)
{
    int i = index;
    int temp;
    while ((2 * i) <= size)//Children exist(either left child or both )
    {
        // Left Child exists. (Right child cannot exist on its own)[second last level]
        if ((2 * i) + 1 > size)
        {
            // Right child does not exist, but left does
            if (minHeap[i] > minHeap[2 * i])
            {
                // Left child is smaller than parent
                temp = minHeap[i];
                minHeap[i] = minHeap[2 * i];
                minHeap[2 * i] = temp;
            }
            break;
            // Once you reach this level where it does not
            // have a right child, the heap ends here
            // taking it to the next iteration is pointless
        }
        //Both Children exist
        if (minHeap[i] > minHeap[2 * i] || minHeap[i] > minHeap[2 * i + 1])//Parent greater than atleast one child
        {
            // One of the other child is lesser than parent
            // Now find the least amoung 2 children
            if (minHeap[2 * i] <= minHeap[(2 * i) + 1])
            {
                // Left Child is lesser, so, swap
                temp = minHeap[2 * i];
                minHeap[2 * i] = minHeap[i];
                minHeap[i] = temp;
                // And go down the heap
                i = 2 * i;
            }
            
            else if (minHeap[2 * i] > minHeap[(2 * i) + 1])
            {
                // Left Child is lesser, so, swap
                temp = minHeap[(2 * i) + 1];
                minHeap[(2 * i) + 1] = minHeap[i];
                minHeap[i] = temp;
                // And go down the heap
                i = (2 * i) + 1;
            }
        }
        else
        {
            // Parent is lesser than its children
            
            break;
        }
    }
}
int deleteVertex(int minHeap[], int size, int index)
{
    if (index < 1 || index > size) {
        return size;
    }
    // Swap the indexed element with the last
    int temp = minHeap[index];
    minHeap[index] = minHeap[size];
    minHeap[size] = temp;
    int i = index;
    --size;
    // check conditions
    
    int swappedElement = minHeap[index];
    int parent = minHeap[index / 2];
    
    if (swappedElement > parent || i == 1)
    {
        heapify(minHeap, size, index);
    }
    
    else
    {
        while (minHeap[index] < minHeap[index / 2] && index != 0)
        {
            temp = minHeap[index];
            minHeap[index] = minHeap[index / 2];
            minHeap[index / 2] = temp;
            index /= 2;
        }
    }
    return size;
}
int main()
{
    int opt, n=0, i, num;
    int minHeap[20];
    while(1) {
        printf("enter choice 1: Insert, 2: delete, 3: display 4: exit\n");
        scanf("%d",&opt);
        switch(opt) {
                
                
                
            case 1:
                printf("\n\nInsert an element -\n");
                scanf("%d", &num);
                n = addVertex(minHeap, n, num);
                printf("\nHeap After Insert -\n");
                for (i = 1; i <= n; ++i) {
                    printf("%d\n", minHeap[i]);
                }
                break;
            case 2:
                printf("\n\nEnter index where number has to be deleted-\n");
                scanf("%d", &i);
                n = deleteVertex(minHeap, n, i);
                printf("\nHeap After Delete -\n");
                for (i = 1; i <= n; ++i) {
                    printf("%d\n", minHeap[i]);
                }
            case 3:
                printf("\nHeap -\n");
                for (i = 1; i <= n; ++i) {
                    printf("%d\n", minHeap[i]);
                }
                break;
            case 4: exit(0);
        }
    }
    return 0;
}
